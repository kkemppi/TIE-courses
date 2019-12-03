#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
//    ui_->setFixedSize(700, 540);
    scene_ = new QGraphicsScene(this);


    int left_margin = 10; // x coordinate
    int top_margin = 270; // y coordinate


    ui_->graphicsView->setGeometry(left_margin, top_margin,
                                   BORDER_RIGHT + 2, BORDER_DOWN + 2);
    ui_->graphicsView->setScene(scene_);
    scene_->setSceneRect(0, 0, BORDER_RIGHT - 1, BORDER_DOWN - 1);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QPen blackPen(Qt::black);

    if (user_defined_n){
        // Implementation for custom n
    }
    a.setX(BORDER_RIGHT / 4);
    int i = 0;
    while(i<=n){
//        int width = MAX_WIDTH-(i*DECREASE_INCEREMENT);
//        rect = scene_->addRect(LEFT_POLE-(width/2)-GAP, BORDER_DOWN-(i*DISC_HEIGHT), width, DISC_HEIGHT, blackPen, redBrush);
//        ++i;
//        pole_a.push_back(rect_);

        int width = MAX_WIDTH-(i*DECREASE_INCEREMENT);
        rect = scene_->addRect(a.x(), BORDER_DOWN-(i*DISC_HEIGHT), width, DISC_HEIGHT, blackPen, redBrush);
        rect->centerOn(a.x());)
        ++i;
        pole_a.push_back(rect);
    }

}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::on_pushButton_ab_clicked()
{
//    *rect = pole_a.at(pole_a.end()-1);
//    rect->setRect();
}
