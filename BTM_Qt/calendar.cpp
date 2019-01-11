#include "calendar.h"
#include "ui_calendar.h"
#include <QLabel>
#include <iostream>

Calendar::Calendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
    QStringList header;
    header<<"Week"<<"Team againts";
    this->ui->tableWidget->setHorizontalHeaderLabels(header);
    for (int i = 0; i < 22; i++ ) {
    this->ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
    this->ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(i)));
    }
}
Calendar::Calendar(User& myuser, League& myleague, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
    QStringList header;
    header<<"Week"<<"Team againts";
    this->ui->tableWidget->setHorizontalHeaderLabels(header);
    for (int i = 0; i < 22; i++ ) {
    this->ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
    //this->ui->tableWidget->setItem(i,1,new QTableWidgetItem(std::get<0>(myleague.Calendar[i][0])));
    }
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::on_pushButton_clicked()
{
    this -> hide();
    emit backButtonClicked();
}
