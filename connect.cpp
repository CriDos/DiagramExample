#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QGraphicsScene>

#include "scenerouter.h"

Connect::Connect(SceneRouter *router, Node *src, Node *dest, QGraphicsItem *parent)
    : QGraphicsItem(parent)
    , m_router(router)
{
    m_router->addConnect(src, dest, this);
    m_router->reroute();
    m_path = m_router->getPainterPath(this);
    m_router->setCallback(this);

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
    m_path = m_router->getPainterPath(this);
    scene()->update();
}
