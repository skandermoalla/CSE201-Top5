#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(calendar, SIGNAL(backButtonClicked()), this, SLOT(show()));
    connect(calendar, SIGNAL(backButtonClicked()), this, SLOT(refresh()));

    connect(training, SIGNAL(backButtonClicked()), this, SLOT(show()));
    connect(training, SIGNAL(backButtonClicked()), this, SLOT(refresh()));

    connect(teaminfo, SIGNAL(backButtonClicked()), this, SLOT(show()));
    connect(teaminfo, SIGNAL(backButtonClicked()), this, SLOT(refresh()));

    connect(preparation, SIGNAL(backButtonClicked()), this, SLOT(show()));
    connect(preparation, SIGNAL(backButtonClicked()), this, SLOT(refresh()));
    // We may need a function to refresh the display
    // the function pack up all the operations on data below
    // the function may take the current game state as an argument
}

//Window operations
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh()
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

    //Info tab
    QStringList header;
    header<<"Name"<<"Nationality"<<"Age"<<"Height"<<"Weight";
    this->ui->tableWidget->setColumnCount(5);
    this->ui->tableWidget->setRowCount(12);
    this->ui->tableWidget->setHorizontalHeaderLabels(header);

    for (int i = 0; i < 12; i++ ) {
    this->ui->tableWidget->setItem(i,0,new QTableWidgetItem("BILIBILI"));
    this->ui->tableWidget->setItem(i,1,new QTableWidgetItem((/*QIcon("images.png"), */"Country")));
    this->ui->tableWidget->setItem(i,2,new QTableWidgetItem("20"));
    this->ui->tableWidget->setItem(i,3,new QTableWidgetItem("190"));
    this->ui->tableWidget->setItem(i,4,new QTableWidgetItem("85"));
    }

    //Ability tab
    QStringList header2;
    header2<<"Name"<<"Nationality"<<"Age"<<"Height"<<"Weight";
    this->ui->tableWidget->setColumnCount(5);
    this->ui->tableWidget->setRowCount(12);
    this->ui->tableWidget->setHorizontalHeaderLabels(header2);

    for (int i = 0; i < 12; i++ ) {
    this->ui->tableWidget->setItem(i,0,new QTableWidgetItem("BILIBILI"));
    this->ui->tableWidget->setItem(i,1,new QTableWidgetItem((/*QIcon("images.png"), */"Country")));
    this->ui->tableWidget->setItem(i,2,new QTableWidgetItem("20"));
    this->ui->tableWidget->setItem(i,3,new QTableWidgetItem("190"));
    this->ui->tableWidget->setItem(i,4,new QTableWidgetItem("85"));
    }

    /*
    QStringList header3;
    header3<<"Name"<<"Nationality"<<"Age"<<"Height"<<"Weight";
    this->ui->tableWidget->setColumnCount(5);
    this->ui->tableWidget->setRowCount(12);
    this->ui->tableWidget->setHorizontalHeaderLabels(header3);

    for (int i = 0; i < 12; i++ ) {
    this->ui->tableWidget->setItem(i,0,new QTableWidgetItem("BILIBILI"));
    this->ui->tableWidget->setItem(i,1,new QTableWidgetItem((QIcon("images.png"), "Country")));
    this->ui->tableWidget->setItem(i,2,new QTableWidgetItem("20"));
    this->ui->tableWidget->setItem(i,3,new QTableWidgetItem("190"));
    this->ui->tableWidget->setItem(i,4,new QTableWidgetItem("85"));
    }
*/

    this->ui->tableWidget->show();
}

void MainWindow::on_pushButton_clicked()
{
    this -> hide();
    calendar -> show();
}

void MainWindow::on_pushButton_3_clicked()
{
    this -> hide();
    training -> refresh();
    training -> show();
}

void MainWindow::on_pushButton_4_clicked()
{
    this -> hide();
    teaminfo -> show();
}

void MainWindow::on_pushButton_5_clicked()
{
    this -> hide();
    preparation -> show();
}
