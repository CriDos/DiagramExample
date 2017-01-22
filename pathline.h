#pragma once

#include <QGraphicsItem>
#include <QGraphicsPathItem>
#include <QString>
#include <QPen>

class PathLine : public QGraphicsItem
{
public:
    PathLine(QGraphicsItem *parent = 0);

    virtual QPainterPath shape() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    void updatePath();

private:
    QPainterPath m_path;
};
