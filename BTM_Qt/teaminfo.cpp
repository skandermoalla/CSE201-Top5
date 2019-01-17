#include "teaminfo.h"
#include "ui_teaminfo.h"
#include <QLabel>


TeamInfo::TeamInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamInfo)

{
    ui->setupUi(this);
}

TeamInfo::TeamInfo(User& theuser, League& A, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamInfo)

{
    ui->setupUi(this);

    this->myuser = &theuser;
    this->myleague = &A;
    this->ui->coachn->setText(QString::fromStdString(theuser.name));
    this->ui->teamn->setText(QString::fromStdString(theuser.teamname));

    //Ranking Table
    QStringList header;
    header<<"Ranking"<<"Team name"<<"Points";
    this->ui->tableWidget->setColumnCount(3);
    this->ui->tableWidget->setRowCount(12);
    this->ui->tableWidget->setHorizontalHeaderLabels(header);

    for (int i = 0; i < 12; i++ ) {
    this->ui->tableWidget->setItem(i,0,new QTableWidgetItem(i+1));
    this->ui->tableWidget->setItem(i,1,new QTableWidgetItem(i+1));
    this->ui->tableWidget->setItem(i,2,new QTableWidgetItem(i+1));
    }
    this->ui->tableWidget->show();
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
