#include "market.h"
#include "ui_market.h"

Market::Market(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Market)
{
    ui->setupUi(this);
}

Market::~Market()
{
    delete ui;
}
