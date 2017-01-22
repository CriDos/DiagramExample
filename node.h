#pragma once

#include <QRectF>
#include <QSize>
#include <QRectF>
#include <QPen>
#include <QBrush>
#include <QGraphicsItem>

namespace Avoid
{
class QRouter;
}

class Node : public QGraphicsItem
{

public:
    Node(const QSize &size, Avoid::QRouter *router, QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    virtual QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value);

    Avoid::ConnEnd *connectionEnd() const;

private:
    Avoid::QRouter *m_router{};
    Avoid::ShapeRef *m_shapeRef{};
    Avoid::ShapeConnectionPin *m_pin{};
    Avoid::ConnEnd *m_connEnd{};
    QRectF m_rect;
};
