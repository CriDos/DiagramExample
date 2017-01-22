#include <QDebug>
#include <QList>
#include <QListIterator>

#include "libavoid/qrouter.h"

#include "scene.h"
#include "node.h"
#include "pathline.h"

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{
    m_router = new Avoid::QRouter();
}

Scene::~Scene()
{
    delete m_router;
}

void Scene::handleConnectorCallback(void *context)
{
    PathLine *edge = static_cast<PathLine *>(context);
    edge->updatePath();
}

void Scene::addNode(Node *node)
{
    addItem(node);
}

void Scene::addConnect(PathLine *pathLine)
{
    pathLine->connection()->setCallback(&handleConnectorCallback, reinterpret_cast<void *>(pathLine));
    addItem(pathLine);
}

Avoid::QRouter *Scene::router() const
{
    return m_router;
}
