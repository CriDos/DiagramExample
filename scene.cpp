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
}

void Scene::addNode(Node *node)
{
    addItem(node);
}

void Scene::addConnect(Node *src, Node *dest)
{
    QRouterConnect *connect = m_router->createConnect(src->routerNode(), dest->routerNode());
    router()->processTransaction();

    auto pathLine = new PathLine(connect);
    addItem(pathLine);
}

QRouter *Scene::router() const
{
    return m_router;
}
