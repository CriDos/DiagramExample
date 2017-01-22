#pragma once

#include <QObject>
#include <QRectF>
#include <QGraphicsScene>

class ShapeBase;

namespace Avoid
{
class QRouter;
}

class Node;
class PathLine;

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene(QObject *parent = 0);

    ~Scene();

    void addNode(Node *node);
    void addConnect(PathLine *pathLine);
    Avoid::QRouter *router() const;

private:
    Avoid::QRouter *m_router;
    static void handleConnectorCallback(void *context);
};
