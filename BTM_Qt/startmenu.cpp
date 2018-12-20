#include "startmenu.h"
#include "ui_startmenu.h"

StartMenu::StartMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartMenu)
{
    ui->setupUi(this);
}

StartMenu::~StartMenu()
{
    delete ui;
}
void StartMenu::on_Next_clicked()
{
    QString name = ui->nameInput->text();
    QString team_name = ui->teamInput->text();
    QString nationality = ui->nationalityInput->text();
    this -> close();
    mainwindow -> refresh();
    mainwindow -> show();

}
