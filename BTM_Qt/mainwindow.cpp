#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <iostream>

MainWindow::MainWindow(User& theuser ,League& A,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->myuser=&theuser;
    this->myleague=&A;
    this->team=theuser.team;
    this->ui->setupUi(this);
    this->refresh(*myuser);
    //training= new Training(theuser,A);
    //this->calendar = new Calendar();
    //this->market= new Market();
    this->teaminfo = new TeamInfo();
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

    if (theuser.team.players.size()>=1){
    // Player 1
    this->ui->label->setText(QString::fromStdString(theuser.team.players[0].surname));
    this->ui->lcdNumber->display(theuser.team.players[0].overallgeneral);
    this->ui->labelp->setText(QString::fromStdString(theuser.team.players[0].position));
    // Image Player 1
    QPixmap im1(theuser.team.players[0].photoadress);
    this->ui->image_1->setPixmap(im1);
    this->ui->image_1->setScaledContents(true);
    this->ui->image_1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber->display("-");
        this->ui->labelp->setText(QString::fromStdString("-"));
        this->ui->image_1->setText(QString::fromStdString("        NO PICTURE "));

    }
    if (theuser.team.players.size()>=2){
    // Player 2
    this->ui->label_2->setText(QString::fromStdString(theuser.team.players[1].surname));
    this->ui->lcdNumber_2->display(theuser.team.players[1].overallgeneral);
    this->ui->label_2p->setText(QString::fromStdString(theuser.team.players[1].position));
    QPixmap im1(theuser.team.players[1].photoadress);
    this->ui->image_2->setPixmap(im1);
    this->ui->image_2->setScaledContents(true);
    this->ui->image_2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_2->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_2->display("-");
        this->ui->label_2p->setText(QString::fromStdString("-"));
        this->ui->image_2->setText(QString::fromStdString("        NO PICTURE "));
    }
    // Player 3
    if (theuser.team.players.size()>=3){
    this->ui->label_3->setText(QString::fromStdString(theuser.team.players[2].surname));
    this->ui->lcdNumber_3->display(theuser.team.players[2].overallgeneral);
    this->ui->label_3p->setText(QString::fromStdString(theuser.team.players[2].position));
        QPixmap im1(theuser.team.players[2].photoadress);
        this->ui->image_3->setPixmap(im1);
        this->ui->image_3->setScaledContents(true);
        this->ui->image_3->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_3->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_3->display("-");
        this->ui->label_3p->setText(QString::fromStdString("-"));
        this->ui->image_3->setText(QString::fromStdString("        NO PICTURE "));
    }
    // Player 4
    if (theuser.team.players.size()>=4){
    this->ui->label_4->setText(QString::fromStdString(theuser.team.players[3].surname));
    this->ui->lcdNumber_4->display(theuser.team.players[3].overallgeneral);
    this->ui->label_4p->setText(QString::fromStdString(theuser.team.players[3].position));
        QPixmap im1(theuser.team.players[3].photoadress);
        this->ui->image_4->setPixmap(im1);
        this->ui->image_4->setScaledContents(true);
        this->ui->image_4->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_4->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_4->display("-");
        this->ui->label_4p->setText(QString::fromStdString("-"));
        this->ui->image_4->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 5
    if (theuser.team.players.size()>=5){
    this->ui->label_5->setText(QString::fromStdString(theuser.team.players[4].surname));
    this->ui->lcdNumber_5->display(theuser.team.players[4].overallgeneral);
    this->ui->label_5p->setText(QString::fromStdString(theuser.team.players[4].position));
        QPixmap im1(theuser.team.players[4].photoadress);
        this->ui->image_5->setPixmap(im1);
        this->ui->image_5->setScaledContents(true);
        this->ui->image_5->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_5->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_5->display("-");
        this->ui->label_5p->setText(QString::fromStdString("-"));
        this->ui->image_5->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 6
    if (theuser.team.players.size()>=6){
    this->ui->label_6->setText(QString::fromStdString(theuser.team.players[5].surname));
    this->ui->lcdNumber_6->display(theuser.team.players[5].overallgeneral);
    this->ui->label_6p->setText(QString::fromStdString(theuser.team.players[5].position));
        QPixmap im1(theuser.team.players[5].photoadress);
        this->ui->image_6->setPixmap(im1);
        this->ui->image_6->setScaledContents(true);
        this->ui->image_6->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_6->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_6->display("-");
        this->ui->label_6p->setText(QString::fromStdString("-"));
        this->ui->image_6->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 7
    if (theuser.team.players.size()>=7){
    this->ui->label_7->setText(QString::fromStdString(theuser.team.players[6].surname));
    this->ui->lcdNumber_7->display(theuser.team.players[6].overallgeneral);
    this->ui->label_7p->setText(QString::fromStdString(theuser.team.players[6].position));
        QPixmap im1(theuser.team.players[6].photoadress);
        this->ui->image_7->setPixmap(im1);
        this->ui->image_7->setScaledContents(true);
        this->ui->image_7->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    }
    else{
        this->ui->label_7->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_7->display("-");
        this->ui->label_7p->setText(QString::fromStdString("-"));
        this->ui->image_7->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 8
    if (theuser.team.players.size()>=8){
    this->ui->label_8->setText(QString::fromStdString(theuser.team.players[7].surname));
    this->ui->lcdNumber_8->display(theuser.team.players[7].overallgeneral);
    this->ui->label_8p->setText(QString::fromStdString(theuser.team.players[7].position));
        QPixmap im1(theuser.team.players[7].photoadress);
        this->ui->image_8->setPixmap(im1);
        this->ui->image_8->setScaledContents(true);
        this->ui->image_8->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_8->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_8->display("-");
        this->ui->label_8p->setText(QString::fromStdString("-"));
        this->ui->image_8->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 9
    if (theuser.team.players.size()>=9){
    this->ui->label_9->setText(QString::fromStdString(theuser.team.players[8].surname));
    this->ui->lcdNumber_9->display(theuser.team.players[8].overallgeneral);
    this->ui->label_9p->setText(QString::fromStdString(theuser.team.players[8].position));
        QPixmap im1(theuser.team.players[8].photoadress);
        this->ui->image_9->setPixmap(im1);
        this->ui->image_9->setScaledContents(true);
        this->ui->image_9->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_9->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_9->display("-");
        this->ui->label_9p->setText(QString::fromStdString("-"));
        this->ui->image_9->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 10
    if (theuser.team.players.size()>=10){
    this->ui->label_10->setText(QString::fromStdString(theuser.team.players[9].surname));
    this->ui->lcdNumber_10->display(theuser.team.players[9].overallgeneral);
    this->ui->label_10p->setText(QString::fromStdString(theuser.team.players[9].position));
        QPixmap im1(theuser.team.players[9].photoadress);
        this->ui->image_10->setPixmap(im1);
        this->ui->image_10->setScaledContents(true);
        this->ui->image_10->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_10->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_10->display("-");
        this->ui->label_10p->setText(QString::fromStdString("-"));
        this->ui->image_10->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 11
    if (theuser.team.players.size()>=11){
    this->ui->label_11->setText(QString::fromStdString(theuser.team.players[10].surname));
    this->ui->lcdNumber_11->display(theuser.team.players[10].overallgeneral);
    this->ui->label_11p->setText(QString::fromStdString(theuser.team.players[10].position));
        QPixmap im1(theuser.team.players[10].photoadress);
        this->ui->image_11->setPixmap(im1);
        this->ui->image_11->setScaledContents(true);
        this->ui->image_11->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_11->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_11->display("-");
        this->ui->label_11p->setText(QString::fromStdString("-"));
        this->ui->image_11->setText(QString::fromStdString("        NO PICTURE "));
    }

    // Player 12
    if (theuser.team.players.size()>=12){
    this->ui->label_12->setText(QString::fromStdString(theuser.team.players[11].surname));
    this->ui->lcdNumber_12->display(theuser.team.players[11].overallgeneral);
    this->ui->label_12p->setText(QString::fromStdString(theuser.team.players[11].position));
        QPixmap im1(theuser.team.players[11].photoadress);
        this->ui->image_12->setPixmap(im1);
        this->ui->image_12->setScaledContents(true);
        this->ui->image_12->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else{
        this->ui->label_12->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_12->display("-");
        this->ui->label_12p->setText(QString::fromStdString("-"));
        this->ui->image_12->setText(QString::fromStdString("        NO PICTURE "));
}
    //Energy tab
    QStringList header;
    header<<"surname"<<"Energy"<<"Motivation";
    this->ui->tableWidget_3->setColumnCount(3);
    this->ui->tableWidget_3->setRowCount(theuser.team.players.size());
    this->ui->tableWidget_3->setHorizontalHeaderLabels(header);

    for (int i = 0; i < theuser.team.players.size(); i++ ) {
    this->ui->tableWidget_3->setItem(i,0,new QTableWidgetItem(QString::fromStdString(theuser.team.players[i].surname)));
    this->ui->tableWidget_3->setItem(i,1,new QTableWidgetItem(QString::number(theuser.team.players[i].energy)));
    this->ui->tableWidget_3->setItem(i,2,new QTableWidgetItem(QString::number(theuser.team.players[i].motivation)));
    }
    this->ui->tableWidget_3->show();

    //Ability tab
    QStringList header2;
    header2<<"surname"<<"Overall"<<"Offense"<<"Defense";
    this->ui->tableWidget_2->setColumnCount(4);
    this->ui->tableWidget_2->setRowCount(theuser.team.players.size());
    this->ui->tableWidget_2->setHorizontalHeaderLabels(header2);

    for (int i = 0; i < theuser.team.players.size(); i++ ) {
    this->ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(QString::fromStdString(theuser.team.players[i].surname)));
    this->ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::number(theuser.team.players[i].overallgeneral)));
    this->ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(QString::number(theuser.team.players[i].attack)));
    this->ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(QString::number(theuser.team.players[i].defence)));
    }
    this->ui->tableWidget_2->show();

    QStringList header3;
    header3<<"Surname"<<"Nationality"<<"Age"<<"Height"<<"Weight";
    this->ui->tableWidget->setColumnCount(5);
    this->ui->tableWidget->setRowCount(theuser.team.players.size());
    this->ui->tableWidget->setHorizontalHeaderLabels(header3);

    for (int i = 0; i < theuser.team.players.size(); i++ ) {
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
    calendar= new Calendar(*myuser,*myleague);
    connect(this->calendar, SIGNAL(backButtonClicked(User)), this, SLOT(show()));
    connect(this->calendar, SIGNAL(backButtonClicked(User)), this, SLOT(refresh(User)));
    calendar -> show();
}

//market
void MainWindow::on_pushButton_2_clicked()
{
    this -> hide();
    market= new Market(*myuser,*myleague);
    connect(this->market, SIGNAL(backButtonClicked(User)), this, SLOT(show()));
    connect(this->market, SIGNAL(backButtonClicked(User)), this, SLOT(refresh(User)));
    market -> show();
}

//training
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

void MainWindow::on_pushButton_5_clicked() // Next game
{
    this -> hide();
    this->preparation=new Preparation(*myuser,*myleague);
    connect(this->preparation, SIGNAL(backButtonClicked(User)), this, SLOT(show()));
    connect(this->preparation, SIGNAL(backButtonClicked(User)), this, SLOT(refresh(User)));
    preparation ->show();
}
