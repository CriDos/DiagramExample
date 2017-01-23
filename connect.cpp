#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QGraphicsScene>

#include "qrouter.h"
#include "connect.h"
#include "node.h"

Connect::Connect(QRouter *router, Node *src, Node *dest, QGraphicsItem *parent)
    : QGraphicsItem(parent)
    , m_router(router)
{

    m_connect = m_router->createConnect(src->routerNode(), dest->routerNode());
    m_router->reroute();
    m_path = QRouter::makeQPainterPath(m_connect->shapeRef);
    m_connect->shapeRef->setCallback(QRouter::handleConnectorCallback, this);

    setZValue(-1);
}

QPainterPath Connect::shape() const
{
    return m_path;
}

QRectF Connect::boundingRect() const
{
    return shape().boundingRect();
}

void Connect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();

    painter->setPen(Qt::green);
    painter->drawPath(m_path);

    qInfo() << m_path;

    painter->restore();
}

void Connect::updatePath()
{
    m_path = QRouter::makeQPainterPath(m_connect->shapeRef);
    scene()->update();
}
