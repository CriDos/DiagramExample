#pragma once

#include <QRectF>
#include <QSize>
#include <QRectF>
#include <QPen>
#include <QBrush>
#include <QGraphicsItem>

class Node : public QGraphicsItem
{

public:
    Node(const QSize &size, QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    virtual QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value);


private:
    QRectF m_rect;
};
