#include "node.h"
#include "scenerouter.h"

#include <QtWidgets>

Node::Node(SceneRouter *router, QGraphicsItem *parent)
    : QGraphicsItem(parent)
    , m_router(router)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    m_rect = QRectF(0, 0, 40, 40);
    setZValue(1);

    m_router->addNode(this);
}

QRectF Node::boundingRect() const
{
    return m_rect;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();
    painter->setPen(QColor("white"));
    painter->drawRect(m_rect);
    painter->restore();
}

QVariant Node::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange) {
        m_router->moveShape(this, QRectF(value.toPointF(), m_rect.size()));
        //m_router->reroute();
    }

    return QGraphicsItem::itemChange(change, value);
}

QRectF Node::rect() const
{
    return m_rect;
}
