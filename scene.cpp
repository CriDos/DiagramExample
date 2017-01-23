#include <QDebug>
#include <QList>
#include <QListIterator>

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

void Scene::addConnect(Node *src, Node *dest)
{
    addItem(new Connect(m_router, src, dest));
}

SceneRouter *Scene::router() const
{
    return m_router;
}
