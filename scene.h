#pragma once

#include <QObject>
#include <QRectF>
#include <QGraphicsScene>

class SceneRouter;
class Node;
class Connect;

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene(QObject *parent = 0);
    ~Scene();

    Node *addNode(QPointF pos);
    void removeNode(Node *node);
    Connect *addConnect(Node *src, Node *dest);
    void removeConnect(Connect *connect);
    SceneRouter *router() const;

private:
    SceneRouter *m_router{};
};
