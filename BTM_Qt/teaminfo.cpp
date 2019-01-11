#include "teaminfo.h"
#include "ui_teaminfo.h"
#include <QLabel>


TeamInfo::TeamInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamInfo)

{
    ui->setupUi(this);

}


TeamInfo::~TeamInfo()
{
    delete ui;
}

void TeamInfo::on_pushButton_clicked()
{
    this -> hide();
    emit backButtonClicked();
}
