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
    void keyPressEvent(QKeyEvent* event) override;

    // Set number of discs here
    int n = 5;

    int move_counter;
    int autoplay_counter;

    struct Disc{
        QGraphicsRectItem* disc;
        int width;
    };

    std::vector<Disc> pole_a;
    std::vector<Disc> pole_b;
    std::vector<Disc> pole_c;





//    void keyPressEvent(QKeyEvent* event) override;


private slots:
    void move_disc(std::vector<Disc> &start, std::vector<Disc> &end, int dir, int dist, QBrush color);

    void update();

    void on_push_button_ab_clicked();

    void on_push_button_ba_clicked();

    void on_push_button_ac_clicked();

    void on_push_button_bc_clicked();

    void on_push_button_ca_clicked();

    void on_push_button_cb_clicked();

    void check_win();

    void check_poles();

    bool is_possible(std::vector<Disc> &start, std::vector<Disc> &end);

    void on_push_button_autoplay_clicked();

    void autoplay();

    void on_push_button_stop_autoplay_clicked();

private:
    Ui::MainWindow *ui_;

    QGraphicsScene* scene_;         // a surface for drawing the game
    QGraphicsRectItem* rect_;       // drawing a rectangle
    QTimer* timer_;
    QTimer* autoplay_timer_;




    const int DEFAULT_DISCS = 6;
    const int BORDER_UP = 0;
    const int BORDER_DOWN = 260;
    const int BORDER_LEFT = 0;
    const int BORDER_RIGHT = 680;
    const int GAP = 50;
    const int MAX_WIDTH = (BORDER_RIGHT - (4 * GAP)) / 3;
    const int POLE_GAP = MAX_WIDTH + GAP;
    const int LEFT_POLE = GAP;
    const int MIDDLE_POLE = LEFT_POLE + MAX_WIDTH + GAP;
    const int RIGHT_POLE = MIDDLE_POLE + MAX_WIDTH + GAP;
    const int MIN_WIDTH = 10;
    int DECREASE_INCEREMENT = (MAX_WIDTH - MIN_WIDTH) / n;
    int DISC_HEIGHT = BORDER_DOWN / n;

    QPoint a;
    QPoint b;
    QPoint c;

    QBrush redBrush;
    QBrush blueBrush;
    QBrush greenBrush;
    QPen blackPen;

};

#endif // MAINWINDOW_HH
