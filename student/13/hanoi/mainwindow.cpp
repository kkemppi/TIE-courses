#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QLabel>
#include <QString>

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

    a.setX(LEFT_POLE);
    b.setX(MIDDLE_POLE);
    c.setX(RIGHT_POLE);



    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QPen blackPen(Qt::black);

    if (user_defined_n){
        // Implementation for custom n
    }
    int i = 0;
    while(i<=n){
        int width = MAX_WIDTH-(i*DECREASE_INCEREMENT);
        rect_ = scene_->addRect(LEFT_POLE+(i*(DECREASE_INCEREMENT)/2), BORDER_DOWN-(i*DISC_HEIGHT), width, DISC_HEIGHT, blackPen, redBrush);
        ++i;
        pole_a.push_back(rect_);
    }

//    scene_->addRect(b.x()-(pole_a.at(5)->, BORDER_DOWN, ))

}

MainWindow::~MainWindow()
{
    delete ui_;
}


void MainWindow::move_disc(std::vector<QGraphicsRectItem *>, std::vector<QGraphicsRectItem *>)
{

}

void MainWindow::on_push_button_ab_clicked()
{

    pole_b.push_back(pole_a.at(pole_a.size()-1));
    qreal deltaX = static_cast<qreal>(POLE_GAP);
//    qreal deltaY = static_cast<qreal>();
    pole_b.at(pole_b.size()-1)->moveBy(deltaX, 0);

    pole_a.pop_back();

//    pole_b.at(0)->y() = BORDER_DOWN;

}
