#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <string>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
//    QString (filu),
//    QString (key)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fileLineEdit_editingFinished()
{
    QString filu = ui->fileLineEdit->text();
}


void MainWindow::on_findPushButton_clicked()
{
    if(!QFile::exists(ui->fileLineEdit->text())){
        ui->textBrowser->setText(FILE_NOT_FOUND);
    }
    else if (QFile::exists(ui->fileLineEdit->text())){
        QFile file(ui->fileLineEdit->text());
        file.open(QIODevice::ReadWrite);
        if (ui->checkBox->isChecked()){
            if(ui->keyLineEdit->text().isEmpty()){
                ui->textBrowser->setText(FILE_FOUND);
            }else{
                QTextStream in(&file);
                QString searchString(ui->keyLineEdit->text());
                while (!in.atEnd()) {
                        QString line = in.readLine();
                        if (line.contains(searchString, Qt::CaseSensitive)){
                            ui->textBrowser->setText(WORD_FOUND);
                            return;
                        }
                }
                ui->textBrowser->setText(WORD_NOT_FOUND);
            }
        }else{
            if(ui->keyLineEdit->text().isEmpty()){
                ui->textBrowser->setText(FILE_FOUND);
            }else{
                QTextStream in(&file);
                QString searchString(ui->keyLineEdit->text());
                while (!in.atEnd()) {
                        QString line = in.readLine();
                        if (line.contains(searchString, Qt::CaseInsensitive)){
                            ui->textBrowser->setText(WORD_FOUND);
                            return;
                        }
                }
            ui->textBrowser->setText(WORD_NOT_FOUND);
            }
        }
    file.close();
    }
}

void MainWindow::on_keyLineEdit_editingFinished()
{
    QString key = ui->keyLineEdit->text();
}
