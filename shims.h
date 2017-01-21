#pragma once

#include <QRectF>
#include <QPointF>
#include <QPolygonF>
#include <QPainterPath>

#include <libavoid/geomtypes.h>
#include <libavoid/connector.h>

QPointF convertPoint(const Avoid::Point& point);

Avoid::Point convertPoint(const QPointF& point);


QRectF convertRectangle(const Avoid::Rectangle& rect);

Avoid::Rectangle convertRectangle(const QRectF& rect);




Avoid::Polygon convertPolygon(const QRectF& rect);

Avoid::Polygon convertPolygon(const QPolygonF& polygon);

QPolygonF convertPolygon(const Avoid::Polygon& polygon);



QPainterPath convertPolyLine(const Avoid::PolyLine& polyline);

QPainterPath makePainterPath(Avoid::ConnRef* connection);

QPolygonF createArrow(const QPointF& start, const QPointF& end);

QPolygonF createArrow(Avoid::ConnRef* connection);
