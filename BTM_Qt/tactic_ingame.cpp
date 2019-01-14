#include "tactic_ingame.h"
#include "ui_tactic_ingame.h"
#include <QMessageBox>


Tactic_inGame::Tactic_inGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tactic_inGame)
{
    ui->setupUi(this);
}

Tactic_inGame::Tactic_inGame (GameEngine* eng, User &theuser , League& league, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tactic_inGame)
{
    ui->setupUi(this);
    this->myuser = &theuser;
    this->myleague = &league;
    engine = eng;
    this->chosen = 0;
}

Tactic_inGame::~Tactic_inGame()
{
    delete ui;
}

void Tactic_inGame::on_pushButton_5_clicked() // Continue Button
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to go to the next quarter?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            emit ContinueClicked(this->engine, *(this->myuser), *(this->myleague)); // This is used to pass the infor to the nextgame window (nextgame window may need a refresh function)
            //switch "chosen" from an integer to the tactics.
            // if "chosen" is 0, then it remains unchanged;
            //"chosen" = 1 -> tactics 1 (full court press) ..."chosen" = 4 -> tactics 4 (full time attack)
            this -> close();
        }
        else if (reply == QMessageBox::No)
        {}
}

void Tactic_inGame::on_pushButton_6_clicked() //Cancel button
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to discart your changes?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            this -> close();
        }
        else if (reply == QMessageBox::No)
        {}
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
        this->ui->chosentac->setText(QString::fromStdString("Default Tactics") );
        this->chosen = -1;
    }
}

void Tactic_inGame::on_pushButton_2_clicked() // Tac 2
{
    int index = 2;
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

void Tactic_inGame::on_pushButton_3_clicked() // Tac 3
{
    int index = 3;
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

