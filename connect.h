#pragma once

#include <QGraphicsItem>
#include <QGraphicsPathItem>
#include <QString>
#include <QPen>
#include <scenerouter.h>

class Connect : public QGraphicsItem
{
public:
    Connect(SceneRouter *router, Node *src, Node *dest, QGraphicsItem *parent = 0);

    virtual QPainterPath shape() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    void updatePath();

private:
    QPainterPath m_path;
    SceneRouter *m_router{};
    RouterConnect *m_connect{};
};
