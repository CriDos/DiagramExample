#pragma once

#include <QMainWindow>
#include <QBrush>
#include <QPen>
#include <QGraphicsPathItem>

class DrawingScene;

namespace Avoid
{
    class ConnRef;
}

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;

    DrawingScene* mDrawingScene;

    Avoid::ConnRef* mConnRef;

    QGraphicsPathItem* mPathItem;
};
