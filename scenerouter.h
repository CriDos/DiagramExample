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
class Connect;

class SceneRouter
{
private:
    Avoid::Router *m_router{};

public:
    SceneRouter();
    struct RouterNode *createNode(Node *node);
    struct RouterConnect *createConnect(RouterNode *src, RouterNode *dest);
    Avoid::Router *router() const;
    void reroute();
    void moveShape(RouterNode *node, QRectF rect);

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

struct RouterNode {
    Avoid::ShapeRef *shapeRef{};
    Avoid::ConnEnd *connEnd{};
};

struct RouterConnect {
    Avoid::ConnRef *shapeRef{};

    void setCallback(Connect *connect)
    {
        shapeRef->setCallback(SceneRouter::handleConnectorCallback, connect);
    }
    QPainterPath getPainterPath()
    {
        return SceneRouter::makeQPainterPath(shapeRef);
    }
};
