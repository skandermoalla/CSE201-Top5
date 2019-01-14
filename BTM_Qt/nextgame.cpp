#include "nextgame.h"
#include "ui_nextgame.h"
#include <QTimer>
#include<QTime>
#include<QString>
#include <QDebug>

NextGame::NextGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NextGame)
{
    ui->setupUi(this);
    timer = new QTimer(this); //new timer object
    ui->time->setAlignment(Qt::AlignCenter);
    ui->time->setFont(QFont("Comic Sans MS",12));
    ui->quater->setAlignment(Qt::AlignCenter);
    ui->quater->setText("Quarter: 1");
    ui->quater->setFont(QFont("Comic Sans MS",12)); //typo in my ui_form, quater instead of quarter,don't mind it
    ui->end_msg->setAlignment(Qt::AlignCenter);
    ui->end_msg->setFont(QFont("Comic Sans MS",12));

}

NextGame::NextGame(User& theuser, League& theleague, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NextGame)
{
    myuser = &theuser;
    myleague = &theleague;

    ui->setupUi(this);
    timer = new QTimer(this); //new timer object
    ui->time->setAlignment(Qt::AlignCenter);
    ui->time->setFont(QFont("Comic Sans MS",12));
    ui->quater->setAlignment(Qt::AlignCenter);
    ui->quater->setText("Quarter: 1");
    ui->quater->setFont(QFont("Comic Sans MS",12)); //typo in my ui_form, quater instead of quarter,don't mind it
    ui->end_msg->setAlignment(Qt::AlignCenter);
    ui->end_msg->setFont(QFont("Comic Sans MS",12));

}


NextGame::~NextGame()
{
    delete ui;
}

QTime quarter_length(0,1,20); //a quarter last 12 mins but we gonna make it 1:20 for now
void NextGame::myfunc(){
    QTime stop_count(0,0,0);
    QTime time;
    if (quarter_length != stop_count){
        qDebug() << "update..";
        time =quarter_length.addSecs(-1); // minus -1 sec to the time
        quarter_length = time;
        QString time_text = time.toString("mm : ss"); //displaying format
        ui->time->setText(time_text); //set the ui label to time_text
    } else {
        timer->stop();
        ui->start->setText("Continue");
        /*ui->quater->setText("Quarter: 2");*/
        ui->end_msg->setText("End of the Quarter");
    }
}


void NextGame::on_start_clicked()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(myfunc()));
    timer->start(1000); //scale time

}
