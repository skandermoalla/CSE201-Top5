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
        {
            this -> hide();
        }


}

void Training::on_pushButton_2_clicked()
{
  myuser->budget-=8000;
  myuser->team.Training2();
  this->hide();

}

void Training::on_pushButton_3_clicked()
{   myuser->budget-=7000;
    myuser->team.Training3();
    this->hide();

}

void Training::on_pushButton_4_clicked()
{   myuser->budget-=10000;
    myuser->team.Training4();
    this->hide();
}

//Defense training
void Training::on_pushButton_clicked()
{   myuser->budget-=5000;
    myuser->team.Training1();
    this->hide();

}

void Training::on_pushButton_2_clicked()
{
  myuser->budget-=8000;
  myuser->team.Training2();
  this->hide();

}

void Training::on_pushButton_3_clicked()
{   myuser->budget-=7000;
    myuser->team.Training3();
    this->hide();

}

void Training::on_pushButton_4_clicked()
{   myuser->budget-=10000;
    myuser->team.Training4();
    this->hide();
}
