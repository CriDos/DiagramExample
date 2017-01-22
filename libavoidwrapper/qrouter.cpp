#include "qrouter.h"
#include "pathline.h"

QRouter::QRouter()
    : Router(Avoid::OrthogonalRouting)
{
    setRoutingParameter(Avoid::shapeBufferDistance, 5.0);
    setRoutingParameter(Avoid::idealNudgingDistance, 5.0);
    setRoutingOption(Avoid::nudgeOrthogonalSegmentsConnectedToShapes, true);
}

QRouterConnect *QRouter::createConnect(QRouterNode *src, QRouterNode *dest)
{
    QRouterConnect *node = new QRouterConnect();

    Avoid::ConnEnd dstEnd(src->shapeRef, 1);
    Avoid::ConnEnd srcEnd(dest->shapeRef, 1);
    node->connRef = new Avoid::ConnRef(this, srcEnd, dstEnd);
    node->connRef->setCallback(handleConnectorCallback, node);

    return node;
}

void QRouter::handleConnectorCallback(void *context)
{
    PathLine *edge = static_cast<PathLine *>(context);
    edge->updatePath();
}

QPointF QRouter::toQPointF(const Avoid::Point &point)
{
    return QPointF(point.x, point.y);
}

Avoid::Point QRouter::toAPoint(const QPointF &point)
{
    return Avoid::Point(point.x(), point.y());
}

QRectF QRouter::toQRectF(const Avoid::Rectangle &rect)
{
    QRectF newRect;

    newRect.setTopRight(QPointF(rect.at(0).x, rect.at(0).y));
    newRect.setBottomRight(QPointF(rect.at(1).x, rect.at(1).y));
    newRect.setBottomLeft(QPointF(rect.at(2).x, rect.at(2).y));
    newRect.setTopLeft(QPointF(rect.at(3).x, rect.at(3).y));

    return newRect;
}

Avoid::Rectangle QRouter::toARect(const QRectF &rect)
{
    return Avoid::Rectangle(toAPoint(rect.topLeft()), toAPoint(rect.bottomRight()));
}

Avoid::Polygon QRouter::toAPolygon(const QRectF &rect)
{
    Avoid::Polygon newPolygon;

    newPolygon.setPoint(0, toAPoint(rect.topRight()));
    newPolygon.setPoint(1, toAPoint(rect.bottomRight()));
    newPolygon.setPoint(2, toAPoint(rect.bottomLeft()));
    newPolygon.setPoint(3, toAPoint(rect.topLeft()));

    return newPolygon;
}

Avoid::Polygon QRouter::toAPolygon(const QPolygonF &polygon)
{
    Avoid::Polygon newPolygon;
    newPolygon.ps.clear();

    for (int idx = 0; idx < polygon.size(); ++idx)
        newPolygon.ps.push_back(
            Avoid::Point(polygon[idx].x(), polygon[idx].y()));

    return newPolygon;
}

QPolygonF QRouter::toQPolygon(const Avoid::Polygon &polygon)
{
    QPolygonF newPolygon;

    for (unsigned int idx = 0; idx < polygon.ps.size(); ++idx) {
        newPolygon.push_back(toQPointF(polygon.at(idx)));
    }

    return newPolygon;
}

QPainterPath QRouter::toQPainterPath(const Avoid::PolyLine &polyline)
{
    Avoid::Point p = polyline.at(0);
    QPainterPath path(QPointF(p.x, p.y));

    for (size_t i = 0; i < polyline.size(); ++i) {
        Avoid::Point point = polyline.at(i);
        path.lineTo(QPointF(point.x, point.y));
    }

    return path;
}

QPainterPath QRouter::makeQPainterPath(Avoid::ConnRef *connection)
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

QPolygonF QRouter::makeQPolygonF(const QPointF &start, const QPointF &end)
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

QPolygonF QRouter::makeQPolygonF(Avoid::ConnRef *connection)
{
    Avoid::PolyLine route = connection->displayRoute();
    const auto size = route.size();
    Avoid::Point start = route.at(size - 2);
    Avoid::Point end = route.at(size - 1);
    return makeQPolygonF(toQPointF(start), toQPointF(end));
}
