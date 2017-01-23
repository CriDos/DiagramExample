#include <QtWidgets>

#include "scenerouter.h"
#include "scene.h"
#include "node.h"
#include "connect.h"

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{
    m_router = new SceneRouter();
}

Scene::~Scene()
{
}

Node *Scene::addNode(QPointF pos)
{
    Node *node = new Node(m_router);
    m_nodes << node;
    addItem(node);
    node->setPos(pos);

    return node;
}

void Scene::removeNode(Node *node)
{
    m_router->removeNode(node);
    removeItem(node);
    delete node;
}

Connect *Scene::addConnect(Node *src, Node *dest)
{
    Connect *connect = m_router->makeConnect(src, dest);
    addItem(connect);
    return connect;
}

void Scene::removeConnect(Connect *connect)
{
    removeItem(connect);
    delete connect;
}

SceneRouter *Scene::router() const
{
    return m_router;
}
