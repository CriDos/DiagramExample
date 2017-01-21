#pragma once

#include <QObject>
#include <QRectF>
#include <QGraphicsScene>

class ShapeBase;

namespace Avoid
{
    class Router;
}

class RectangleShape;
class Edge;

class DrawingScene : public QGraphicsScene
{
    Q_OBJECT

public:
    DrawingScene(QObject *parent=0);
    DrawingScene(const QRectF& sceneRect, QObject *parent=0);
    DrawingScene(qreal x, qreal y, qreal width, qreal height, QObject *parent=0);

    ~DrawingScene();

    static DrawingScene* mStaticDrawingScene;

    void addShape(RectangleShape *shape);
    void addEdge(Edge* edge);

    Avoid::Router* router() const;

private slots:


private:
    Avoid::Router* mRouter;

    void makeRouter_p();
    static void handleConnectorCallback_p(void* context);
};
