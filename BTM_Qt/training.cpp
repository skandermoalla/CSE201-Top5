#include "training.h"
#include "ui_training.h"

Training::Training(User& theuser , League& league, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Training)
{
    ui->setupUi(this);
}

Training::~Training()
{
    delete ui;
}

void Training::refresh()
{
    theuser.team.players[0].name="EDISONNNN";
    this->ui->label->setText(QString::fromStdString(theuser.team.players[0].name));
    this->ui->lcdNumber->display(theuser.team.players[0].overallgeneral);
    this->ui->labelp->setText(QString::fromStdString(theuser.team.players[0].position));

    // Player 2
    this->ui->label_2->setText(QString::fromStdString(theuser.team.players[1].name));
    this->ui->lcdNumber_2->display(theuser.team.players[1].overallgeneral);
    this->ui->label_2p->setText(QString::fromStdString(theuser.team.players[1].position));

    // Player 3
    this->ui->label_3->setText(QString::fromStdString(theuser.team.players[2].name));
    this->ui->lcdNumber_3->display(theuser.team.players[2].overallgeneral);
    this->ui->label_3p->setText(QString::fromStdString(theuser.team.players[2].position));

    // Player 4
    this->ui->label_4->setText(QString::fromStdString(theuser.team.players[3].name));
    this->ui->lcdNumber_4->display(theuser.team.players[3].overallgeneral);
    this->ui->label_4p->setText(QString::fromStdString(theuser.team.players[3].position));

    // Player 5
    this->ui->label_5->setText(QString::fromStdString(theuser.team.players[4].name));
    this->ui->lcdNumber_5->display(theuser.team.players[4].overallgeneral);
    this->ui->label_5p->setText(QString::fromStdString(theuser.team.players[4].position));

    // Player 6
    this->ui->label_6->setText(QString::fromStdString(theuser.team.players[5].name));
    this->ui->lcdNumber_6->display(theuser.team.players[5].overallgeneral);
    this->ui->label_6p->setText(QString::fromStdString(theuser.team.players[5].position));

    // Player 7
    this->ui->label_7->setText(QString::fromStdString(theuser.team.players[6].name));
    this->ui->lcdNumber_7->display(theuser.team.players[6].overallgeneral);
    this->ui->label_7p->setText(QString::fromStdString(theuser.team.players[6].position));

    // Player 8
    this->ui->label_8->setText(QString::fromStdString(theuser.team.players[7].name));
    this->ui->lcdNumber_8->display(theuser.team.players[7].overallgeneral);
    this->ui->label_8p->setText(QString::fromStdString(theuser.team.players[7].position));

    // Player 9
    this->ui->label_9->setText(QString::fromStdString(theuser.team.players[8].name));
    this->ui->lcdNumber_9->display(theuser.team.players[8].overallgeneral);
    this->ui->label_9p->setText(QString::fromStdString(theuser.team.players[8].position));

    // Player 10
    this->ui->label_10->setText(QString::fromStdString(theuser.team.players[9].name));
    this->ui->lcdNumber_10->display(theuser.team.players[9].overallgeneral);
    this->ui->label_10p->setText(QString::fromStdString(theuser.team.players[9].position));

    // Player 11
    this->ui->label_11->setText(QString::fromStdString(theuser.team.players[10].name));
    this->ui->lcdNumber_11->display(theuser.team.players[10].overallgeneral);
    this->ui->label_11p->setText(QString::fromStdString(theuser.team.players[10].position));

    // Player 12
    this->ui->label_12->setText(QString::fromStdString(theuser.team.players[11].name));
    this->ui->lcdNumber_12->display(theuser.team.players[11].overallgeneral);
    this->ui->label_12p->setText(QString::fromStdString(theuser.team.players[11].position));

}

void Training::on_pushButton_5_clicked()
{
    this -> hide();

    emit backButtonClicked();
}
