#include <QDebug>
#include <QList>
#include <QListIterator>

#include "qrouter.h"

#include "scene.h"
#include "node.h"
#include "pathline.h"

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{
    m_router = new QRouter();
}

Scene::~Scene()
{
    delete m_router;
}

void Scene::addNode(Node *node)
{
    addItem(node);
}

void Scene::addConnect(PathLine *pathLine)
{
    pathLine->connection()->setCallback(&QRouter::handleConnectorCallback, reinterpret_cast<void *>(pathLine));
    addItem(pathLine);
}

QRouter *Scene::router() const
{
    return m_router;
}
