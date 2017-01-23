#pragma once

#include <QObject>
#include <QRectF>
#include <QGraphicsScene>

class SceneRouter;
class Node;

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene(QObject *parent = 0);
    ~Scene();

    void addNode(Node *node);
    void addConnect(Node *src, Node *dest);

    SceneRouter *router() const;

private:
    SceneRouter *m_router{};
};
