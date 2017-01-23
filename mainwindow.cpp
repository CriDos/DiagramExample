#include <QtWidgets>
#include <QPointF>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "scene.h"
#include "node.h"
#include "pathline.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setBackgroundBrush(QBrush(Qt::black));
    m_scene = new Scene(this);
    ui->graphicsView->setScene(m_scene);
    //ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    Node *mri1 = new Node(QPointF(47, 60), m_scene->router());
    m_scene->addNode(mri1);

    Node *mri2 = new Node(QPointF(100, 110), m_scene->router());
    m_scene->addNode(mri2);

    Node *mri3 = new Node(QPointF(200, 110), m_scene->router());
    m_scene->addNode(mri3);

    m_scene->addConnect(mri1, mri2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
