#ifndef NEXTGAME_H
#define NEXTGAME_H
#include <QLCDNumber>
#include <QDialog>
#include<QTimer>
#include <User.h>
#include <League.h>
#include <GameEngine/gameengine.h>
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

    void quarter_timing();//function that set and display the time

    void strat();

private slots:
    void on_start_clicked(); //click start function

private:
    Ui::NextGame *ui;
    QTimer *timer;
    QTimer *s_timer;
    User* myuser;
    League* myleague;
    GameEngine* engine;
    bool isManagerAttacking;
    std::pair<int, int> score;

    Team playingManagersTeam;
    Team playingOpponentsTeam;

    //method


};

#endif // NEXTGAME_H
