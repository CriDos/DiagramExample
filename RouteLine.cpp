#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QGraphicsScene>

#include <libavoid/connector.h>
#include <libavoid/router.h>

#include "RouteLine.h"
#include "node.h"
#include "utils.h"

RouteLine::RouteLine(Avoid::Router *router, Node *src, Node *dst, QGraphicsItem *parent)
    : QGraphicsItem(parent)
    , m_router(router)
    , m_src(src)
    , m_dst(dst)
    , m_connRef(0)
{
    m_connRef = new Avoid::ConnRef(m_router, *(m_src->connectionEnd()), *(m_dst->connectionEnd()));
    m_router->processTransaction();
    m_path = Utils::makePainterPath(m_connRef);
    setZValue(-1);
}

QPainterPath RouteLine::shape() const
{
    return Utils::makePainterPath(m_connRef);
}

QRectF RouteLine::boundingRect() const
{
    return m_path.boundingRect();
}

void RouteLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();

    painter->setPen(Qt::green);
    painter->drawPath(m_path);

    painter->restore();
}

void RouteLine::updatePath()
{
    m_path = Utils::makePainterPath(m_connRef);
    scene()->update();
}

Node *RouteLine::source() const
{
    return m_src;
}

void RouteLine::setSource(Node *shape)
{
    m_src = shape;
}

Node *RouteLine::destination() const
{
    return m_dst;
}

void RouteLine::setDestination(Node *shape)
{
    m_dst = shape;
}

Avoid::ConnRef *RouteLine::connection() const
{
    return m_connRef;
}
