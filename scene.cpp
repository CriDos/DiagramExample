#include <QDebug>
#include <QList>
#include <QListIterator>

#include <libavoid/router.h>
#include <libavoid/shape.h>
#include <libavoid/connend.h>
#include <libavoid/connector.h>

#include "scene.h"
#include "node.h"
#include "pathline.h"

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{
    //m_router = new Avoid::Router(Avoid::PolyLineRouting);
    m_router = new Avoid::Router(Avoid::OrthogonalRouting);
    m_router->setRoutingParameter(Avoid::shapeBufferDistance, 5.0);
    m_router->setRoutingParameter(Avoid::idealNudgingDistance, 5.0);
    m_router->setRoutingOption(Avoid::nudgeOrthogonalSegmentsConnectedToShapes, true);
    //mRouter->setRoutingOption(Avoid::nudgeOrthogonalTouchingColinearSegments, true);
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

Avoid::Router *Scene::router() const
{
    return m_router;
}
