#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QGraphicsScene>

#include "qrouter.h"
#include "pathline.h"
#include "node.h"

PathLine::PathLine(Node *src, Node *dest, QRouter *router, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    m_router = router;
    m_connect = m_router->createConnect(src->routerNode(), dest->routerNode());

    m_router->processTransaction();
    m_path = QRouter::makeQPainterPath(m_connect->shapeRef);
    m_connect->shapeRef->setCallback(QRouter::handleConnectorCallback, this);

    setZValue(-1);
}

QPainterPath PathLine::shape() const
{
    return m_path;
}

QRectF PathLine::boundingRect() const
{
    return shape().boundingRect();
}

void PathLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();

    painter->setPen(Qt::green);
    painter->drawPath(m_path);

    qInfo() << m_path;

    painter->restore();
}

void PathLine::updatePath()
{
    m_path = QRouter::makeQPainterPath(m_connect->shapeRef);
    scene()->update();
}
