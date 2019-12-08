/* Module: MainWindow
 * ---------------
 * The main window for Hanoi's Tower game.
 * ---------------
 *
 * This is a game where you have to move all discs from the starting pole to
 * another pole. Detailed instructions in Finnish in instructions.txt
 *
 * Mikko Kemppi, 272670
 * mikko.kemppi@tuni.fi
 *
 *
 * ---------------
 * TIE-02201 S2019
 * */


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


    // Data structure for a single disc
    struct Disc{
        QGraphicsRectItem* disc;
        int width;
    };

    // Containers for Discs
    std::vector<Disc> pole_a;
    std::vector<Disc> pole_b;
    std::vector<Disc> pole_c;

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

    // Set number of discs here
    const int n = 6;


    // Default scale of time, value of 1 equals 1 in-game second is 1 real-life
    // second
    const float TIMESCALE = 1;
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


    int move_counter = 0;
    int autoplay_counter = 0;

    QPoint a;
    QPoint b;
    QPoint c;

    QBrush redBrush;
    QBrush blueBrush;
    QBrush greenBrush;
    QPen blackPen;

};

#endif // MAINWINDOW_HH
