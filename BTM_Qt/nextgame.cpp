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
    s_timer = new QTimer(this); //timer that manages strategy change
    ui->time->setAlignment(Qt::AlignCenter);
    ui->time->setFont(QFont("Comic Sans MS",12));
    ui->quater->setAlignment(Qt::AlignCenter);
    ui->quater->setText("Quarter: 1");
    ui->quater->setFont(QFont("Comic Sans MS",12)); //typo in my ui_form, quater instead of quarter,don't mind it
    ui->end_msg->setAlignment(Qt::AlignCenter);
    ui->end_msg->setFont(QFont("Comic Sans MS",12));
    ui->second_q->setVisible(false);
    ui->third_q->setVisible(false);
    ui->fourth_q->setVisible(false);
    ui->end_game->setVisible(false);
}

NextGame::NextGame(User& theuser, League& theleague, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NextGame)
{
    myuser = &theuser;
    myleague = &theleague;

    ui->setupUi(this);
    timer = new QTimer(this); //new timer object
    s_timer = new QTimer(this);
    ui->time->setAlignment(Qt::AlignCenter);
    ui->time->setFont(QFont("Comic Sans MS",12));
    ui->quater->setAlignment(Qt::AlignCenter);
    ui->quater->setText("Quarter: 1");
    ui->quater->setFont(QFont("Comic Sans MS",12)); //typo in my ui_form, quater instead of quarter,don't mind it
    ui->end_msg->setAlignment(Qt::AlignCenter);
    ui->end_msg->setFont(QFont("Comic Sans MS",12));
    ui->second_q->setVisible(false);
    ui->third_q->setVisible(false);
    ui->fourth_q->setVisible(false);
    ui->end_game->setVisible(false);
}


NextGame::~NextGame()
{
    delete ui;
}
int i = 1;
QTime quarter_length(0,3,00); //a quarter last 12 mins but we gonna make it 3:00 for now
void NextGame::quarter_1_timing(){
    QTime stop_count(0,0,0);
    QTime time;
    if (quarter_length != stop_count){
        qDebug() << "updating clock";
        time =quarter_length.addSecs(-1); // minus -1 sec to the time
        quarter_length = time;
        QString time_text = time.toString("mm : ss"); //displaying format
        ui->time->setText(time_text); //set the ui label to time_text
    } else {
        /*QList <QPushButton* > pb;
        pb[0] = ui->start;
        pb[1] = ui->second_q;
        pb[2] = ui->third_q;
        pb[3] = ui->fourth_q;
        pb[4] = ui->end_game;*/
        timer->stop();
        ui->start->setVisible(false);
        ui->second_q->setVisible(true);
        ui->second_q->setText("Continue");
        ui->end_msg->setText("End of the Quarter"+QString::number(i));
        i=i+1;
    }
}
void NextGame::quarter_2_timing(){
    QTime stop_count(0,0,0);
    QTime time;
    if (quarter_length != stop_count){
        qDebug() << "updating clock";
        time =quarter_length.addSecs(-1); // minus -1 sec to the time
        quarter_length = time;
        QString time_text = time.toString("mm : ss"); //displaying format
        ui->time->setText(time_text); //set the ui label to time_text
    } else {
        timer->stop();
        ui->second_q->setVisible(false);
        ui->third_q->setVisible(true);
        ui->third_q->setText("Continue");
        ui->end_msg->setText("End of the Quarter"+QString::number(i));
        i=i+1;
    }
}
void NextGame::quarter_3_timing(){
    QTime stop_count(0,0,0);
    QTime time;
    if (quarter_length != stop_count){
        qDebug() << "updating clock";
        time =quarter_length.addSecs(-1); // minus -1 sec to the time
        quarter_length = time;
        QString time_text = time.toString("mm : ss"); //displaying format
        ui->time->setText(time_text); //set the ui label to time_text
    } else {
        timer->stop();
        ui->third_q->setVisible(false);
        ui->fourth_q->setVisible(true);
        ui->fourth_q->setText("Continue");
        ui->end_msg->setText("End of the Quarter"+QString::number(i));
        i=i+1;
    }
}
void NextGame::quarter_4_timing(){
    QTime stop_count(0,0,0);
    QTime time;
    if (quarter_length != stop_count){
        qDebug() << "updating clock";
        time =quarter_length.addSecs(-1); // minus -1 sec to the time
        quarter_length = time;
        QString time_text = time.toString("mm : ss"); //displaying format
        ui->time->setText(time_text); //set the ui label to time_text
    } else {
        timer->stop();
        ui->fourth_q->setVisible(false);
        ui->second_q->setVisible(true);
        ui->second_q->setText("Continue");
        ui->end_msg->setText("End of the game");
    }
}
QTime stra_time(0,0,0);
void NextGame::strat(){
    QTime change_stra(0,0,15);
    if  (stra_time != change_stra){
        qDebug()<<"updating strategy timer";
        stra_time = stra_time.addSecs(1);
    } else{
        qDebug()<<"fifteen seconds reached";
        //insert your attack/defense function here
        stra_time=stra_time.addSecs(-15);
        qDebug()<<"stra_time="<<stra_time;
    }
}

void NextGame::on_start_clicked()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(quarter_1_timing()));
    connect(s_timer,SIGNAL(timeout()),this,SLOT(strat()));
    timer->start(1000); //scale time
    s_timer->start(1000);


}

void NextGame::on_second_q_clicked()
{
    if (i<5){
      ui->quater->setText("Quarter: "+QString::number(i+1));
    }
    connect(timer,SIGNAL(timeout()),this,SLOT(quarter_2_timing()));
    connect(s_timer,SIGNAL(timeout()),this,SLOT(strat()));
    timer->start(1000); //scale time
    s_timer->start(1000);

}

void NextGame::on_third_q_clicked()
{
    if (i<5){
      ui->quater->setText("Quarter: "+QString::number(i+1));
    }
    connect(timer,SIGNAL(timeout()),this,SLOT(quarter_3_timing()));
    connect(s_timer,SIGNAL(timeout()),this,SLOT(strat()));
    timer->start(1000); //scale time
    s_timer->start(1000);

}

void NextGame::on_fourth_q_clicked()
{
    if (i<5){
      ui->quater->setText("Quarter: "+QString::number(i+1));
    }
    connect(timer,SIGNAL(timeout()),this,SLOT(quarter_4_timing()));
    connect(s_timer,SIGNAL(timeout()),this,SLOT(strat()));
    timer->start(1000); //scale time
    s_timer->start(1000);

}

void NextGame::on_end_game_clicked()
{
    //When button is clicked I want to hide nextgame window and go back to mainwindow
    /*this->hide();*/

}
