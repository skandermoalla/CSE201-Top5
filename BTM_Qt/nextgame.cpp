#include "nextgame.h"
#include "ui_nextgame.h"
#include <QTimer>
#include<QTime>
#include<QString>

NextGame::NextGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NextGame)
{
    ui->setupUi(this);
    timer = new QTimer(this); //new timer object
}

NextGame::~NextGame()
{
    delete ui;
}
void NextGame::myfunc(){
    QTime quarter_length(0,12,0); //a quarter last 12 mins
    QTime time;
    time =quarter_length.addSecs(-1); // minus -1 sec to the time
    QString time_text = time.toString("mm : ss"); //displaying format
    ui->time->setText(time_text); //set the ui label to time_text
}

void NextGame::on_start_clicked()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(myfunc));
    timer->start(8000); //scale time
}
