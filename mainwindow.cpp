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

    Node *mri1 = new Node(m_scene->router());
    m_scene->addNode(mri1);

    Node *mri2 = new Node(m_scene->router());
    m_scene->addNode(mri2);

    Node *mri3 = new Node(m_scene->router());
    m_scene->addNode(mri3);

    Connect *con = m_scene->addConnect(mri1, mri2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
