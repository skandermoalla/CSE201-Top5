#include "training.h"
#include "ui_training.h"
#include <iostream>
#include <QMessageBox>

Training::Training(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Training)
{
    ui->setupUi(this);

}

Training::Training(User &theuser , League& league, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Training)
{
    ui->setupUi(this);
    myuser = &theuser;
    myleague = &league;

    if (theuser.team.players.size()>=1){
    // Player 1
    this->ui->label->setText(QString::fromStdString(theuser.team.players[0].surname));
    this->ui->lcdNumber->display(theuser.team.players[0].overallgeneral);
    this->ui->labelp->setText(QString::fromStdString(theuser.team.players[0].position));
    }
    else{
        this->ui->label->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber->display("-");
        this->ui->labelp->setText(QString::fromStdString("-"));
    }
    if (theuser.team.players.size()>=2){
    // Player 2
    this->ui->label_2->setText(QString::fromStdString(theuser.team.players[1].surname));
    this->ui->lcdNumber_2->display(theuser.team.players[1].overallgeneral);
    this->ui->label_2p->setText(QString::fromStdString(theuser.team.players[1].position));
    }
    else{
        this->ui->label_2->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_2->display("-");
        this->ui->label_2p->setText(QString::fromStdString("-"));
    }
    // Player 3
    if (theuser.team.players.size()>=3){
    this->ui->label_3->setText(QString::fromStdString(theuser.team.players[2].surname));
    this->ui->lcdNumber_3->display(theuser.team.players[2].overallgeneral);
    this->ui->label_3p->setText(QString::fromStdString(theuser.team.players[2].position));
    }
    else{
        this->ui->label_3->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_3->display("-");
        this->ui->label_3p->setText(QString::fromStdString("-"));
    }
    // Player 4
    if (theuser.team.players.size()>=4){
    this->ui->label_4->setText(QString::fromStdString(theuser.team.players[3].surname));
    this->ui->lcdNumber_4->display(theuser.team.players[3].overallgeneral);
    this->ui->label_4p->setText(QString::fromStdString(theuser.team.players[3].position));
    }
    else{
        this->ui->label_4->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_4->display("-");
        this->ui->label_4p->setText(QString::fromStdString("-"));
    }

    // Player 5
    if (theuser.team.players.size()>=5){
    this->ui->label_5->setText(QString::fromStdString(theuser.team.players[3].surname));
    this->ui->lcdNumber_5->display(theuser.team.players[3].overallgeneral);
    this->ui->label_5p->setText(QString::fromStdString(theuser.team.players[3].position));
    }
    else{
        this->ui->label_5->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_5->display("-");
        this->ui->label_5p->setText(QString::fromStdString("-"));
    }

    // Player 6
    if (theuser.team.players.size()>=6){
    this->ui->label_6->setText(QString::fromStdString(theuser.team.players[5].surname));
    this->ui->lcdNumber_6->display(theuser.team.players[5].overallgeneral);
    this->ui->label_6p->setText(QString::fromStdString(theuser.team.players[5].position));
    }
    else{
        this->ui->label_6->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_6->display("-");
        this->ui->label_6p->setText(QString::fromStdString("-"));
    }

    // Player 7
    if (theuser.team.players.size()>=7){
    this->ui->label_7->setText(QString::fromStdString(theuser.team.players[6].surname));
    this->ui->lcdNumber_7->display(theuser.team.players[6].overallgeneral);
    this->ui->label_7p->setText(QString::fromStdString(theuser.team.players[6].position));
    }
    else{
        this->ui->label_7->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_7->display("-");
        this->ui->label_7p->setText(QString::fromStdString("-"));
    }

    // Player 8
    if (theuser.team.players.size()>=8){
    this->ui->label_8->setText(QString::fromStdString(theuser.team.players[7].surname));
    this->ui->lcdNumber_8->display(theuser.team.players[7].overallgeneral);
    this->ui->label_8p->setText(QString::fromStdString(theuser.team.players[7].position));
    }
    else{
        this->ui->label_8->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_8->display("-");
        this->ui->label_8p->setText(QString::fromStdString("-"));
    }

    // Player 9
    if (theuser.team.players.size()>=9){
    this->ui->label_9->setText(QString::fromStdString(theuser.team.players[8].surname));
    this->ui->lcdNumber_9->display(theuser.team.players[8].overallgeneral);
    this->ui->label_9p->setText(QString::fromStdString(theuser.team.players[8].position));
    }
    else{
        this->ui->label_9->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_9->display("-");
        this->ui->label_9p->setText(QString::fromStdString("-"));
    }

    // Player 10
    if (theuser.team.players.size()>=10){
    this->ui->label_10->setText(QString::fromStdString(theuser.team.players[9].surname));
    this->ui->lcdNumber_10->display(theuser.team.players[9].overallgeneral);
    this->ui->label_10p->setText(QString::fromStdString(theuser.team.players[9].position));
    }
    else{
        this->ui->label_10->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_10->display("-");
        this->ui->label_10p->setText(QString::fromStdString("-"));
    }

    // Player 11
    if (theuser.team.players.size()>=11){
    this->ui->label_11->setText(QString::fromStdString(theuser.team.players[10].surname));
    this->ui->lcdNumber_11->display(theuser.team.players[10].overallgeneral);
    this->ui->label_11p->setText(QString::fromStdString(theuser.team.players[10].position));
    }
    else{
        this->ui->label_11->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_11->display("-");
        this->ui->label_11p->setText(QString::fromStdString("-"));
    }

    // Player 12
    if (theuser.team.players.size()>=12){
    this->ui->label_12->setText(QString::fromStdString(theuser.team.players[11].surname));
    this->ui->lcdNumber_12->display(theuser.team.players[11].overallgeneral);
    this->ui->label_12p->setText(QString::fromStdString(theuser.team.players[11].position));
    }
    else{
        this->ui->label_12->setText(QString::fromStdString("NO PLAYER"));
        this->ui->lcdNumber_12->display("-");
        this->ui->label_12p->setText(QString::fromStdString("-"));
    }


    // Budget Display
    this->ui->lcdNumber_16->display(theuser.budget);


    // Energy Left Display
    this->ui->lcdNumber_13->display(theuser.team.energy);
}



Training::~Training()
{
    delete ui;
}

void Training::on_pushButton_5_clicked()
{
    emit backButtonClicked(*(this->myuser));
    std::cout<<"signal emitted"<<std::endl;
    this -> hide();
}

//Defense training
void Training::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to take this training?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            myuser->budget-=5000;
            myuser->team.Training1();
            emit backButtonClicked(*(this->myuser));
            std::cout<<"signal emitted"<<std::endl;
            this -> hide();
        }
        else if (reply == QMessageBox::No)
        {   //uncomment this if you want 'no' to send you to the mainwindw
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }


}
//second training
void Training::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to take this training?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            myuser->budget-=8000;
            myuser->team.Training2();
            emit backButtonClicked(*(this->myuser));
            std::cout<<"signal emitted"<<std::endl;
            this -> hide();
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

//third training
void Training::on_pushButton_3_clicked()
{   QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to take this training?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            myuser->budget-=7000;
            myuser->team.Training3();
            emit backButtonClicked(*(this->myuser));
            std::cout<<"signal emitted"<<std::endl;
            this -> hide();
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }

}
//fourth training
void Training::on_pushButton_4_clicked()
{   QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to take this training?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            myuser->budget-=10000;
            myuser->team.Training4();
            emit backButtonClicked(*(this->myuser));
            std::cout<<"signal emitted"<<std::endl;
            this -> hide();
        }
        else if (reply == QMessageBox::No)
        {
            //this -> hide();
            //emit backButtonClicked(*(this->myuser));
        }
}

