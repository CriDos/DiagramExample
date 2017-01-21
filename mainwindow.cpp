/*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* Copyright (C) 2016  Mark E. Wilson
*
*/

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
#include "drawingscene.h"
#include "ui_mainwindow.h"
#include "rectangleshape.h"
#include "shims.h"
#include "edge.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mPathItem(0)
{
    ui->setupUi(this);

    ui->changeBrushButton->setVisible(false);
    ui->changePenButton->setVisible(false);

    ui->graphicsView->setBackgroundBrush(QBrush(Qt::black));
    mDrawingScene = new DrawingScene(0, 0, 640, 480, this);
    ui->graphicsView->setScene(mDrawingScene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    //ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

    RectangleShape *mri1 = new RectangleShape(QSize(40, 40), mDrawingScene->router());
    mDrawingScene->addShape(mri1);
    mri1->setPos(47, 60);

    RectangleShape *mri2 = new RectangleShape(QSize(40, 40), mDrawingScene->router());
    mDrawingScene->addShape(mri2);
    mri2->setPos(100, 110);

    RectangleShape *mri3 = new RectangleShape(QSize(40, 40), mDrawingScene->router());
    mDrawingScene->addShape(mri3);
    mri3->setPos(200, 110);

    Edge *edge1 = new Edge("first", mDrawingScene->router(), mri1, mri2);
    edge1->setPen(QPen(Qt::green));
    mDrawingScene->addEdge(edge1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

