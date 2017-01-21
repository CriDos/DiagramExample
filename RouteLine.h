#pragma once

#include <QGraphicsObject>
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

class RouteLine : public QGraphicsObject
{
    Q_OBJECT

public:
    RouteLine(Avoid::Router *router, Node *src, Node *dst, QGraphicsItem *parent = 0);

    virtual QPainterPath shape() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void updateRect();

    QPen pen() const;
    void setPen(const QPen &pen);

    Node *source() const;
    void setSource(Node *shape);

    Node *destination() const;
    void setDestination(Node *shape);

    Avoid::ConnRef *connection() const;

    QPainterPath path();

private:
    Avoid::Router *mRouter;
    QPen mPen;
    QPainterPath mPath;

    Node *mSrc;
    Node *mDst;
    Avoid::ConnRef *mConnRef;
};
