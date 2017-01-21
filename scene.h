#pragma once

#include <QObject>
#include <QRectF>
#include <QGraphicsScene>

class ShapeBase;

namespace Avoid
{
class Router;
}

class Node;
class RouteLine;

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene(QObject *parent = 0);

    ~Scene();

    void addShape(Node *shape);
    void addEdge(RouteLine *edge);
    Avoid::Router *router() const;

private slots:

private:
    Avoid::Router *mRouter;
    static void handleConnectorCallback(void *context);
};
