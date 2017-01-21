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

class RectangleShape;

class Edge : public QGraphicsObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QPen pen READ pen WRITE setPen)

public:
    Edge(const QString &name, Avoid::Router *router, RectangleShape *src, RectangleShape *dst, QGraphicsItem *parent = 0);

    virtual QPainterPath shape() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    QString name() const;
    void setName(const QString &name);

    QPen pen() const;
    void setPen(const QPen &pen);

    RectangleShape *source() const;
    void setSource(RectangleShape *shape);

    RectangleShape *destination() const;
    void setDestination(RectangleShape *shape);

    Avoid::ConnRef *connection() const;

    QPainterPath path();

private:
    QString mName;
    Avoid::Router *mRouter;
    QPen mPen;
    QPainterPath mPath;

    RectangleShape *mSrc;
    RectangleShape *mDst;
    Avoid::ConnRef *mConnRef;
};
