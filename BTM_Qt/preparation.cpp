#include "preparation.h"
#include "ui_preparation.h"

Preparation::Preparation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preparation)
{
    ui->setupUi(this);
}

Preparation::~Preparation()
{
    delete ui;
}
