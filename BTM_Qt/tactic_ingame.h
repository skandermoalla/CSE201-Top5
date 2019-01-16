#ifndef TACTIC_INGAME_H
#define TACTIC_INGAME_H

#include <QDialog>
#include"User.h"
#include"League.h"
#include "GameEngine/gameengine.h"

namespace Ui {
class Tactic_inGame;
}

class Tactic_inGame : public QDialog
{
    Q_OBJECT

public:
    explicit Tactic_inGame(QWidget *parent);
    explicit Tactic_inGame(GameEngine* eng, Team* playingManagersTeam, Team* initManagersTeam, QWidget *parent = nullptr);
    Team* managersTeam;
    Team* initManagersTeam;
    GameEngine* engine;
    ~Tactic_inGame();

signals:
    void ContinueClicked(const GameEngine*, const User&, const League&); // to do

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Tactic_inGame *ui;
    int chosen;
};

#endif // TACTIC_INGAME_H
