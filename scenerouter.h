#pragma once

#include "connect.h"
#include "node.h"

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

struct RouterConnect;
struct RouterNode;

class SceneRouter
{
private:
    Avoid::Router *m_router{};
    QMap<Node *, RouterNode *> m_nodes;
    QMap<Connect *, RouterConnect *> m_connects;

public:
    SceneRouter();
    void addNode(Node *node);
    void addConnect(Node *src, Node *dest, Connect *connect);
    Avoid::Router *router() const;
    void reroute();
    void moveShape(Node *node, QRectF rect);
    QPainterPath getPainterPath(Connect *connect);
    void setCallback(Connect *connect);

public:
    static void handleConnect(void *context);
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
};

struct RouterConnect {
    Avoid::ConnRef *shapeRef{};

    void setCallback(class Connect *connect)
    {
        shapeRef->setCallback(SceneRouter::handleConnect, connect);
    }
    QPainterPath getPainterPath()
    {
        return SceneRouter::makeQPainterPath(shapeRef);
    }
};
