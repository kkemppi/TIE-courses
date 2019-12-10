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
#include <cmath>

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
/*  Function for moving a disc from start pole to end pole. Checks both poles'
 * height and determines the vertical distance to move, and then moves according
 * to given parameters. Adds the Disc to the target pole's container and removes
 * it from start pole's. After every move the win condition and available moves
 * are checked
 *
 * Params:
 * std::vector<Disc>& start: Starting pole
 * std::vector<Disc>& end: Destination pole
 * int dir: Direction of movement, -1 for left, 1 for right
 * int dist: Distance of movement, 1 for moving by one POLE_GAP, 2 for moving
 * by two POLE_GAPs
 * QBrush color: Color of the destination pole
 */
    void move_disc(std::vector<Disc> &start, std::vector<Disc> &end, int dir,
                   int dist, QBrush color);



    // Functions for different buttons to move the discs. Buttons ab and ba
    // start the timer and set autoplay to disabled.
    void on_push_button_ab_clicked();

    void on_push_button_ba_clicked();

    void on_push_button_ac_clicked();

    void on_push_button_bc_clicked();

    void on_push_button_ca_clicked();

    void on_push_button_cb_clicked();

    // Checks if user has won. If the user has won, stops timers, displays
    // win message and disables all but close button.
    void check_win();

    // Checks if moving a Disc between start pole and end pole is legal
    bool is_possible(std::vector<Disc> &start, std::vector<Disc> &end);

    // Compares all poles to eachother and disables push buttons with illegal
    // moves
    void check_poles();

    // Updates the timer to new value
    void update();

    // Starts the autoplay timer, disables gameplay buttons
    void on_push_button_autoplay_clicked();

    // Stops autoplay and enables buttons with legal moves
    void on_push_button_stop_autoplay_clicked();

    // Performs a move determined by an iterative algorithm. Uses a counter to
    // perform only a single move when called, and performs the next available
    // next time it is called
    void autoplay();



private:
    Ui::MainWindow *ui_;

    QGraphicsScene* scene_;         // a surface for drawing the game
    QGraphicsRectItem* rect_;       // drawing a rectangle
    QTimer* timer_;
    QTimer* autoplay_timer_;

    // Set number of discs here, values of over 20 make the game last very long,
    // and might make the towers look wonky
    const int n = 5;


    // Default scale of time, value of 1 equals 1 in-game second is 1 real-life
    // second
    const float TIMESCALE = 1;

    // Maths for determining the locations of discs. Game area has three poles
    // and four gaps.
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
    const int DECREASE_INCEREMENT = (MAX_WIDTH - MIN_WIDTH) / n;
    const int DISC_HEIGHT = BORDER_DOWN / n;
    const int MIN_MOVES = pow(2, n) - 1;

    // Counters for displaying used moves and to keep autoplay doing the right
    // move
    int move_counter = 0;
    int autoplay_counter = 0;

    // Color for discs, poles and outlines
    QBrush redBrush;
    QBrush blueBrush;
    QBrush greenBrush;
    QPen blackPen;

};

#endif // MAINWINDOW_HH
