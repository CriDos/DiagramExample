#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QGraphicsScene>

#include <libavoid/connector.h>
#include <libavoid/router.h>

#include "RouteLine.h"
#include "node.h"
#include "shims.h"

RouteLine::RouteLine(Avoid::Router *router, Node *src, Node *dst, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , mRouter(router)
    , mSrc(src)
    , mDst(dst)
    , mConnRef(0)
{
    mConnRef = new Avoid::ConnRef(mRouter, *(mSrc->connectionEnd()), *(mDst->connectionEnd()));
    mRouter->processTransaction();
    mPath = makePainterPath(mConnRef);
    setZValue(-1);
}

QPainterPath RouteLine::shape() const
{
    return makePainterPath(mConnRef);
}

QRectF RouteLine::boundingRect() const
{
    return mPath.boundingRect();
}

void RouteLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();
    mPath = makePainterPath(mConnRef);
    painter->setPen(mPen);
    painter->drawPath(mPath);
    painter->restore();
}

void RouteLine::updateRect()
{
    scene()->update();
}

QPen RouteLine::pen() const
{
    return mPen;
}

void RouteLine::setPen(const QPen &pen)
{
    mPen = pen;
    update();
}

Node *RouteLine::source() const
{
    return mSrc;
}

void RouteLine::setSource(Node *shape)
{
    mSrc = shape;
}

Node *RouteLine::destination() const
{
    return mDst;
}

void RouteLine::setDestination(Node *shape)
{
    mDst = shape;
}

Avoid::ConnRef *RouteLine::connection() const
{
    return mConnRef;
}

QPainterPath RouteLine::path()
{
    mPath = makePainterPath(mConnRef);
    return mPath;
}
