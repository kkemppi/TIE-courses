#include "startwindow.hh"
#include "ui_startwindow.h"
#include "QDebug"
#include "fastball.hh"
#include "constants.hh"
#include "movingobjectgraphics.hh"
#include "startwindow.hh"

startwindow::startwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startwindow)
{
    ui->setupUi(this);
}

startwindow::~startwindow()
{
    delete ui;
}

void startwindow::on_startButton_clicked()
{
    emit startClicked(count, FASTBALL);
    accept();
}

void startwindow::on_amountSpinBox_valueChanged(int arg1)
{
    count = arg1;
}

void startwindow::on_quitButton_clicked()
{
    reject();
}

int startwindow::getCount()
{
    return count;
}
