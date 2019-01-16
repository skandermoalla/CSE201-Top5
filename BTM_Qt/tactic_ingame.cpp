#include "tactic_ingame.h"
#include "ui_tactic_ingame.h"
#include <QMessageBox>


Tactic_inGame::Tactic_inGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tactic_inGame)
{
    ui->setupUi(this);
}

Tactic_inGame::Tactic_inGame(GameEngine* eng, Team* playingManagersTeam, Team* initManagersTeam,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tactic_inGame)

{
    ui->setupUi(this);
    this->managersTeam = playingManagersTeam;
    this->initManagersTeam = initManagersTeam;
    engine = eng;
    this->chosen = 0;
}

Tactic_inGame::~Tactic_inGame()
{
    delete ui;
}

void Tactic_inGame::on_pushButton_5_clicked() // Continue Button
{
    // emit ContinueClicked(this->engine, *(this->myuser), *(this->myleague)); // This is used to pass the infor to the nextgame window (nextgame window may need a refresh function)
    //switch "chosen" from an integer to the tactics.
    // if "chosen" is 0, then it remains unchanged;
    //"chosen" = 1 -> tactics 1 (full court press) ..."chosen" = 4 -> tactics 4 (full time attack)
    switch(chosen) {
        case 0: engine->getBacktoDefaultTactic(*managersTeam, *initManagersTeam); break;
        case 1: engine->applyTactic(*managersTeam, "FullCourtPress"); break;
        case 2: engine->applyTactic(*managersTeam, "FastBreak"); break;
        case 3: engine->applyTactic(*managersTeam, "ZoneDefence"); break;
        case 4: engine->applyTactic(*managersTeam, "FullTimeAttack"); break;
    }
    this -> close();

}

void Tactic_inGame::on_pushButton_6_clicked() //Cancel button
{
    this -> close();
}

void Tactic_inGame::on_pushButton_clicked() //  Tac 1
{
    int index = 1;
    if (this->chosen != index)
    {
        this->ui->chosentac->setText(QString::fromStdString("Full Court Press") );
        this->chosen = index;
    }
    else
    {
        this->ui->chosentac->setText(QString::fromStdString("Fast Break"));
        this->chosen = -1;
    }
}

void Tactic_inGame::on_pushButton_2_clicked() // Tac 2
{
    int index = 2;
    if (this->chosen != index)
    {
        this->ui->chosentac->setText(QString::fromStdString("Zone Defence") );
        this->chosen = index;
    }
    else
    {
        this->ui->chosentac->setText(QString::fromStdString("Default Tactics") );
        this->chosen = -1;
    }
}

void Tactic_inGame::on_pushButton_3_clicked() // Tac 3
{
    int index = 3;
    if (this->chosen != index)
    {
        this->ui->chosentac->setText(QString::fromStdString("FullTime Attack") );
        this->chosen = index;
    }
    else
    {
        this->ui->chosentac->setText(QString::fromStdString("Default Tactics") );
        this->chosen = -1;
    }
}

void Tactic_inGame::on_pushButton_4_clicked() // Tac 4
{
    int index = 4;
    if (this->chosen != index)
    {
        this->ui->chosentac->setText(QString::fromStdString("Full Court Press") );
        this->chosen = index;
    }
    else
    {
        this->ui->chosentac->setText(QString::fromStdString("Default Tactics") );
        this->chosen = -1;
    }
}

