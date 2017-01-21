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

#ifndef EDGE_H
#define EDGE_H


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
    Edge(const QString& name, Avoid::Router *router, RectangleShape* src, RectangleShape* dst, QGraphicsItem* parent=0);

    virtual QPainterPath shape() const;
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget=0);

    QString name() const;
    void setName(const QString& name);

    QPen pen() const;
    void setPen(const QPen& pen);

    RectangleShape* source() const;
    void setSource(RectangleShape* shape);

    RectangleShape* destination() const;
    void setDestination(RectangleShape* shape);

    Avoid::ConnRef* connection() const;

    QPainterPath path();

private:
    QString mName;
    Avoid::Router* mRouter;
    QPen mPen;
    QPainterPath mPath;

    RectangleShape* mSrc;
    RectangleShape* mDst;
    Avoid::ConnRef* mConnRef;
};

#endif // EDGE_H
