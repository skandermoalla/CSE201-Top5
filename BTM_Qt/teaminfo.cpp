#include "teaminfo.h"
#include "ui_teaminfo.h"
#include <QLabel>


TeamInfo::TeamInfo(/*GamePLayer gp, */QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamInfo)
    //gameplayer(gp)
{
    ui->setupUi(this);
    //ui->coachn->setText(gameplayer.get_name());
   // ui->teamn->setText(gameplayer.get_team());
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
