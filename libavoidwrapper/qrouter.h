#pragma once

#include "libavoid/libavoid.h"
#include "libavoid/connend.h"
#include "libavoid/connector.h"
#include "libavoid/router.h"
#include "libavoid/shape.h"
#include "libavoid/geomtypes.h"

#include <QObject>
#include <QRectF>
#include <QPointF>
#include <QPolygonF>
#include <QPainterPath>

class Node;
class PathLine;

struct QRouterNode {
    Avoid::ShapeRef *shapeRef{};
    Avoid::ConnEnd *connEnd{};
};

typedef Avoid::ConnRef QRouterConnect;

class QRouter : public Avoid::Router
{
public:
    QRouter();
    QRouterNode *createNode(Node *node);
    QRouterConnect *createConnect(QRouterNode *src, QRouterNode *dest);

public:
    static void handleConnectorCallback(void *context);
    static QPointF toQPointF(const Avoid::Point &point);
    static Avoid::Point toAPoint(const QPointF &point);
    static QRectF toQRectF(const Avoid::Rectangle &rect);
    static Avoid::Rectangle toARect(const QRectF &rect);
    static Avoid::Polygon toAPolygon(const QRectF &rect);
    static Avoid::Polygon toAPolygon(const QPolygonF &polygon);
    static QPolygonF toQPolygon(const Avoid::Polygon &polygon);
    static QPainterPath toQPainterPath(const Avoid::PolyLine &polyline);
    static QPainterPath makeQPainterPath(Avoid::ConnRef *connection);
    static QPolygonF makeQPolygonF(const QPointF &start, const QPointF &end);
    static QPolygonF makeQPolygonF(Avoid::ConnRef *connection);
};
