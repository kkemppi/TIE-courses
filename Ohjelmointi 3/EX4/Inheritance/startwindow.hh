#ifndef STARTWINDOW_HH
#define STARTWINDOW_HH

#include <QDialog>
#include "objectcontroller.hh"
#include "constants.hh"
#include "movingobjectgraphics.hh"

namespace Ui {
class startwindow;
}

class startwindow : public QDialog
{
    Q_OBJECT

public:
    explicit startwindow(QWidget *parent = nullptr);
    ~startwindow();

public slots:
    void on_startButton_clicked();
    void on_amountSpinBox_valueChanged(int arg1);

    void on_quitButton_clicked();

    int getCount();
signals:
    void startClicked(int, ObjectType);


private:
    Ui::startwindow *ui;

    int count;
};

#endif // STARTWINDOW_HH
