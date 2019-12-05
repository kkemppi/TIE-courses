#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <cmath>

#define a_last pole_a.size()-1
#define b_last pole_b.size()-1
#define c_last pole_c.size()-1

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
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
    int i = 0;
    while(i<n){
        int width = MAX_WIDTH-(i*DECREASE_INCEREMENT);
        rect_ = scene_->addRect(LEFT_POLE+(i*(DECREASE_INCEREMENT/2)), BORDER_DOWN-((i+1)*DISC_HEIGHT), width, DISC_HEIGHT, blackPen, redBrush);
        ++i;
        pole_a.push_back(rect_);
    }
    scene_->addRect(LEFT_POLE+(MAX_WIDTH/2)-(MIN_WIDTH-5), BORDER_UP, MIN_WIDTH-5, BORDER_DOWN, blackPen, redBrush);
    scene_->addRect(MIDDLE_POLE+(MAX_WIDTH/2)-(MIN_WIDTH-5), BORDER_UP, MIN_WIDTH-5, BORDER_DOWN, blackPen, greenBrush);
    scene_->addRect(RIGHT_POLE+(MAX_WIDTH/2)-(MIN_WIDTH-5), BORDER_UP, MIN_WIDTH-5, BORDER_DOWN, blackPen, blueBrush);




}

MainWindow::~MainWindow()
{
    delete ui_;
}


void MainWindow::move_disc(std::vector<QGraphicsRectItem *>& start, std::vector<QGraphicsRectItem *>& end, int dir, int dist = 1)
{
    if (start.size() > end.size()){
        qreal y_offset = (start.size()*DISC_HEIGHT)-(end.size()*DISC_HEIGHT);
        start.at(start.size()-1)->moveBy(dist*dir*POLE_GAP, y_offset-DISC_HEIGHT);
    }
    else if(start.size() < end.size()){
        qreal y_offset = (end.size()*DISC_HEIGHT)-(start.size()*DISC_HEIGHT);
        start.at((start.size()-1))->moveBy(dist*dir*POLE_GAP, -(DISC_HEIGHT+y_offset));
    }else if(start.size() == end.size()){
        qreal y_offset = DISC_HEIGHT;
        start.at((start.size()-1))->moveBy(dist*dir*POLE_GAP, -y_offset);
    }
    end.push_back(start.at((start.size()-1)));
    start.pop_back();
    qDebug() << start.size() << end.size();
}

void MainWindow::on_push_button_ab_clicked()
{
    move_disc(pole_a, pole_b, 1);
}

void MainWindow::on_push_button_ba_clicked()
{
    move_disc(pole_b, pole_a, -1);
}

void MainWindow::on_push_button_ac_clicked()
{
    move_disc(pole_a, pole_c, 1, 2);
}

void MainWindow::on_push_button_bc_clicked()
{
    move_disc(pole_b, pole_c, 1);
}

void MainWindow::on_push_button_ca_clicked()
{
    move_disc(pole_c, pole_a, -1, 2);
}

void MainWindow::on_push_button_cb_clicked()
{
    move_disc(pole_c, pole_b, -1);
}
