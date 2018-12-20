#include "preparation.h"
#include "ui_preparation.h"

Preparation::Preparation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preparation)
{
    ui->setupUi(this);
    this-> ui -> widget -> setStyleSheet("widget {border-image: url(:/images/images/background.jpeg)};");
}

Preparation::~Preparation()
{
    delete ui;
}

void Preparation::refresh()
{
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
}

void Preparation::on_pushButton_15_clicked()
{
    this -> hide();
    emit backButtonClicked();
}
