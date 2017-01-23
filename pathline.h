#pragma once

#include <QGraphicsItem>
#include <QGraphicsPathItem>
#include <QString>
#include <QPen>
#include <qrouter.h>

class PathLine : public QGraphicsItem
{
public:
    PathLine(QRouterConnect *connect, QRouter *router, QGraphicsItem *parent = 0);

    virtual QPainterPath shape() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    void updatePath();

private:
    QPainterPath m_path;
    QRouterConnect *m_connect{};
    QRouter *m_router{};
};
