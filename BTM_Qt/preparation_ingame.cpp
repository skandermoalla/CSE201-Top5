#include "preparation_ingame.h"
#include "ui_preparation_ingame.h"

Preparation_inGame::Preparation_inGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preparation_inGame)
{
    ui->setupUi(this);
}

Preparation_inGame::~Preparation_inGame()
{
    delete ui;
}
