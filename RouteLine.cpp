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

#include <QPainter>
#include <QPainterPath>
#include <QDebug>

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

    mPath = makePainterPath(mConnRef);
    painter->setPen(mPen);
    painter->drawPath(mPath);
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
