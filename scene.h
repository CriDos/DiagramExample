#pragma once

#include <QObject>
#include <QRectF>
#include <QGraphicsScene>

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene(QObject *parent = 0);
    ~Scene();

    void addNode(class Node *node);

private:


};
