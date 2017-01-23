#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QGraphicsScene>

#include "scenerouter.h"

Connect::Connect(QPainterPath path, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    m_path = path;
    setZValue(1000000);
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
