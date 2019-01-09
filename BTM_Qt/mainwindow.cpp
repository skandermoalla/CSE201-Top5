#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(calendar, SIGNAL(backButtonClicked()), this, SLOT(show()));
    connect(training, SIGNAL(backButtonClicked()), this, SLOT(show()));
    connect(teaminfo, SIGNAL(backButtonClicked()), this, SLOT(show()));

    // We may need a function to refresh the display
    // the function pack up all the operations on data below
    // the function may take the current game state as an argument

    // Player 1
    this->ui->label->setText(QString("BILIBILI"));
    this->ui->lcdNumber->display(QString("55"));
    this->ui->labelp->setText(QString("SG"));

    // Player 2
    this->ui->label_2->setText(QString("BILIBILI"));
    this->ui->lcdNumber_2->display(QString("55"));
    this->ui->label_2p->setText(QString("SG"));

    // Player 3
    this->ui->label_3->setText(QString("BILIBILI"));
    this->ui->lcdNumber_3->display(QString("55"));
    this->ui->label_3p->setText(QString("SG"));

    // Player 4
    this->ui->label_4->setText(QString("BILIBILI"));
    this->ui->lcdNumber_4->display(QString("55"));
    this->ui->label_4p->setText(QString("SG"));

    // Player 5
    this->ui->label_5->setText(QString("BILIBILI"));
    this->ui->lcdNumber_5->display(QString("55"));
    this->ui->label_5p->setText(QString("SG"));

    // Player 6
    this->ui->label_6->setText(QString("BILIBILI"));
    this->ui->lcdNumber_6->display(QString("55"));
    this->ui->label_6p->setText(QString("SG"));

    // Player 7
    this->ui->label_7->setText(QString("BILIBILI"));
    this->ui->lcdNumber_7->display(QString("55"));
    this->ui->label_7p->setText(QString("SG"));

    // Player 8
    this->ui->label_8->setText(QString("BILIBILI"));
    this->ui->lcdNumber_8->display(QString("55"));
    this->ui->label_8p->setText(QString("SG"));

    // Player 9
    this->ui->label_9->setText(QString("BILIBILI"));
    this->ui->lcdNumber_9->display(QString("55"));
    this->ui->label_9p->setText(QString("SG"));

    // Player 10
    this->ui->label_10->setText(QString("BILIBILI"));
    this->ui->lcdNumber_10->display(QString("55"));
    this->ui->label_10p->setText(QString("SG"));

    // Player 11
    this->ui->label_11->setText(QString("BILIBILI"));
    this->ui->lcdNumber_11->display(QString("55"));
    this->ui->label_11p->setText(QString("SG"));

    // Player 12
    this->ui->label_12->setText(QString("BILIBILI"));
    this->ui->lcdNumber_12->display(QString("55"));
    this->ui->label_12p->setText(QString("SG"));

    //Info tab
    QStringList header;
    header<<"surname"<<"Nationality"<<"Age"<<"Height"<<"Weight";
    this->ui->tableWidget->setColumnCount(5);
    this->ui->tableWidget->setRowCount(12);
    this->ui->tableWidget->setHorizontalHeaderLabels(header);

    for (int i = 0; i < 12; i++ ) {
    this->ui->tableWidget->setItem(i,0,new QTableWidgetItem("BILIBILI"));
    this->ui->tableWidget->setItem(i,1,new QTableWidgetItem((/*QIcon("images.png"), */"Country")));
    this->ui->tableWidget->setItem(i,2,new QTableWidgetItem("20"));
    this->ui->tableWidget->setItem(i,3,new QTableWidgetItem("190"));
    this->ui->tableWidget->setItem(i,4,new QTableWidgetItem("85"));
    }

    //Ability tab
    QStringList header2;
    header2<<"surname"<<"Nationality"<<"Age"<<"Height"<<"Weight";
    this->ui->tableWidget->setColumnCount(5);
    this->ui->tableWidget->setRowCount(12);
    this->ui->tableWidget->setHorizontalHeaderLabels(header2);

    for (int i = 0; i < 12; i++ ) {
    this->ui->tableWidget->setItem(i,0,new QTableWidgetItem("BILIBILI"));
    this->ui->tableWidget->setItem(i,1,new QTableWidgetItem((/*QIcon("images.png"), */"Country")));
    this->ui->tableWidget->setItem(i,2,new QTableWidgetItem("20"));
    this->ui->tableWidget->setItem(i,3,new QTableWidgetItem("190"));
    this->ui->tableWidget->setItem(i,4,new QTableWidgetItem("85"));
    }

    QStringList header3;
    header3<<"surname"<<"Nationality"<<"Age"<<"Height"<<"Weight";
    this->ui->tableWidget->setColumnCount(5);
    this->ui->tableWidget->setRowCount(12);
    this->ui->tableWidget->setHorizontalHeaderLabels(header3);

    for (int i = 0; i < 12; i++ ) {
    this->ui->tableWidget->setItem(i,0,new QTableWidgetItem("BILIBILI"));
    this->ui->tableWidget->setItem(i,1,new QTableWidgetItem((/*QIcon("images.png"), */"Country")));
    this->ui->tableWidget->setItem(i,2,new QTableWidgetItem("20"));
    this->ui->tableWidget->setItem(i,3,new QTableWidgetItem("190"));
    this->ui->tableWidget->setItem(i,4,new QTableWidgetItem("85"));
    }

    this->ui->tableWidget->show();
}

MainWindow::MainWindow(User& theuser ,League& A,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   //training= new Training(theuser,A);
    myuser=&theuser;
    myleague=&A;
    ui->setupUi(this);
    connect(calendar, SIGNAL(backButtonClicked()), this, SLOT(show()));
    connect(training, SIGNAL(backButtonClicked()), this, SLOT(show()));
    connect(teaminfo, SIGNAL(backButtonClicked()), this, SLOT(show()));

    // We may need a function to refresh the display
    // the function pack up all the operations on data below
    // the function may take the current game state as an argument
    team=theuser.team;

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
}
//Window operations
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //this -> hide();
    calendar= new Calendar(*myuser,*myleague);
    calendar -> show();
}

void MainWindow::on_pushButton_3_clicked()
{
    //this -> hide();
    training= new Training(*myuser,*myleague);
    std::cout<<"training created"<<std::endl;
    training -> show();
}


//void MainWindow::on_listView_indexesMoved(const QModelIndexList &indexes)
//{
//    listView = new QListView;
//}

void MainWindow::on_pushButton_4_clicked()
{
    this -> hide();
    teaminfo -> show();
}
