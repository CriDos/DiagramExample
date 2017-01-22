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
}

Scene::~Scene()
{
}

void Scene::addNode(Node *node)
{
    addItem(node);
}
