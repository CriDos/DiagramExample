#pragma once

#include <QMainWindow>
#include <QBrush>
#include <QPen>
#include <QGraphicsPathItem>

class Scene;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Scene *m_scene;
};
