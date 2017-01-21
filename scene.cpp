/*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* Copyright (C) 2016  Mark E. Wilson
*
*/

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
    m_router = new Avoid::Router(Avoid::PolyLineRouting);
    //mRouter = new Avoid::Router(Avoid::PolyLineRouting);
    m_router->setRoutingParameter(Avoid::shapeBufferDistance, 10.0);
    m_router->setRoutingParameter(Avoid::idealNudgingDistance, 20.0);
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

void Scene::addConnect(PathLine *edge)
{
    edge->connection()->setCallback(&handleConnectorCallback, reinterpret_cast<void *>(edge));
    addItem(edge);
}

Avoid::Router *Scene::router() const
{
    return m_router;
}
