#include "startmenu.h"
#include "ui_startmenu.h"
#include <string>
#include <iostream>
#include <QMessageBox>

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
    if (name.toStdString() == "" || team_name.toStdString() == "" || nationality.toStdString() == ""){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You have to complete your information",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else {
        this -> hide();
        User* user=new User(name.toStdString(), team_name.toStdString(), nationality.toStdString());
        League* A=new League(3,"1819");
        A->teams[0]=user->team;
        A->ranking[0]=user->team;
        mainwindow = new MainWindow(*user,*A);
        mainwindow -> show();
    }


}
