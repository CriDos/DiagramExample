#pragma once

#include <QObject>
#include <QRectF>
#include <QGraphicsScene>

class ShapeBase;
class QRouter;
class Node;
class PathLine;

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene(QObject *parent = 0);

    ~Scene();

    void addNode(Node *node);
    void addConnect(PathLine *pathLine);
    QRouter *router() const;

private:
    QRouter *m_router;

};
