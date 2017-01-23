#include <QtWidgets>
#include <QPointF>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "scene.h"
#include "node.h"
#include "connect.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setBackgroundBrush(QBrush(Qt::black));
    m_scene = new Scene(this);
    ui->graphicsView->setScene(m_scene);

    for (int i = 0; i < 100; ++i) {
        auto x = rand() % 4000 + 1;
        auto y = rand() % 4000 + 1;
        Node *mri1 = m_scene->addNode(QPointF(x, y));
        auto x2 = rand() % 4000 + 1;
        auto y2 = rand() % 4000 + 1;

        Node *mri2 = m_scene->addNode(QPointF(x2, y2));
        Connect *con = m_scene->addConnect(mri1, mri2);
    }
    //Node *mri1 = m_scene->addNode(QPointF(10, 10));
    //Node *mri2 = m_scene->addNode(QPointF(3600, 3600));
    //Connect *con = m_scene->addConnect(mri1, mri2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
