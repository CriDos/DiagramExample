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
}
class QRouter;
class Node;

class PathLine : public QGraphicsItem
{
public:
    PathLine(QRouter *router, Node *src, Node *dst, QGraphicsItem *parent = 0);

    virtual QPainterPath shape() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

    void updatePath();

    Avoid::ConnRef *connection() const;

private:
    QRouter *m_router;
    QPainterPath m_path;

    Node *m_src;
    Node *m_dst;
    Avoid::ConnRef *m_connRef;
};
