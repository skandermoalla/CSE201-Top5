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

}

NextGame::NextGame(GameEngine* eng, User& theuser, League& theleague, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NextGame)
{
    myuser = &theuser;
    myleague = &theleague;
    engine = eng;
    isManagerAttacking = true;
    score = std::pair<int, int>(0,0);

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

}


NextGame::~NextGame()
{
    delete ui;
}

QTime quarter_length(0,3,00); //a quarter last 12 mins but we gonna make it 3:00 for now
void NextGame::quarter_timing(){
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
        ui->start->setText("Continue");
        /*ui->quater->setText("Quarter: 2");*/
        ui->end_msg->setText("End of the Quarter");
    }
}

QTime stra_time(0,0,0);

void NextGame::strat(){


    QTime change_stra(0,0,15);
    if  (stra_time != change_stra){
        qDebug()<<"updating strategy function timer";
        stra_time = stra_time.addSecs(1);
    } else{
        qDebug()<<"fifteen seconds reached start function ";
        //insert your attack/defense function here

        int outcome = engine->getAttackResult(playingManagersTeam, playingOpponentsTeam, isManagerAttacking);

        qDebug()<<"outcome = " << outcome;
        if (isManagerAttacking){
            score.first += outcome;
        }
        else {
            score.second += outcome;
        }

        isManagerAttacking = not isManagerAttacking;

        stra_time=stra_time.addSecs(-15);
        qDebug()<<"stra_time function ="<<stra_time;
    }
}

void NextGame::on_start_clicked()
{
    Team& initManagersTeam = myuser->team;
    Team& initOpponentsTeam = myleague->getThisWeeksOpponentTeam();

    playingManagersTeam = engine->copyTeam(initManagersTeam);
    playingOpponentsTeam = engine->copyTeam(initOpponentsTeam);

    qDebug()<<"copied them";

    connect(timer,SIGNAL(timeout()),this,SLOT(quarter_timing()));
    connect(s_timer,SIGNAL(timeout()),this,SLOT(strat()));

    timer->start(1000); //scale time
    s_timer->start(1000);


}
