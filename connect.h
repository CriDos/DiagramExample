#pragma once

#include <QGraphicsItem>
#include <QGraphicsPathItem>
#include <QString>
#include <QPen>
#include <qrouter.h>

class Connect : public QGraphicsItem
{
public:
    Connect(QRouter *router, Node *src, Node *dest, QGraphicsItem *parent = 0);

    virtual QPainterPath shape() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    void updatePath();

private:
    QPainterPath m_path;
    QRouter *m_router{};
    QRouterConnect *m_connect{};
};
