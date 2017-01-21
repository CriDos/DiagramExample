/*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* Copyright (C) 2016  Mark E. Wilson
*
*/

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QPainter>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QRectF>
#include <QPointF>
#include <QDebug>
#include <QPen>
#include <QBrush>

#include <libavoid/router.h>
#include <libavoid/shape.h>

#include "shims.h"

#include "node.h"

Node::Node(const QSize &size, Avoid::Router *router, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , mRouter(router)
    , mShapeRef(0)
    , mRect(QRectF(0, 0, size.width(), size.height()))
    , mBorder(0.0)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);

    Avoid::Rectangle rect = convertRectangle(mRect);
    mShapeRef = new Avoid::ShapeRef(mRouter, rect);

    mPin = new Avoid::ShapeConnectionPin(mShapeRef, 1,
                                         Avoid::ATTACH_POS_CENTRE,
                                         Avoid::ATTACH_POS_CENTRE, true,
                                         0.0, Avoid::ConnDirAll);

    mConnEnd = new Avoid::ConnEnd(mShapeRef, 1);

    setZValue(1);
}

QRectF Node::boundingRect() const
{
    return QRectF(mRect);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();
    painter->setPen(QColor("white"));
    painter->drawRect(mRect);
    painter->restore();
}

QVariant Node::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange) {
        QPointF newPos = value.toPointF();

        qreal sw = mRect.width();
        qreal sh = mRect.height();
        qreal sx = newPos.x() + (sw / 2);
        qreal sy = newPos.y() + (sh / 2);

        Avoid::Rectangle poly(Avoid::Point(sx, sy),
                              sw, sh);

        mRouter->moveShape(mShapeRef, poly);

        mRouter->processTransaction();
    }

    return QGraphicsObject::itemChange(change, value);
}

int Node::type() const
{
    return Type;
}

void Node::setRouter(Avoid::Router *router)
{
    mRouter = router;
}

const Avoid::Router *Node::router() const
{
    return mRouter;
}

const Avoid::ShapeRef *Node::shapeRef() const
{
    return mShapeRef;
}

const Avoid::ShapeConnectionPin *Node::pin() const
{
    return mPin;
}

Avoid::ConnEnd *Node::connectionEnd() const
{
    return mConnEnd;
}
