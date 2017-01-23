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

void Scene::addNode(Node *node)
{
    addItem(node);
}

Connect *Scene::addConnect(Node *src, Node *dest)
{
    Connect *connect = new Connect(m_router, src, dest);
    addItem(connect);

    return connect;
}

void Scene::removeConnect(Connect *connect)
{
    m_router->removeConnect(connect);
    removeItem(connect);
    delete connect;
}

SceneRouter *Scene::router() const
{
    return m_router;
}
