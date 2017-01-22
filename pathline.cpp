#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QGraphicsScene>

#include "qrouter.h"
#include "pathline.h"
#include "node.h"

PathLine::PathLine(QRouter *router, Node *src, Node *dst, QGraphicsItem *parent)
    : QGraphicsItem(parent)
    , m_router(router)
    , m_src(src)
    , m_dst(dst)
    , m_connRef(0)
{
    m_connRef = new Avoid::ConnRef(m_router, *(m_src->connectionEnd()), *(m_dst->connectionEnd()));
    m_router->processTransaction();
    m_path = QRouter::makeQPainterPath(m_connRef);
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
    m_path = QRouter::makeQPainterPath(m_connRef);
    scene()->update();
}

Avoid::ConnRef *PathLine::connection() const
{
    return m_connRef;
}
