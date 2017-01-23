#pragma once

#include <QRectF>
#include <QSize>
#include <QRectF>
#include <QPen>
#include <QBrush>
#include <QGraphicsItem>

#include "qrouter.h"

class Node : public QGraphicsItem
{

public:
    Node(QPointF pos, QRouter *router, QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    virtual QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value);
    QRectF rect() const;
    QRouterNode *routerNode() const;

private:
    QRectF m_rect;
    QRouter *m_router{};
    QRouterNode *m_routerNode{};
    QRouterConnect *m_routerConnect{};
};
