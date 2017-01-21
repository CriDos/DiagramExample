#pragma once

#include <QGraphicsItem>
#include <QGraphicsPathItem>
#include <QString>
#include <QPen>

namespace Avoid
{
class ConnEnd;
class ConnRef;
class ShapeRef;
class Router;
}

class Node;

class PathLine : public QGraphicsItem
{
public:
    PathLine(Avoid::Router *router, Node *src, Node *dst, QGraphicsItem *parent = 0);

    virtual QPainterPath shape() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

    void updatePath();

    Node *source() const;
    void setSource(Node *shape);

    Node *destination() const;
    void setDestination(Node *shape);

    Avoid::ConnRef *connection() const;

private:
    Avoid::Router *m_router;
    QPainterPath m_path;

    Node *m_src;
    Node *m_dst;
    Avoid::ConnRef *m_connRef;
};
