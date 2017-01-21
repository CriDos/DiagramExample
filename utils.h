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
Avoid::Polygon toAPolygon(const QRectF &rect);
Avoid::Polygon toAPolygon(const QPolygonF &polygon);
QPolygonF toQPolygon(const Avoid::Polygon &polygon);
QPainterPath toQPainterPath(const Avoid::PolyLine &polyline);
QPainterPath makeQPainterPath(Avoid::ConnRef *connection);
QPolygonF makeQPolygonF(const QPointF &start, const QPointF &end);
QPolygonF makeQPolygonF(Avoid::ConnRef *connection);
}
