#pragma once

#include <QRectF>
#include <QSize>
#include <QRectF>
#include <QPen>
#include <QBrush>
#include <QGraphicsItem>

#include <libavoid/router.h>

class Node : public QGraphicsItem
{

public:
    Node(const QSize &size, Avoid::Router *router, QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    virtual QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value);

    Avoid::ConnEnd *connectionEnd() const;

private:
    Avoid::Router *m_router{};
    Avoid::ShapeRef *m_shapeRef{};
    Avoid::ShapeConnectionPin *m_pin{};
    Avoid::ConnEnd *m_connEnd{};
    QRectF m_rect;
};
