#pragma once

#include <memory>

#include <QRectF>
#include <QSize>
#include <QRectF>
#include <QPen>
#include <QBrush>
#include <QGraphicsObject>

#include <libavoid/router.h>

class QGraphicsItem;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;

namespace Avoid
{
    class Router;
    class ShapeRef;
    class ShapeConnectionPin;
    class ConnEnd;
}

class Node : public QGraphicsObject
{
    Q_OBJECT

public:
    enum
    {
        Type = UserType + 1
    };

    Node(const QSize& size, Avoid::Router *router, QGraphicsItem* parent=0);

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget=0);

    virtual QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant& value);

    int type() const;

    void setRouter(Avoid::Router *router);
    const Avoid::Router* router() const;

    const Avoid::ShapeRef* shapeRef() const;

    const Avoid::ShapeConnectionPin* pin() const;

    Avoid::ConnEnd *connectionEnd() const;


signals:
    void onNodeMoved();

private:
    Avoid::Router* mRouter;
    Avoid::ShapeRef* mShapeRef;
    Avoid::ShapeConnectionPin* mPin;
    Avoid::ConnEnd* mConnEnd;
    QRectF mRect;
    qreal mBorder;


};

