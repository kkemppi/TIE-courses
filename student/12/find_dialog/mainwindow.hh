#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_findPushButton_clicked();

private:
    Ui::MainWindow *ui;

    const QString FILE_NOT_FOUND = "File not found";
    const QString FILE_FOUND = "File found";
    const QString WORD_NOT_FOUND ="Word not found";
    const QString WORD_FOUND = "Word found";
};

#endif // MAINWINDOW_HH
