#pragma once

#include <QRectF>
#include <QPointF>
#include <QPolygonF>
#include <QPainterPath>

#include <libavoid/geomtypes.h>
#include <libavoid/connector.h>

namespace Utils
{
QPointF toQPointF(const Avoid::Point &point);
Avoid::Point toAPoint(const QPointF &point);
QRectF toQRectF(const Avoid::Rectangle &rect);
Avoid::Rectangle toARect(const QRectF &rect);
Avoid::Polygon convertPolygon(const QRectF &rect);
Avoid::Polygon convertPolygon(const QPolygonF &polygon);
QPolygonF convertPolygon(const Avoid::Polygon &polygon);
QPainterPath convertPolyLine(const Avoid::PolyLine &polyline);
QPainterPath makePainterPath(Avoid::ConnRef *connection);
QPolygonF createArrow(const QPointF &start, const QPointF &end);
QPolygonF createArrow(Avoid::ConnRef *connection);
}
