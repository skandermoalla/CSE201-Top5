#include "startmenu.h"
#include "ui_startmenu.h"
#include <string>
#include<iostream>

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


    this -> hide();
    User* user=new User(name.toStdString(), team_name.toStdString(), nationality.toStdString());
    League* A=new League(3,"1819");
    mainwindow = new MainWindow(*user,*A);
    std::cout<<"main window created"<<std::endl;
    mainwindow -> show();

}
