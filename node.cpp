#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QPainter>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QRectF>
#include <QPointF>
#include <QDebug>
#include <QPen>
#include <QBrush>

#include "qrouter.h"
#include "node.h"

Node::Node(QRouter *router, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);

    m_rect = QRectF(0, 0, 40, 40);
    m_router = router;
    m_routerNode = m_router->createNode(this);

    setZValue(1);
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
        //m_router->moveShape(m_shapeRef, QRouter::toARect(QRectF(value.toPointF(), m_rect.size())));
        //m_router->processTransaction();
    }

    return QGraphicsItem::itemChange(change, value);
}

QRectF Node::rect() const
{
    return m_rect;
}

QRouterNode *Node::routerNode() const
{
    return m_routerNode;
}
