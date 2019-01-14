#include "tactics.h"
#include "ui_tactics.h"

Tactics::Tactics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tactics)
{
    ui->setupUi(this);
    ui->t1->setFont(QFont("Comic Sans MS",12));
    ui->t2->setFont(QFont("Comic Sans MS",12));
    ui->t3->setFont(QFont("Comic Sans MS",12));
    ui->l1->setAlignment(Qt::AlignCenter);
    ui->l1->setText("Quarter: 1");
    ui->l1->setFont(QFont("Comic Sans MS",12));
    ui->l2->setAlignment(Qt::AlignCenter);
    ui->l2->setText("Quarter: 1");
    ui->l2->setFont(QFont("Comic Sans MS",12));
    ui->l3->setAlignment(Qt::AlignCenter);
    ui->l3->setText("Quarter: 1");
    ui->l3->setFont(QFont("Comic Sans MS",12));
}

Tactics::~Tactics()
{
    delete ui;
}
