#ifndef NEXTGAME_H
#define NEXTGAME_H
#include <QLCDNumber>
#include <QDialog>
#include<QTimer>
#include <User.h>
#include <League.h>
#include <GameEngine/gameengine.h>
#include <tactic_ingame.h>
namespace Ui {
class NextGame;
}

class NextGame : public QDialog
{
    Q_OBJECT

public:
    explicit NextGame(QWidget *parent = nullptr);
    explicit NextGame(GameEngine* eng, User& theuser, League& league, QWidget *parent = nullptr);
    ~NextGame();
public slots:
    void quarter_1_timing();//function that set and display the time
    void quarter_2_timing();
    void quarter_3_timing();
    void quarter_4_timing();
    void strat();

private slots:
    void on_start_clicked(); //click start button

    void on_second_q_clicked();

    void on_third_q_clicked();

    void on_fourth_q_clicked();

    void on_end_game_clicked();

    void on_tactics_clicked();

private:
    Ui::NextGame *ui;
    QTimer *timer;
    QTimer *s_timer;
    User* myuser;
    League* myleague;
    GameEngine* engine;

    Tactic_inGame *tactic_ingame;
    bool isManagerAttacking;
    std::pair<int, int> score;

    Team playingManagersTeam;
    Team playingOpponentsTeam;

    //method


};

#endif // NEXTGAME_H
