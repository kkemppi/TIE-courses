#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>
#include <vector>
#include <QPoint>
#include <QLabel>

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
    int n = 25;
    std::vector<QGraphicsRectItem*> pole_a;
    std::vector<QGraphicsRectItem*> pole_b;
    std::vector<QGraphicsRectItem*> pole_c;

    QLabel* history;




//    void keyPressEvent(QKeyEvent* event) override;


private slots:
    void move_disc(std::vector<QGraphicsRectItem*>, std::vector<QGraphicsRectItem*>);

    void on_push_button_ab_clicked();

private:
    Ui::MainWindow *ui_;

    QGraphicsScene* scene_;         // a surface for drawing the game
    QGraphicsRectItem* rect_;       // drawing a rectangle
    QTimer timer_;


    const int DEFAULT_DISCS = 6;
    const int BORDER_UP = 0;
    const int BORDER_DOWN = 260;
    const int BORDER_LEFT = 0;
    const int BORDER_RIGHT = 680;
    const int RIGHT_POLE = MIDDLE_POLE + GAP;
    const int LEFT_POLE = GAP;
    const int POLE_GAP = (BORDER_RIGHT / 3) - GAP;
    const int MIDDLE_POLE = LEFT_POLE + MAX_WIDTH + GAP;
    const int GAP = 50;
    const int MAX_WIDTH = (BORDER_RIGHT - (3 * GAP)) / 3; // - GAP;
    const int MIN_WIDTH = 10;
    int DECREASE_INCEREMENT = (MAX_WIDTH - MIN_WIDTH) / n;
    int DISC_HEIGHT = BORDER_DOWN / n;

    QPoint a;
    QPoint b;
    QPoint c;


};

#endif // MAINWINDOW_HH
