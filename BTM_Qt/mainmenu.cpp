#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "startmenu.h"
#include  <QMessageBox>


MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_start_clicked()
{
    this->hide();
    startmenu->show();
}

void MainMenu::on_quit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to leave the game?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            this -> close();
        }
        else if (reply == QMessageBox::No)
        {}
}
