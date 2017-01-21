#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QColor>
#include <QBrush>
#include <QColorDialog>
#include <QDebug>
#include <QPainterPath>
#include <QGraphicsPathItem>
#include <QTransform>

#include "mainwindow.h"
#include "scene.h"
#include "ui_mainwindow.h"
#include "node.h"
#include "utils.h"
#include "RouteLine.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setBackgroundBrush(QBrush(Qt::black));
    m_scene = new Scene(this);
    ui->graphicsView->setScene(m_scene);
    //ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    Node *mri1 = new Node(QSize(40, 40), m_scene->router());
    m_scene->addShape(mri1);
    mri1->setPos(47, 60);

    Node *mri2 = new Node(QSize(40, 40), m_scene->router());
    m_scene->addShape(mri2);
    mri2->setPos(100, 110);

    Node *mri3 = new Node(QSize(40, 40), m_scene->router());
    m_scene->addShape(mri3);
    mri3->setPos(200, 110);

    RouteLine *edge1 = new RouteLine(m_scene->router(), mri1, mri2);
    m_scene->addEdge(edge1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
