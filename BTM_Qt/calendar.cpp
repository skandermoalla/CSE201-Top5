#include "calendar.h"
#include "ui_calendar.h"
#include <QLabel>
#include <iostream>


Calendar::Calendar(User& myuser, League& myleague, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
    theuser=&myuser;
    theleague=&myleague;
    QStringList header;
    header<<"Week"<<"Team against";
    std::vector <int> B = myleague.getAllUserMatches(); //the vector with all the matches of the user
    this->ui->tableWidget->setHorizontalHeaderLabels(header);
    for (int i = 0; i < 22; i++ ) {
    this->ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
    //this->ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(B[i]-1)));
    this->ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(myleague.teams[B[i]-1].name)));
    }
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::on_pushButton_clicked()
{
    this -> hide();
    emit backButtonClicked(*(this->theuser));
    //emit backButtonClicked();
}
