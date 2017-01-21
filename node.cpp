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

#include "utils.h"

#include "node.h"

Node::Node(const QSize &size, Avoid::Router *router, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);

    m_router = router;
    m_rect = QRectF(0, 0, size.width(), size.height());
    Avoid::Rectangle rect = Utils::toARect(m_rect);
    m_shapeRef = new Avoid::ShapeRef(m_router, rect);

    m_pin = new Avoid::ShapeConnectionPin(m_shapeRef, 1,
                                          Avoid::ATTACH_POS_CENTRE,
                                          Avoid::ATTACH_POS_CENTRE, true,
                                          0.0, Avoid::ConnDirAll);

    m_connEnd = new Avoid::ConnEnd(m_shapeRef, 1);

    setZValue(1);
}

QRectF Node::boundingRect() const
{
    return m_rect;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();
    painter->setPen(QColor("white"));
    painter->drawRect(m_rect);
    painter->restore();
}

QVariant Node::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange) {
        m_router->moveShape(m_shapeRef, Utils::toARect(QRectF(value.toPointF(), m_rect.size())));
        m_router->processTransaction();
    }

    return QGraphicsItem::itemChange(change, value);
}

Avoid::ConnEnd *Node::connectionEnd() const
{
    return m_connEnd;
}
