#include <QDebug>
#include <QList>
#include <QListIterator>

#include "qrouter.h"
#include "scene.h"
#include "node.h"
#include "connect.h"

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{
    m_router = new QRouter();
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
    auto pathLine = new Connect(m_router, src, dest);
    addItem(pathLine);
}

QRouter *Scene::router() const
{
    return m_router;
}
