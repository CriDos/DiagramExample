#pragma once

#include "connect.h"
#include "node.h"

#include "libavoid/geometry.h"

#include <QObject>
#include <QRectF>
#include <QPointF>
#include <QPolygonF>
#include <QPainterPath>

namespace Avoid
{
class Router;
class ShapeRef;
class ConnRef;
}

class SceneRouter
{
private:
    Avoid::Router *m_router{};
    QHash<Node *, class Avoid::ShapeRef *> m_nodes;
    QHash<Connect *, class Avoid::ConnRef *> m_connects;

public:
    SceneRouter();
    void addNode(Node *node);
    void removeNode(Node *node);
    void addConnect(Node *src, Node *dest, Connect *connect);
    void removeConnect(Connect *connect);
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
