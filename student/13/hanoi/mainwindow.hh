#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>
#include <vector>
#include <QPoint>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool user_defined_n = false;
    int n = 6;
    std::vector<QGraphicsRectItem*> pole_a;
    std::vector<QGraphicsRectItem*> pole_b;
    std::vector<QGraphicsRectItem*> pole_c;
    QGraphicsRectItem* rect;




//    void keyPressEvent(QKeyEvent* event) override;


private slots:
    void on_pushButton_ab_clicked();

private:
    Ui::MainWindow *ui_;

    QGraphicsScene* scene_;          // a surface for drawing the game
  // drawing a circle
    QTimer timer_;


    const int DEFAULT_DISCS = 6;
    const int BORDER_UP = 0;
    const int BORDER_DOWN = 260;
    const int BORDER_LEFT = 0;
    const int BORDER_RIGHT = 680;
    const int MIDDLE_POLE = BORDER_RIGHT / 2;
    QPoint a;
    const int RIGHT_POLE = BORDER_RIGHT - a.x();
    const int GAP = 80;
    const int MAX_WIDTH = BORDER_RIGHT / 3 - GAP;
    const int MIN_WIDTH = 10;
    int DECREASE_INCEREMENT = (MAX_WIDTH - MIN_WIDTH) / n;
    int DISC_HEIGHT = BORDER_DOWN / n;


};

#endif // MAINWINDOW_HH
