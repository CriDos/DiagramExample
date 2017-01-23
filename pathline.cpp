#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QGraphicsScene>

#include "qrouter.h"
#include "pathline.h"
#include "node.h"

PathLine::PathLine(QRouterConnect *connect, QRouter *router, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    m_connect = connect;
    m_router = router;
    m_router->processTransaction();
    m_path = QRouter::makeQPainterPath(connect);

    setZValue(-1);
}

QPainterPath PathLine::shape() const
{
    return QRouter::makeQPainterPath(m_connect);
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
    //auto *s = scene();
    //if (s)
    //    s->update();
}
