#include "scenerouter.h"
#include "connect.h"

#include "libavoid/libavoid.h"

#include <node.h>

SceneRouter::SceneRouter()
{
    m_router = new Avoid::Router(Avoid::OrthogonalRouting);
    m_router->setRoutingParameter(Avoid::shapeBufferDistance, 5.0);
    m_router->setRoutingParameter(Avoid::idealNudgingDistance, 5.0);
    m_router->setRoutingOption(Avoid::nudgeOrthogonalSegmentsConnectedToShapes, true);
}

void SceneRouter::addNode(Node *node)
{
    Avoid::Rectangle rect = toARect(node->rect());
    Avoid::ShapeRef *shapeRef = new Avoid::ShapeRef(m_router, rect);

    new Avoid::ShapeConnectionPin(shapeRef, 1, Avoid::ATTACH_POS_CENTRE, Avoid::ATTACH_POS_CENTRE, true, 0.0, Avoid::ConnDirNone);
    m_nodes[node] = shapeRef;
}

void SceneRouter::removeNode(Node *node)
{
    Avoid::ShapeRef *shape = m_nodes[node];
    m_router->deleteShape(shape);
}

void SceneRouter::addConnect(Node *src, Node *dest, Connect *connect)
{
    Avoid::ConnEnd srcEnd(m_nodes[src], 1);
    Avoid::ConnEnd dstEnd(m_nodes[dest], 1);
    m_connects[connect] = new Avoid::ConnRef(m_router, srcEnd, dstEnd);
}

void SceneRouter::removeConnect(Connect *connect)
{
    Avoid::ConnRef *ref = m_connects[connect];
    m_router->deleteConnector(ref);
    m_connects.remove(connect);
}

void SceneRouter::reroute()
{
    m_router->processTransaction();
}

void SceneRouter::moveShape(Node *node, QRectF rect)
{
    m_router->moveShape(m_nodes[node], SceneRouter::toARect(rect));
}

QPainterPath SceneRouter::getPainterPath(Connect *connect)
{
    return makeQPainterPath(m_connects[connect]);
}

void SceneRouter::setCallback(Connect *connect)
{
    m_connects[connect]->setCallback(handleConnect, connect);
}

void SceneRouter::handleConnect(void *context)
{
    Connect *connect = static_cast<Connect *>(context);
    connect->updatePath();
}

QPointF SceneRouter::toQPointF(const Avoid::Point &point)
{
    return QPointF(point.x, point.y);
}

Avoid::Point SceneRouter::toAPoint(const QPointF &point)
{
    return Avoid::Point(point.x(), point.y());
}

QRectF SceneRouter::toQRectF(const Avoid::Rectangle &rect)
{
    QRectF newRect;

    newRect.setTopRight(QPointF(rect.at(0).x, rect.at(0).y));
    newRect.setBottomRight(QPointF(rect.at(1).x, rect.at(1).y));
    newRect.setBottomLeft(QPointF(rect.at(2).x, rect.at(2).y));
    newRect.setTopLeft(QPointF(rect.at(3).x, rect.at(3).y));

    return newRect;
}

Avoid::Rectangle SceneRouter::toARect(const QRectF &rect)
{
    return Avoid::Rectangle(toAPoint(rect.topLeft()), toAPoint(rect.bottomRight()));
}

Avoid::Polygon SceneRouter::toAPolygon(const QRectF &rect)
{
    Avoid::Polygon newPolygon;

    newPolygon.setPoint(0, toAPoint(rect.topRight()));
    newPolygon.setPoint(1, toAPoint(rect.bottomRight()));
    newPolygon.setPoint(2, toAPoint(rect.bottomLeft()));
    newPolygon.setPoint(3, toAPoint(rect.topLeft()));

    return newPolygon;
}

Avoid::Polygon SceneRouter::toAPolygon(const QPolygonF &polygon)
{
    Avoid::Polygon newPolygon;
    newPolygon.ps.clear();

    for (int idx = 0; idx < polygon.size(); ++idx)
        newPolygon.ps.push_back(
            Avoid::Point(polygon[idx].x(), polygon[idx].y()));

    return newPolygon;
}

QPolygonF SceneRouter::toQPolygon(const Avoid::Polygon &polygon)
{
    QPolygonF newPolygon;

    for (unsigned int idx = 0; idx < polygon.ps.size(); ++idx) {
        newPolygon.push_back(toQPointF(polygon.at(idx)));
    }

    return newPolygon;
}

QPainterPath SceneRouter::toQPainterPath(const Avoid::PolyLine &polyline)
{
    Avoid::Point p = polyline.at(0);
    QPainterPath path(QPointF(p.x, p.y));

    for (size_t i = 0; i < polyline.size(); ++i) {
        Avoid::Point point = polyline.at(i);
        path.lineTo(QPointF(point.x, point.y));
    }

    return path;
}

QPainterPath SceneRouter::makeQPainterPath(Avoid::ConnRef *connection)
{
    const auto &displayRoute = connection->displayRoute();
    const auto &ps = displayRoute.ps;
    const auto &p = ps[0];
    QPainterPath path(QPointF(p.x, p.y));
    for (auto &point : ps) {
        path.lineTo(point.x, point.y);
    }

    return path;
}

QPolygonF SceneRouter::makeQPolygonF(const QPointF &start, const QPointF &end)
{
    qreal Pi = 3.14;
    qreal arrowSize = 10;

    QPolygonF arrowHead;

    QLineF line(end, start);

    double angle = ::acos(line.dx() / line.length());

    if (line.dy() >= 0)
        angle = (Pi * 2) - angle;

    QPointF arrowP1 = line.p1() + QPointF(sin(angle + Pi / 3) * arrowSize,
                                          cos(angle + Pi / 3) * arrowSize);
    QPointF arrowP2 = line.p1() + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                          cos(angle + Pi - Pi / 3) * arrowSize);

    arrowHead.clear();
    arrowHead << line.p1() << arrowP1 << arrowP2;

    return arrowHead;
}

QPolygonF SceneRouter::makeQPolygonF(Avoid::ConnRef *connection)
{
    Avoid::PolyLine route = connection->displayRoute();
    const auto size = route.size();
    Avoid::Point start = route.at(size - 2);
    Avoid::Point end = route.at(size - 1);
    return makeQPolygonF(toQPointF(start), toQPointF(end));
}
