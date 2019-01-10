#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <iostream>

MainWindow::MainWindow(User& theuser ,League& A,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   //training= new Training(theuser,A);
    this->myuser=&theuser;
    this->myleague=&A;
    this->team=theuser.team;
    this->ui->setupUi(this);
    this->refresh(*myuser);
    this->calendar = new Calendar();
    this->teaminfo = new TeamInfo();
    connect(this->calendar, SIGNAL(backButtonClicked()), this, SLOT(show()));
    connect(this->teaminfo, SIGNAL(backButtonClicked()), this, SLOT(show()));

}
//Window operations
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh(const User& theuser)
{
    std::cout<<"start refresh"<<std::endl;

    // Player 1
    this->ui->label->setText(QString::fromStdString(theuser.team.players[0].surname));
    this->ui->lcdNumber->display(theuser.team.players[0].overallgeneral);
    this->ui->labelp->setText(QString::fromStdString(theuser.team.players[0].position));

    // Player 2
    this->ui->label_2->setText(QString::fromStdString(theuser.team.players[1].surname));
    this->ui->lcdNumber_2->display(theuser.team.players[1].overallgeneral);
    this->ui->label_2p->setText(QString::fromStdString(theuser.team.players[1].position));

    // Player 3
    this->ui->label_3->setText(QString::fromStdString(theuser.team.players[2].surname));
    this->ui->lcdNumber_3->display(theuser.team.players[2].overallgeneral);
    this->ui->label_3p->setText(QString::fromStdString(theuser.team.players[2].position));

    // Player 4
    this->ui->label_4->setText(QString::fromStdString(theuser.team.players[3].surname));
    this->ui->lcdNumber_4->display(theuser.team.players[3].overallgeneral);
    this->ui->label_4p->setText(QString::fromStdString(theuser.team.players[3].position));

    // Player 5
    this->ui->label_5->setText(QString::fromStdString(theuser.team.players[4].surname));
    this->ui->lcdNumber_5->display(theuser.team.players[4].overallgeneral);
    this->ui->label_5p->setText(QString::fromStdString(theuser.team.players[4].position));

    // Player 6
    this->ui->label_6->setText(QString::fromStdString(theuser.team.players[5].surname));
    this->ui->lcdNumber_6->display(theuser.team.players[5].overallgeneral);
    this->ui->label_6p->setText(QString::fromStdString(theuser.team.players[5].position));

    // Player 7
    this->ui->label_7->setText(QString::fromStdString(theuser.team.players[6].surname));
    this->ui->lcdNumber_7->display(theuser.team.players[6].overallgeneral);
    this->ui->label_7p->setText(QString::fromStdString(theuser.team.players[6].position));

    // Player 8
    this->ui->label_8->setText(QString::fromStdString(theuser.team.players[7].surname));
    this->ui->lcdNumber_8->display(theuser.team.players[7].overallgeneral);
    this->ui->label_8p->setText(QString::fromStdString(theuser.team.players[7].position));

    // Player 9
    this->ui->label_9->setText(QString::fromStdString(theuser.team.players[8].surname));
    this->ui->lcdNumber_9->display(theuser.team.players[8].overallgeneral);
    this->ui->label_9p->setText(QString::fromStdString(theuser.team.players[8].position));

    // Player 10
    this->ui->label_10->setText(QString::fromStdString(theuser.team.players[9].surname));
    this->ui->lcdNumber_10->display(theuser.team.players[9].overallgeneral);
    this->ui->label_10p->setText(QString::fromStdString(theuser.team.players[9].position));

    // Player 11
    this->ui->label_11->setText(QString::fromStdString(theuser.team.players[10].surname));
    this->ui->lcdNumber_11->display(theuser.team.players[10].overallgeneral);
    this->ui->label_11p->setText(QString::fromStdString(theuser.team.players[10].position));

    // Player 12
    this->ui->label_12->setText(QString::fromStdString(theuser.team.players[11].surname));
    this->ui->lcdNumber_12->display(theuser.team.players[11].overallgeneral);
    this->ui->label_12p->setText(QString::fromStdString(theuser.team.players[11].position));

    //Energy tab
    QStringList header;
    header<<"surname"<<"Energy"<<"Motivation";
    this->ui->tableWidget_3->setColumnCount(3);
    this->ui->tableWidget_3->setRowCount(12);
    this->ui->tableWidget_3->setHorizontalHeaderLabels(header);

    for (int i = 0; i < 12; i++ ) {
    this->ui->tableWidget_3->setItem(i,0,new QTableWidgetItem(QString::fromStdString(theuser.team.players[i].surname)));
    this->ui->tableWidget_3->setItem(i,1,new QTableWidgetItem(QString::number(theuser.team.players[i].energy)));
    this->ui->tableWidget_3->setItem(i,2,new QTableWidgetItem(QString::number(theuser.team.players[i].motivation)));
    }
    this->ui->tableWidget_3->show();

    //Ability tab
    QStringList header2;
    header2<<"surname"<<"Overall"<<"Offense"<<"Deffense";
    this->ui->tableWidget_2->setColumnCount(4);
    this->ui->tableWidget_2->setRowCount(12);
    this->ui->tableWidget_2->setHorizontalHeaderLabels(header2);

    for (int i = 0; i < 12; i++ ) {
    this->ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(QString::fromStdString(theuser.team.players[i].surname)));
    this->ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::number(theuser.team.players[i].overallgeneral)));
    this->ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(QString::number(theuser.team.players[i].attack)));
    this->ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(QString::number(theuser.team.players[i].defence)));
    }
    this->ui->tableWidget_2->show();

    QStringList header3;
    header3<<"Surname"<<"Nationality"<<"Age"<<"Height"<<"Weight";
    this->ui->tableWidget->setColumnCount(5);
    this->ui->tableWidget->setRowCount(12);
    this->ui->tableWidget->setHorizontalHeaderLabels(header3);

    for (int i = 0; i < 12; i++ ) {
    this->ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(theuser.team.players[i].surname)));
    this->ui->tableWidget->setItem(i,1,new QTableWidgetItem((/*QIcon("images.png"), */"Country")));
    this->ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(theuser.team.players[i].age)));
    this->ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(theuser.team.players[i].height)));
    this->ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(theuser.team.players[i].weight)));
    }

    this->ui->tableWidget->show();
    std::cout<<"refreshed"<<std::endl;
}

void MainWindow::on_pushButton_clicked()
{
    this -> hide();
    calendar -> show();
}

void MainWindow::on_pushButton_3_clicked()
{
    this -> hide();
    this->training= new Training(*myuser,*myleague);
    connect(this->training, SIGNAL(backButtonClicked(User)), this, SLOT(show()));
    connect(this->training, SIGNAL(backButtonClicked(User)), this, SLOT(refresh(User)));
    std::cout<<"training created"<<std::endl;
    training -> show();
}

void MainWindow::on_pushButton_4_clicked()
{
    this -> hide();
    teaminfo -> show();
}
