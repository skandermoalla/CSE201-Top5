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
}


Market::~Market()
{
    delete ui;
}

void Market::on_pushButton_13_clicked()
{
    this -> hide();
    emit backButtonClicked();
}
