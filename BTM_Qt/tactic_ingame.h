#ifndef TACTIC_INGAME_H
#define TACTIC_INGAME_H

#include <QDialog>
#include"User.h"
#include"League.h"
#include"nextgame.h"
#include "GameEngine/gameengine.h"

namespace Ui {
class Tactic_inGame;
}

class Tactic_inGame : public QDialog
{
    Q_OBJECT

public:
    explicit Tactic_inGame(QWidget *parent = nullptr);
    explicit Tactic_inGame(GameEngine* eng, User& theuser,League& league, QWidget *parent = nullptr);
    User* myuser;
    League* myleague;
    GameEngine* engine;
    ~Tactic_inGame();

signals:
    void ContinueClicked(const GameEngine*, const User&, const League&);

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Tactic_inGame *ui;
    int chosen;
};

#endif // TACTIC_INGAME_H
