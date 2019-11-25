#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <string>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fileLineEdit_editingFinished()
{
    QString file_to_be_found = ui->fileLineEdit->text();
}


void MainWindow::on_findPushButton_clicked()
{
    const QString FILE_NOT_FOUND = "File not found";
    const QString FILE_FOUND = "File found";
    const QString WORD_NOT_FOUND ="Word not found";
    const QString WORD_FOUND = "Word found";
    qDebug() << QFile::exists(ui->fileLineEdit->text());
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
                QString searchString(ui->keyLineEdit->text());
                QTextStream in (&file);
                QString line;
                do {
                    line = in.readLine();
                    if(line.contains(searchString, Qt::CaseSensitive)){
                        ui->textBrowser->setText(WORD_FOUND);
                        break;
                    }
                } while (!line.isNull());
                if (line.isNull()){
                                ui->textBrowser->setText(WORD_NOT_FOUND);
                }
            }
        }else{
            if(ui->keyLineEdit->text().isEmpty()){
                ui->textBrowser->setText(FILE_FOUND);
            }else{
                QString searchString(ui->keyLineEdit->text());
                QTextStream in (&file);
                QString line;
                do {
                    line = in.readLine();
                    if(line.contains(searchString, Qt::CaseInsensitive)){
                        ui->textBrowser->setText(WORD_FOUND);
                        break;
                    }
                } while (!line.isNull());
                if (line.isNull()){
                                ui->textBrowser->setText(WORD_NOT_FOUND);
                }
            file.close();
            }
        }
    }
}

void MainWindow::on_keyLineEdit_editingFinished()
{
    QString text_to_be_found = ui->keyLineEdit->text();
}
