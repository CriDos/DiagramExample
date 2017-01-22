#pragma once

#include <QObject>
#include <QRectF>
#include <QGraphicsScene>

class QRouter;
class Node;

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene(QObject *parent = 0);
    ~Scene();

    void addNode(Node *node);
    void addConnect(Node *src, Node *dest);

    QRouter *router() const;

private:
    QRouter *m_router{};
};
