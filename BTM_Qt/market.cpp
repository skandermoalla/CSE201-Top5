#include "market.h"
#include "ui_market.h"

Market::Market(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Market)
{
    ui->setupUi(this);
}
Market::Market(User& theuser, League& theleague , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Market)
{
    ui->setupUi(this);
    myuser=&theuser;
    myleague=&theleague;
    // Player 1
    this->ui->label->setText(QString::fromStdString(theuser.team.players[0].surname));
    this->ui->lcdNumber->display(theuser.team.players[0].overallgeneral);
    this->ui->label_13->setText(QString::fromStdString(theuser.team.players[0].position));
    this->ui->pushButton->setText(QString::number(theuser.team.players[0].marketvalue)+"$");

    // Player 2
    this->ui->label_2->setText(QString::fromStdString(theuser.team.players[1].surname));
    this->ui->lcdNumber_2->display(theuser.team.players[1].overallgeneral);
    this->ui->label_14->setText(QString::fromStdString(theuser.team.players[1].position));
    this->ui->pushButton_2->setText(QString::number(theuser.team.players[1].marketvalue)+"$");

    // Player 3
    this->ui->label_3->setText(QString::fromStdString(theuser.team.players[2].surname));
    this->ui->lcdNumber_3->display(theuser.team.players[2].overallgeneral);
    this->ui->label_15->setText(QString::fromStdString(theuser.team.players[2].position));
    this->ui->pushButton_3->setText(QString::number(theuser.team.players[2].marketvalue)+"$");

    // Player 4
    this->ui->label_4->setText(QString::fromStdString(theuser.team.players[3].surname));
    this->ui->lcdNumber_4->display(theuser.team.players[3].overallgeneral);
    this->ui->label_16->setText(QString::fromStdString(theuser.team.players[3].position));
    this->ui->pushButton_4->setText(QString::number(theuser.team.players[3].marketvalue)+"$");

    // Player 5
    this->ui->label_5->setText(QString::fromStdString(theuser.team.players[4].surname));
    this->ui->lcdNumber_5->display(theuser.team.players[4].overallgeneral);
    this->ui->label_17->setText(QString::fromStdString(theuser.team.players[4].position));
    this->ui->pushButton_5->setText(QString::number(theuser.team.players[4].marketvalue)+"$");

    // Player 6
    this->ui->label_6->setText(QString::fromStdString(theuser.team.players[5].surname));
    this->ui->lcdNumber_6->display(theuser.team.players[5].overallgeneral);
    this->ui->label_18->setText(QString::fromStdString(theuser.team.players[5].position));
    this->ui->pushButton_6->setText(QString::number(theuser.team.players[5].marketvalue)+"$");

    // Player 7
    this->ui->label_7->setText(QString::fromStdString(theuser.team.players[6].surname));
    this->ui->lcdNumber_7->display(theuser.team.players[6].overallgeneral);
    this->ui->label_19->setText(QString::fromStdString(theuser.team.players[6].position));
    this->ui->pushButton_7->setText(QString::number(theuser.team.players[6].marketvalue)+"$");

    // Player 8
    this->ui->label_8->setText(QString::fromStdString(theuser.team.players[7].surname));
    this->ui->lcdNumber_8->display(theuser.team.players[7].overallgeneral);
    this->ui->label_20->setText(QString::fromStdString(theuser.team.players[7].position));
    this->ui->pushButton_8->setText(QString::number(theuser.team.players[7].marketvalue)+"$");

    // Player 9
    this->ui->label_9->setText(QString::fromStdString(theuser.team.players[8].surname));
    this->ui->lcdNumber_9->display(theuser.team.players[8].overallgeneral);
    this->ui->label_21->setText(QString::fromStdString(theuser.team.players[8].position));
    this->ui->pushButton_9->setText(QString::number(theuser.team.players[8].marketvalue)+"$");

    // Player 10
    this->ui->label_10->setText(QString::fromStdString(theuser.team.players[9].surname));
    this->ui->lcdNumber_10->display(theuser.team.players[9].overallgeneral);
    this->ui->label_22->setText(QString::fromStdString(theuser.team.players[9].position));
    this->ui->pushButton_10->setText(QString::number(theuser.team.players[9].marketvalue)+"$");

    // Player 11
    this->ui->label_11->setText(QString::fromStdString(theuser.team.players[10].surname));
    this->ui->lcdNumber_11->display(theuser.team.players[10].overallgeneral);
    this->ui->label_23->setText(QString::fromStdString(theuser.team.players[10].position));
    this->ui->pushButton_11->setText(QString::number(theuser.team.players[10].marketvalue)+"$");

    // Player 12
    this->ui->label_12->setText(QString::fromStdString(theuser.team.players[11].surname));
    this->ui->lcdNumber_12->display(theuser.team.players[11].overallgeneral);
    this->ui->label_24->setText(QString::fromStdString(theuser.team.players[11].position));
    this->ui->pushButton_12->setText(QString::number(theuser.team.players[11].marketvalue)+"$");
}


Market::~Market()
{
    delete ui;
}

void Market::on_pushButton_13_clicked()
{
    this -> hide();
    emit backButtonClicked(*(this->myuser));
    //emit backButtonClicked();
}
