#include "preparation.h"
#include "ui_preparation.h"
#include <QMessageBox>
#include <iostream>

Preparation::Preparation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preparation)
{
    ui->setupUi(this);
}

Preparation::Preparation (User &theuser , League& league, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preparation)
{
    ui->setupUi(this);
    //this-> ui -> widget -> setStyleSheet("widget {border-image: url(:/images/images/background.jpeg)};");

    this->myuser = &theuser;
    this->myleague = &league;
    this->chosen_1 = -1;
    this->chosen_2 = -1;

    this->refresh(*myuser);

}
void Preparation::refresh(const User& theuser)
{
    std::cout<<"preparation start refresh"<<std::endl;

    if (theuser.team.players.size()>=1){
    // Player 1
    this->ui->label->setText(QString::fromStdString(theuser.team.players[0].surname));
    this->ui->lcdNumber->display(theuser.team.players[0].overallgeneral);
    this->ui->labelp->setText(QString::fromStdString(theuser.team.players[0].position));

        ui->progressBar->setRange(0, 100);
        ui->progressBar->setValue(theuser.team.players[0].energy);
    }
    else{
        this->ui->label->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber->display("-");
        this->ui->labelp->setText(QString::fromStdString("-"));

        ui->progressBar->setRange(0, 100);
        ui->progressBar->setValue(0);
    }

    // Player 2
    if (theuser.team.players.size()>=2){
    this->ui->label_2->setText(QString::fromStdString(theuser.team.players[1].surname));
    this->ui->lcdNumber_2->display(theuser.team.players[1].overallgeneral);
    this->ui->label_2p->setText(QString::fromStdString(theuser.team.players[1].position));

        ui->progressBar_2->setRange(0, 100);
        ui->progressBar_2->setValue(theuser.team.players[1].energy);
    }
    else{
        this->ui->label_2->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_2->display("-");
        this->ui->label_2p->setText(QString::fromStdString("-"));

        ui->progressBar_2->setRange(0, 100);
        ui->progressBar_2->setValue(0);
    }
    // Player 3
    if (theuser.team.players.size()>=3){
    this->ui->label_3->setText(QString::fromStdString(theuser.team.players[2].surname));
    this->ui->lcdNumber_3->display(theuser.team.players[2].overallgeneral);
    this->ui->label_3p->setText(QString::fromStdString(theuser.team.players[2].position));

        ui->progressBar_3->setRange(0, 100);
        ui->progressBar_3->setValue(theuser.team.players[2].energy);
    }
    else{
        this->ui->label_3->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_3->display("-");
        this->ui->label_3p->setText(QString::fromStdString("-"));

        ui->progressBar_3->setRange(0, 100);
        ui->progressBar_3->setValue(0);
    }
    // Player 4
    if (theuser.team.players.size()>=4){
    this->ui->label_4->setText(QString::fromStdString(theuser.team.players[3].surname));
    this->ui->lcdNumber_4->display(theuser.team.players[3].overallgeneral);
    this->ui->label_4p->setText(QString::fromStdString(theuser.team.players[3].position));

        ui->progressBar_4->setRange(0, 100);
        ui->progressBar_4->setValue(theuser.team.players[3].energy);
    }
    else{
        this->ui->label_4->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_4->display("-");
        this->ui->label_4p->setText(QString::fromStdString("-"));

        ui->progressBar_4->setRange(0, 100);
        ui->progressBar_4->setValue(0);
    }

    // Player 5
    if (theuser.team.players.size()>=5){
    this->ui->label_5->setText(QString::fromStdString(theuser.team.players[4].surname));
    this->ui->lcdNumber_5->display(theuser.team.players[4].overallgeneral);
    this->ui->label_5p->setText(QString::fromStdString(theuser.team.players[4].position));

        ui->progressBar_5->setRange(0, 100);
        ui->progressBar_5->setValue(theuser.team.players[4].energy);

    }
    else{
        this->ui->label_5->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_5->display("-");
        this->ui->label_5p->setText(QString::fromStdString("-"));

        ui->progressBar_5->setRange(0, 100);
        ui->progressBar_5->setValue(0);
    }

    // Player 6
    if (theuser.team.players.size()>=6){
    this->ui->label_6->setText(QString::fromStdString(theuser.team.players[5].surname));
    this->ui->lcdNumber_6->display(theuser.team.players[5].overallgeneral);
    this->ui->label_6p->setText(QString::fromStdString(theuser.team.players[5].position));

        ui->progressBar_6->setRange(0, 100);
        ui->progressBar_6->setValue(theuser.team.players[5].energy);

    }
    else{
        this->ui->label_6->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_6->display("-");
        this->ui->label_6p->setText(QString::fromStdString("-"));

        ui->progressBar_6->setRange(0, 100);
        ui->progressBar_6->setValue(0);
    }

    // Player 7
    if (theuser.team.players.size()>=7){
    this->ui->label_7->setText(QString::fromStdString(theuser.team.players[6].surname));
    this->ui->lcdNumber_7->display(theuser.team.players[6].overallgeneral);
    this->ui->label_7p->setText(QString::fromStdString(theuser.team.players[6].position));

        ui->progressBar_7->setRange(0, 100);
        ui->progressBar_7->setValue(theuser.team.players[6].energy);

    }
    else{
        this->ui->label_7->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_7->display("-");
        this->ui->label_7p->setText(QString::fromStdString("-"));

        ui->progressBar_7->setRange(0, 100);
        ui->progressBar_7->setValue(0);
    }

    // Player 8
    if (theuser.team.players.size()>=8){
    this->ui->label_8->setText(QString::fromStdString(theuser.team.players[7].surname));
    this->ui->lcdNumber_8->display(theuser.team.players[7].overallgeneral);
    this->ui->label_8p->setText(QString::fromStdString(theuser.team.players[7].position));

        ui->progressBar_8->setRange(0, 100);
        ui->progressBar_8->setValue(theuser.team.players[7].energy);

    }
    else{
        this->ui->label_8->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_8->display("-");
        this->ui->label_8p->setText(QString::fromStdString("-"));

        ui->progressBar_8->setRange(0, 100);
        ui->progressBar_8->setValue(0);
    }

    // Player 9
    if (theuser.team.players.size()>=9){
    this->ui->label_9->setText(QString::fromStdString(theuser.team.players[8].surname));
    this->ui->lcdNumber_9->display(theuser.team.players[8].overallgeneral);
    this->ui->label_9p->setText(QString::fromStdString(theuser.team.players[8].position));

        ui->progressBar_9->setRange(0, 100);
        ui->progressBar_9->setValue(theuser.team.players[8].energy);
    }
    else{
        this->ui->label_9->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_9->display("-");
        this->ui->label_9p->setText(QString::fromStdString("-"));

        ui->progressBar_9->setRange(0, 100);
        ui->progressBar_9->setValue(theuser.team.players[8].energy);
    }

    // Player 10
    if (theuser.team.players.size()>=10){
    this->ui->label_10->setText(QString::fromStdString(theuser.team.players[9].surname));
    this->ui->lcdNumber_10->display(theuser.team.players[9].overallgeneral);
    this->ui->label_10p->setText(QString::fromStdString(theuser.team.players[9].position));

        ui->progressBar_10->setRange(0, 100);
        ui->progressBar_10->setValue(theuser.team.players[9].energy);
    }
    else{
        this->ui->label_10->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_10->display("-");
        this->ui->label_10p->setText(QString::fromStdString("-"));

        ui->progressBar_10->setRange(0, 100);
        ui->progressBar_10->setValue(0);
    }

    // Player 11
    if (theuser.team.players.size()>=11){
    this->ui->label_11->setText(QString::fromStdString(theuser.team.players[10].surname));
    this->ui->lcdNumber_11->display(theuser.team.players[10].overallgeneral);
    this->ui->label_11p->setText(QString::fromStdString(theuser.team.players[10].position));

        ui->progressBar_11->setRange(0, 100);
        ui->progressBar_11->setValue(theuser.team.players[10].energy);
    }
    else{
        this->ui->label_11->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_11->display("-");
        this->ui->label_11p->setText(QString::fromStdString("-"));

        ui->progressBar_11->setRange(0, 100);
        ui->progressBar_11->setValue(0);
    }

    // Player 12
    if (theuser.team.players.size()>=12){
    this->ui->label_12->setText(QString::fromStdString(theuser.team.players[11].surname));
    this->ui->lcdNumber_12->display(theuser.team.players[11].overallgeneral);
    this->ui->label_12p->setText(QString::fromStdString(theuser.team.players[11].position));

        ui->progressBar_12->setRange(0, 100);
        ui->progressBar_12->setValue(theuser.team.players[11].energy);
    }
    else{
        this->ui->label_12->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_12->display("-");
        this->ui->label_12p->setText(QString::fromStdString("-"));

        ui->progressBar_12->setRange(0, 100);
        ui->progressBar_12->setValue(0);
    }

    std::cout<<"preparation refreshed"<<std::endl;
}

Preparation::~Preparation()
{
    delete ui;
}

void Preparation::Substitution()
{
    if (this->chosen_1 == -1 || this->chosen_2 == -1)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You have to choose two players to make substitution",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else
    {
        int ind_1 = this->chosen_1;
        int ind_2 = this->chosen_2;
        Player temp = this->myuser->team.players[ind_1];
        this->myuser->team.players[ind_1] = this->myuser->team.players[ind_2];
        this->myuser->team.players[ind_2] = temp;
        std::cout<<ind_1<<std::endl;
        std::cout<<ind_2<<std::endl;
        this->chosen_1 = -1;
        this->chosen_2 = -1;
        this->ui->label_p1->setText(QString::fromStdString("Player 1"));
        this->ui->label_p2->setText(QString::fromStdString("Player 2"));
        this->refresh(*(this->myuser));
    }
}

void Preparation::on_pushButton_15_clicked() //Back Button
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want leave? All changes will be recorded.",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            emit backButtonClicked(*(this->myuser));
            std::cout<<"signal emitted"<<std::endl;
            this -> close();
        }
        else if (reply == QMessageBox::No)
        {}
}

void Preparation::on_pushButton_14_clicked() //Next Game
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to go to the next game?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            this -> close();
            this->nextgame = new NextGame;
            nextgame -> show();
        }
        else if (reply == QMessageBox::No)
        {}
}

void Preparation::on_pushButton_13_clicked() // Change Button
{
    Substitution();
}

void Preparation::on_p1_clicked() // Choose Player 1
{
    int index = 0;
    if (this->chosen_1 != -1 &&  this->chosen_2 != -1 && this->chosen_1 != index && this->chosen_2 != index)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You can only choose two players",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else if (this->myuser->team.players.size()<1)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "Obviously, you can't choose an emply spot",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }

    else if (this->chosen_1 == -1 &&  this->chosen_2 != index)
    {
        this->chosen_1 = index;
        this->ui->label_p1->setText(QString::fromStdString(this->myuser->team.players[this->chosen_1].surname));
    }
    else if (this->chosen_1 != -1 &&  this->chosen_1 != index && this->chosen_2 == -1)
    {
        this->chosen_2 = index;
        this->ui->label_p2->setText(QString::fromStdString(this->myuser->team.players[this->chosen_2].surname));
    }
    else if (this->chosen_1 == index)
    {
        this->chosen_1 = -1;
        this->ui->label_p1->setText(QString::fromStdString("Player 1"));
    }
    else if (this->chosen_1 != index && this->chosen_2 == index)
    {
        this->chosen_2 = -1;
        this->ui->label_p2->setText(QString::fromStdString("Player 2"));
    }
}

void Preparation::on_p2_clicked() // Choose Player 2
{
    int index = 1;
    if (this->chosen_1 != -1 &&  this->chosen_2 != -1 && this->chosen_1 != index && this->chosen_2 != index)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You can only choose two players",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else if (this->myuser->team.players.size()<2)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "Obviously, you can't choose an emply spot",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }

    else if (this->chosen_1 == -1 &&  this->chosen_2 != index)
    {
        this->chosen_1 = index;
        this->ui->label_p1->setText(QString::fromStdString(this->myuser->team.players[this->chosen_1].surname));
    }
    else if (this->chosen_1 != -1 &&  this->chosen_1 != index && this->chosen_2 == -1)
    {
        this->chosen_2 = index;
        this->ui->label_p2->setText(QString::fromStdString(this->myuser->team.players[this->chosen_2].surname));
    }
    else if (this->chosen_1 == index)
    {
        this->chosen_1 = -1;
        this->ui->label_p1->setText(QString::fromStdString("Player 1"));
    }
    else if (this->chosen_1 != index && this->chosen_2 == index)
    {
        this->chosen_2 = -1;
        this->ui->label_p2->setText(QString::fromStdString("Player 2"));
    }
}

void Preparation::on_p3_clicked() // Choose Player 3
{
    int index = 2;
    if (this->chosen_1 != -1 &&  this->chosen_2 != -1 && this->chosen_1 != index && this->chosen_2 != index)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You can only choose two players",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else if (this->myuser->team.players.size()<3)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "Obviously, you can't choose an emply spot",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }

    else if (this->chosen_1 == -1 &&  this->chosen_2 != index)
    {
        this->chosen_1 = index;
        this->ui->label_p1->setText(QString::fromStdString(this->myuser->team.players[this->chosen_1].surname));
    }
    else if (this->chosen_1 != -1 &&  this->chosen_1 != index && this->chosen_2 == -1)
    {
        this->chosen_2 = index;
        this->ui->label_p2->setText(QString::fromStdString(this->myuser->team.players[this->chosen_2].surname));
    }
    else if (this->chosen_1 == index)
    {
        this->chosen_1 = -1;
        this->ui->label_p1->setText(QString::fromStdString("Player 1"));
    }
    else if (this->chosen_1 != index && this->chosen_2 == index)
    {
        this->chosen_2 = -1;
        this->ui->label_p2->setText(QString::fromStdString("Player 2"));
    }
}

void Preparation::on_p4_clicked() // Choose Player 4
{
    int index = 3;
    if (this->chosen_1 != -1 &&  this->chosen_2 != -1 && this->chosen_1 != index && this->chosen_2 != index)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You can only choose two players",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else if (this->myuser->team.players.size()<4)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "Obviously, you can't choose an emply spot",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }

    else if (this->chosen_1 == -1 &&  this->chosen_2 != index)
    {
        this->chosen_1 = index;
        this->ui->label_p1->setText(QString::fromStdString(this->myuser->team.players[this->chosen_1].surname));
    }
    else if (this->chosen_1 != -1 &&  this->chosen_1 != index && this->chosen_2 == -1)
    {
        this->chosen_2 = index;
        this->ui->label_p2->setText(QString::fromStdString(this->myuser->team.players[this->chosen_2].surname));
    }
    else if (this->chosen_1 == index)
    {
        this->chosen_1 = -1;
        this->ui->label_p1->setText(QString::fromStdString("Player 1"));
    }
    else if (this->chosen_1 != index && this->chosen_2 == index)
    {
        this->chosen_2 = -1;
        this->ui->label_p2->setText(QString::fromStdString("Player 2"));
    }
}

void Preparation::on_p5_clicked() // Choose Player 5
{
    int index = 4;
    if (this->chosen_1 != -1 &&  this->chosen_2 != -1 && this->chosen_1 != index && this->chosen_2 != index)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You can only choose two players",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else if (this->myuser->team.players.size()<5)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "Obviously, you can't choose an emply spot",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }

    else if (this->chosen_1 == -1 &&  this->chosen_2 != index)
    {
        this->chosen_1 = index;
        this->ui->label_p1->setText(QString::fromStdString(this->myuser->team.players[this->chosen_1].surname));
    }
    else if (this->chosen_1 != -1 &&  this->chosen_1 != index && this->chosen_2 == -1)
    {
        this->chosen_2 = index;
        this->ui->label_p2->setText(QString::fromStdString(this->myuser->team.players[this->chosen_2].surname));
    }
    else if (this->chosen_1 == index)
    {
        this->chosen_1 = -1;
        this->ui->label_p1->setText(QString::fromStdString("Player 1"));
    }
    else if (this->chosen_1 != index && this->chosen_2 == index)
    {
        this->chosen_2 = -1;
        this->ui->label_p2->setText(QString::fromStdString("Player 2"));
    }
}

void Preparation::on_p6_clicked() // Choose Player 6
{
    int index = 5;
    if (this->chosen_1 != -1 &&  this->chosen_2 != -1 && this->chosen_1 != index && this->chosen_2 != index)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You can only choose two players",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else if (this->myuser->team.players.size()<6)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "Obviously, you can't choose an emply spot",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }

    else if (this->chosen_1 == -1 &&  this->chosen_2 != index)
    {
        this->chosen_1 = index;
        this->ui->label_p1->setText(QString::fromStdString(this->myuser->team.players[this->chosen_1].surname));
    }
    else if (this->chosen_1 != -1 &&  this->chosen_1 != index && this->chosen_2 == -1)
    {
        this->chosen_2 = index;
        this->ui->label_p2->setText(QString::fromStdString(this->myuser->team.players[this->chosen_2].surname));
    }
    else if (this->chosen_1 == index)
    {
        this->chosen_1 = -1;
        this->ui->label_p1->setText(QString::fromStdString("Player 1"));
    }
    else if (this->chosen_1 != index && this->chosen_2 == index)
    {
        this->chosen_2 = -1;
        this->ui->label_p2->setText(QString::fromStdString("Player 2"));
    }
}

void Preparation::on_p7_clicked() // Choose Player 7
{
    int index = 6;
    if (this->chosen_1 != -1 &&  this->chosen_2 != -1 && this->chosen_1 != index && this->chosen_2 != index)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You can only choose two players",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else if (this->myuser->team.players.size()<7)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "Obviously, you can't choose an emply spot",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }

    else if (this->chosen_1 == -1 &&  this->chosen_2 != index)
    {
        this->chosen_1 = index;
        this->ui->label_p1->setText(QString::fromStdString(this->myuser->team.players[this->chosen_1].surname));
    }
    else if (this->chosen_1 != -1 &&  this->chosen_1 != index && this->chosen_2 == -1)
    {
        this->chosen_2 = index;
        this->ui->label_p2->setText(QString::fromStdString(this->myuser->team.players[this->chosen_2].surname));
    }
    else if (this->chosen_1 == index)
    {
        this->chosen_1 = -1;
        this->ui->label_p1->setText(QString::fromStdString("Player 1"));
    }
    else if (this->chosen_1 != index && this->chosen_2 == index)
    {
        this->chosen_2 = -1;
        this->ui->label_p2->setText(QString::fromStdString("Player 2"));
    }
}

void Preparation::on_p8_clicked() // Choose Player 8
{
    int index = 7;
    if (this->chosen_1 != -1 &&  this->chosen_2 != -1 && this->chosen_1 != index && this->chosen_2 != index)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You can only choose two players",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else if (this->myuser->team.players.size()<8)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "Obviously, you can't choose an emply spot",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }

    else if (this->chosen_1 == -1 &&  this->chosen_2 != index)
    {
        this->chosen_1 = index;
        this->ui->label_p1->setText(QString::fromStdString(this->myuser->team.players[this->chosen_1].surname));
    }
    else if (this->chosen_1 != -1 &&  this->chosen_1 != index && this->chosen_2 == -1)
    {
        this->chosen_2 = index;
        this->ui->label_p2->setText(QString::fromStdString(this->myuser->team.players[this->chosen_2].surname));
    }
    else if (this->chosen_1 == index)
    {
        this->chosen_1 = -1;
        this->ui->label_p1->setText(QString::fromStdString("Player 1"));
    }
    else if (this->chosen_1 != index && this->chosen_2 == index)
    {
        this->chosen_2 = -1;
        this->ui->label_p2->setText(QString::fromStdString("Player 2"));
    }
}

void Preparation::on_p9_clicked() // Choose Player 9
{
    int index = 8;
    if (this->chosen_1 != -1 &&  this->chosen_2 != -1 && this->chosen_1 != index && this->chosen_2 != index)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You can only choose two players",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else if (this->myuser->team.players.size()<9)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "Obviously, you can't choose an emply spot",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }

    else if (this->chosen_1 == -1 &&  this->chosen_2 != index)
    {
        this->chosen_1 = index;
        this->ui->label_p1->setText(QString::fromStdString(this->myuser->team.players[this->chosen_1].surname));
    }
    else if (this->chosen_1 != -1 &&  this->chosen_1 != index && this->chosen_2 == -1)
    {
        this->chosen_2 = index;
        this->ui->label_p2->setText(QString::fromStdString(this->myuser->team.players[this->chosen_2].surname));
    }
    else if (this->chosen_1 == index)
    {
        this->chosen_1 = -1;
        this->ui->label_p1->setText(QString::fromStdString("Player 1"));
    }
    else if (this->chosen_1 != index && this->chosen_2 == index)
    {
        this->chosen_2 = -1;
        this->ui->label_p2->setText(QString::fromStdString("Player 2"));
    }
}

void Preparation::on_p10_clicked() // Choose Player 10
{
    int index = 9;
    if (this->chosen_1 != -1 &&  this->chosen_2 != -1 && this->chosen_1 != index && this->chosen_2 != index)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You can only choose two players",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else if (this->myuser->team.players.size()<10)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "Obviously, you can't choose an emply spot",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }

    else if (this->chosen_1 == -1 &&  this->chosen_2 != index)
    {
        this->chosen_1 = index;
        this->ui->label_p1->setText(QString::fromStdString(this->myuser->team.players[this->chosen_1].surname));
    }
    else if (this->chosen_1 != -1 &&  this->chosen_1 != index && this->chosen_2 == -1)
    {
        this->chosen_2 = index;
        this->ui->label_p2->setText(QString::fromStdString(this->myuser->team.players[this->chosen_2].surname));
    }
    else if (this->chosen_1 == index)
    {
        this->chosen_1 = -1;
        this->ui->label_p1->setText(QString::fromStdString("Player 1"));
    }
    else if (this->chosen_1 != index && this->chosen_2 == index)
    {
        this->chosen_2 = -1;
        this->ui->label_p2->setText(QString::fromStdString("Player 2"));
    }
}

void Preparation::on_p11_clicked() // Choose Player 11
{
    int index = 10;
    if (this->chosen_1 != -1 &&  this->chosen_2 != -1 && this->chosen_1 != index && this->chosen_2 != index)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You can only choose two players",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else if (this->myuser->team.players.size()<11)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "Obviously, you can't choose an emply spot",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }

    else if (this->chosen_1 == -1 &&  this->chosen_2 != index)
    {
        this->chosen_1 = index;
        this->ui->label_p1->setText(QString::fromStdString(this->myuser->team.players[this->chosen_1].surname));
    }
    else if (this->chosen_1 != -1 &&  this->chosen_1 != index && this->chosen_2 == -1)
    {
        this->chosen_2 = index;
        this->ui->label_p2->setText(QString::fromStdString(this->myuser->team.players[this->chosen_2].surname));
    }
    else if (this->chosen_1 == index)
    {
        this->chosen_1 = -1;
        this->ui->label_p1->setText(QString::fromStdString("Player 1"));
    }
    else if (this->chosen_1 != index && this->chosen_2 == index)
    {
        this->chosen_2 = -1;
        this->ui->label_p2->setText(QString::fromStdString("Player 2"));
    }
}

void Preparation::on_p12_clicked() // Choose Player 12
{
    int index = 11;
    if (this->chosen_1 != -1 &&  this->chosen_2 != -1 && this->chosen_1 != index && this->chosen_2 != index)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "You can only choose two players",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }
    else if (this->myuser->team.players.size()<12)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, tr("QMessageBox::warning()"),
                                            "Obviously, you can't choose an emply spot",
                                            QMessageBox::Cancel);
            if (reply == QMessageBox::Cancel)
            {}
    }

    else if (this->chosen_1 == -1 &&  this->chosen_2 != index)
    {
        this->chosen_1 = index;
        this->ui->label_p1->setText(QString::fromStdString(this->myuser->team.players[this->chosen_1].surname));
    }
    else if (this->chosen_1 != -1 &&  this->chosen_1 != index && this->chosen_2 == -1)
    {
        this->chosen_2 = index;
        this->ui->label_p2->setText(QString::fromStdString(this->myuser->team.players[this->chosen_2].surname));
    }
    else if (this->chosen_1 == index)
    {
        this->chosen_1 = -1;
        this->ui->label_p1->setText(QString::fromStdString("Player 1"));
    }
    else if (this->chosen_1 != index && this->chosen_2 == index)
    {
        this->chosen_2 = -1;
        this->ui->label_p2->setText(QString::fromStdString("Player 2"));
    }
}
