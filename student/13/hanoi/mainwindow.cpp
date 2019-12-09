#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>

#define a_last pole_a.size()-1
#define b_last pole_b.size()-1
#define c_last pole_c.size()-1

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);


    timer_ = new QTimer(this);          // Timer for displaying gametime
    autoplay_timer_ = new QTimer(this); // Timer for making autoplay moves
    scene_ = new QGraphicsScene(this);


    connect(timer_, &QTimer::timeout, this, &MainWindow::update);
    connect(autoplay_timer_, &QTimer::timeout, this, &MainWindow::autoplay);


    int left_margin = 10; // x coordinate
    int top_margin = 270; // y coordinate

    // Create a graphicsView and take 1px wide borders into account
    ui_->graphicsView->setGeometry(left_margin, top_margin,
                                   BORDER_RIGHT + 2, BORDER_DOWN + 2);
    ui_->graphicsView->setScene(scene_);
    scene_->setSceneRect(0, 0, BORDER_RIGHT - 1, BORDER_DOWN - 1);


    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QPen blackPen(Qt::black);

    // Create as many discs as specified in const int n and add discs
    // to container and to the game board.
    int i = 0;
    while(i<n){
        int width = MAX_WIDTH-(i*DECREASE_INCEREMENT);
        struct Disc disc = {(scene_->addRect(LEFT_POLE+(i*
        (DECREASE_INCEREMENT/2)), BORDER_DOWN-((i+1)*DISC_HEIGHT), width,
        DISC_HEIGHT, blackPen, redBrush)), width};

        ++i;
        pole_a.push_back(disc);
    }

    // Create three poles
    scene_->addRect(LEFT_POLE+(MAX_WIDTH/2)-(MIN_WIDTH-(MIN_WIDTH/2)), BORDER_UP, MIN_WIDTH/2, BORDER_DOWN, blackPen, redBrush);
    scene_->addRect(MIDDLE_POLE+(MAX_WIDTH/2)-(MIN_WIDTH-(MIN_WIDTH/2)), BORDER_UP, MIN_WIDTH/2, BORDER_DOWN, blackPen, greenBrush);
    scene_->addRect(RIGHT_POLE+(MAX_WIDTH/2)-(MIN_WIDTH-(MIN_WIDTH/2)), BORDER_UP, MIN_WIDTH/2, BORDER_DOWN, blackPen, blueBrush);

    // Set colors to timer numbers
    ui_->lcd_number_minutes->setPalette(Qt::green);
    ui_->lcd_number_seconds->setPalette(Qt::blue);

    // Disable buttons with illegal moves
    check_poles();



}


MainWindow::~MainWindow()
{
    delete ui_;
}


void MainWindow::move_disc(std::vector<Disc>& start, std::vector<Disc>& end, int dir, int dist, QBrush color)
{
    // Determine y_offset and move disc
    if (start.size() > end.size()){
        qreal y_offset = (start.size()*DISC_HEIGHT)-(end.size()*DISC_HEIGHT);
        start.at(start.size()-1).disc->moveBy(dist*dir*POLE_GAP, y_offset-DISC_HEIGHT);
    }
    else if(start.size() < end.size()){
        qreal y_offset = (end.size()*DISC_HEIGHT)-(start.size()*DISC_HEIGHT);
        start.at((start.size()-1)).disc->moveBy(dist*dir*POLE_GAP, -(DISC_HEIGHT+y_offset));
    }else if(start.size() == end.size()){
        qreal y_offset = DISC_HEIGHT;
        start.at((start.size()-1)).disc->moveBy(dist*dir*POLE_GAP, -y_offset);
    }

    // Add the disc to the end pole's container and remove from start pole's
    end.push_back(start.at((start.size()-1)));
    start.pop_back();

    end.at(end.size()-1).disc->setBrush(color);

    // If not using autoplay, update buttons
    if (!autoplay_timer_->isActive()){
        check_poles();
    }

    // Increase move counter by one
    move_counter++;
    ui_->label_move_counter->setText(QString::number(move_counter));
    ui_->list_widget->scrollToBottom();

    check_win();
}


void MainWindow::on_push_button_ab_clicked()
{
    if (!(timer_->isActive())){
        timer_->start(100*TIMESCALE);
    }
    move_disc(pole_a, pole_b, 1, 1, Qt::green);
    ui_->push_button_autoplay->setDisabled(true);
    if (!autoplay_timer_->isActive()){
        ui_->push_button_stop_autoplay->setDisabled(true);
    }
    new QListWidgetItem(tr("A->B"), ui_->list_widget);
}


void MainWindow::on_push_button_ac_clicked()
{
    if (!(timer_->isActive())){
        timer_->start(100*TIMESCALE);
    }
    move_disc(pole_a, pole_c, 1, 2, Qt::blue);
    ui_->push_button_autoplay->setDisabled(true);
    if (!autoplay_timer_->isActive()){
        ui_->push_button_stop_autoplay->setDisabled(true);
    }
    new QListWidgetItem(tr("A->C"), ui_->list_widget);
}

void MainWindow::on_push_button_ba_clicked()
{
    move_disc(pole_b, pole_a, -1, 1, Qt::red);
    new QListWidgetItem(tr("B->A"), ui_->list_widget);
}


void MainWindow::on_push_button_bc_clicked()
{
    move_disc(pole_b, pole_c, 1, 1 , Qt::blue);
    new QListWidgetItem(tr("B->C"), ui_->list_widget);
}

void MainWindow::on_push_button_ca_clicked()
{
    move_disc(pole_c, pole_a, -1, 2, Qt::red);
    new QListWidgetItem(tr("C->A"), ui_->list_widget);
}

void MainWindow::on_push_button_cb_clicked()
{
    move_disc(pole_c, pole_b, -1, 1, Qt::green);
    new QListWidgetItem(tr("C->B"), ui_->list_widget);
}


void MainWindow::check_win()
{
    if ((pole_a.empty() && pole_b.empty()) || (pole_a.empty() && pole_c.empty() )){
        ui_->push_button_ab->setDisabled(true);
        ui_->push_button_ac->setDisabled(true);
        ui_->push_button_ba->setDisabled(true);
        ui_->push_button_bc->setDisabled(true);
        ui_->push_button_ca->setDisabled(true);
        ui_->push_button_cb->setDisabled(true);
        ui_->push_button_autoplay->setDisabled(true);
        timer_->stop();
        autoplay_timer_->stop();
        ui_->lcd_number_minutes->setPalette(Qt::red);
        ui_->lcd_number_seconds->setPalette(Qt::red);
        ui_->label_timer->setText("Final time");
        ui_->label_win->setText("You win!");
        ui_->label_win->setStyleSheet("QLabel {background-color : green; color : white;}");
    }
}


bool MainWindow::is_possible(std::vector<Disc>& first, std::vector<Disc>& second)
{
    if (first.empty() && second.empty()){
        return false;
    }
    else if(first.empty()){
        return false;
    }
    else if(second.empty()){
        return true;
    }else{
        if(first.at(first.size()-1).width < second.at(second.size()-1).width){
            return true;
        }
    }return false;

}


void MainWindow::check_poles()
{
    if(is_possible(pole_a, pole_b)){
        ui_->push_button_ab->setEnabled(true);
    }else{
        ui_->push_button_ab->setDisabled(true);
    }

    if(is_possible(pole_a, pole_c)){
        ui_->push_button_ac->setEnabled(true);
    }else{
        ui_->push_button_ac->setDisabled(true);
    }

    if(is_possible(pole_b, pole_a)){
        ui_->push_button_ba->setEnabled(true);
    }else{
        ui_->push_button_ba->setDisabled(true);
    }

    if(is_possible(pole_b, pole_c)){
        ui_->push_button_bc->setEnabled(true);
    }else{
        ui_->push_button_bc->setDisabled(true);
    }

    if(is_possible(pole_c, pole_a)){
        ui_->push_button_ca->setEnabled(true);
    }else{
        ui_->push_button_ca->setDisabled(true);
    }

    if(is_possible(pole_c, pole_b)){
        ui_->push_button_cb->setEnabled(true);
    }else{
        ui_->push_button_cb->setDisabled(true);
    }
}


void MainWindow::update()
{
    ui_->lcd_number_seconds->display(ui_->lcd_number_seconds->value()+0.1);
    if (ui_->lcd_number_seconds->value() >= 60){
        ui_->lcd_number_minutes->display(ui_->lcd_number_minutes->value()+1);
        ui_->lcd_number_seconds->display(0);
    }
}


void MainWindow::on_push_button_autoplay_clicked()
{
    autoplay_timer_->start(1000*TIMESCALE);
    autoplay();
    timer_->start(100*TIMESCALE);
    ui_->push_button_ab->setDisabled(true);
    ui_->push_button_ac->setDisabled(true);
    ui_->push_button_ba->setDisabled(true);
    ui_->push_button_bc->setDisabled(true);
    ui_->push_button_ca->setDisabled(true);
    ui_->push_button_cb->setDisabled(true);
    ui_->push_button_autoplay->setDisabled(true);
}


void MainWindow::on_push_button_stop_autoplay_clicked()
{
    autoplay_timer_->stop();
    check_poles();
    ui_->push_button_stop_autoplay->setDisabled(true);
}

void MainWindow::autoplay()
{
    if(autoplay_counter==0){
        if (is_possible(pole_a, pole_b)){
            on_push_button_ab_clicked();
            autoplay_counter++;
        }else{
            on_push_button_ba_clicked();
            autoplay_counter++;
        }
    }
    else if(autoplay_counter==1){
        if (is_possible(pole_a, pole_c)){
            on_push_button_ac_clicked();
            autoplay_counter++;
        }else{
            on_push_button_ca_clicked();
            autoplay_counter++;
        }
    }
    else if(autoplay_counter==2){
        if (is_possible(pole_b, pole_c)){
            on_push_button_bc_clicked();
            autoplay_counter = 0;
        }else{
            on_push_button_cb_clicked();
            autoplay_counter = 0;
        }
    }
}


// Handles user's key presses
void MainWindow::keyPressEvent(QKeyEvent* event) {

    if(event->key() == Qt::Key_Q) {
        if (is_possible(pole_a, pole_b)){
            on_push_button_ab_clicked();
        }
    }
    if(event->key() == Qt::Key_W) {
        if (is_possible(pole_a, pole_c)){
            on_push_button_ac_clicked();
        }
    }
    if(event->key() == Qt::Key_E) {
        if (is_possible(pole_b, pole_a)){
            on_push_button_ba_clicked();
        }
    }
    if(event->key() == Qt::Key_R) {
        if (is_possible(pole_b, pole_c)){
            on_push_button_bc_clicked();
        }
    }
    if(event->key() == Qt::Key_T) {
        if (is_possible(pole_c, pole_a)){
            on_push_button_ca_clicked();
        }
    }
    if(event->key() == Qt::Key_Y) {
        if (is_possible(pole_c, pole_b)){
            on_push_button_ca_clicked();
        }
    }
}

