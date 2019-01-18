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
    ui->comments->setAlignment(Qt::AlignCenter);
    ui->comments->setFont(QFont("Comic Sans MS",14));
    ui->second_q->setVisible(false);
    ui->third_q->setVisible(false);
    ui->fourth_q->setVisible(false);
    ui->end_game->setVisible(false);
    ui->sub->setVisible(false);
    ui->tactics->setVisible(false);
    ui->def_tactic->setVisible(false);
    //ui->home_score->setPalette(QColor(255,0,0));
    //ui->away_score->setPalette(QColor(255,0,0));
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
    ui->start->setStyleSheet("font-weight: bold");
    ui->time->setAlignment(Qt::AlignCenter);
    ui->time->setFont(QFont("Comic Sans MS",14));
    ui->quater->setAlignment(Qt::AlignCenter);
    ui->quater->setText("Quarter: 1");
    ui->quater->setFont(QFont("Comic Sans MS",12)); //typo in my ui_form, quater instead of quarter,don't mind it
    ui->end_msg->setAlignment(Qt::AlignCenter);
    ui->end_msg->setFont(QFont("Comic Sans MS",12));
    ui->second_q->setVisible(false);
    ui->third_q->setVisible(false);
    ui->fourth_q->setVisible(false);
    ui->end_game->setVisible(false);
    ui->sub->setVisible(false);
    ui->tactics->setVisible(false);
    ui->def_tactic->setVisible(false);
    ui->home_name->setAlignment(Qt::AlignCenter);
    ui->home_name->setFont(QFont("",14));
    ui->home_name->setText(QString::fromStdString(myuser->teamname));
    ui->away_name->setAlignment(Qt::AlignCenter);
    ui->away_name->setFont(QFont("",14));
    ui->away_name->setText(QString::fromStdString(myleague->getThisWeeksOpponentTeam().name));
    ui->comments->setAlignment(Qt::AlignCenter);
    ui->comments->setFont(QFont("Comic Sans MS",16));
    ui->home_score->setStyleSheet({"color:rgb(255,0,0); background-color:rgb(0,0,0);border: 3px solid white"});
    ui->away_score->setStyleSheet({"color:rgb(0,0,255); background-color:rgb(0,0,0);border: 3px solid white"});
    ui->def_tactic->setVisible(false);
    ui->tactics->setVisible(false);
    ui->sub->setVisible(false);
}


NextGame::~NextGame()
{
    delete ui;
}
QTime quarter_length(0,1,30); //a quarter last 12 mins but we gonna make it 3:00 for now
void NextGame::quarter_1_timing(){
    QTime stop_count(0,0,0);
    QTime time = quarter_length;
    if (time != stop_count){
        qDebug() << "updating clock1";
        time =quarter_length.addSecs(-1); // minus -1 sec to the time
        quarter_length = time;
        QString time_text = time.toString("mm : ss"); //displaying format
        ui->time->setText(time_text); //set the ui label to time_text
        ui->home_score->display(QString::fromStdString(std::to_string((this->score.first))));
        ui->away_score->display(QString::fromStdString(std::to_string((this->score.second))));
    } else {
        timer->stop();
        s_timer->stop();
        ui->second_q->setVisible(true);
        ui->second_q->setText("Go to 2nd");
        ui->second_q->setStyleSheet("font-weight: bold");
        ui->tactics->setVisible(false);
        ui->def_tactic->setVisible(false);
        ui->tactics->setEnabled(false);
        ui->def_tactic->setEnabled(false);
        ui->sub->setVisible(true);
        ui->sub->setEnabled(true);
        quarter_length = QTime(0,1,30);

        ui->end_msg->setText("End of the Quarter 1");
        ui->sub->setVisible(true);
        ui->tactics->setVisible(false);
        ui->def_tactic->setVisible(false);

        //save the state of the managers team and add energy to both teams
        engine->endOfQuarterRest(myuser, playingManagersTeam, playingOpponentsTeam);
    }
}
void NextGame::quarter_2_timing(){
    QTime stop_count(0,0,0);
    QTime time;
    if (quarter_length != stop_count){
        qDebug() << "updating clock2";
        time =quarter_length.addSecs(-1); // minus -1 sec to the time
        quarter_length = time;
        QString time_text = time.toString("mm : ss"); //displaying format
        ui->time->setText(time_text); //set the ui label to time_text
        ui->home_score->display(QString::fromStdString(std::to_string((this->score.first))));
        ui->away_score->display(QString::fromStdString(std::to_string((this->score.second))));
    } else {
        ui->end_msg->setVisible(true);
        timer->stop();
        s_timer->stop();
        ui->third_q->setVisible(true);
        ui->third_q->setText("Go to 3rd");
        ui->third_q->setStyleSheet("font-weight: bold");
        ui->end_msg->setText("End of the Quarter 2");
        ui->tactics->setVisible(false);
        ui->def_tactic->setVisible(false);
        ui->tactics->setEnabled(false);
        ui->def_tactic->setEnabled(false);
        ui->sub->setVisible(true);
        ui->sub->setEnabled(true);
        quarter_length = QTime(0,1,30);

        ui->sub->setVisible(true);
        ui->tactics->setVisible(false);
        ui->def_tactic->setVisible(false);

        //save the state of the managers team and add energy to both teams
        engine->endOfQuarterRest(myuser, playingManagersTeam, playingOpponentsTeam);


    }
}
void NextGame::quarter_3_timing(){
    QTime stop_count(0,0,0);
    QTime time;
    if (quarter_length != stop_count){
        qDebug() << "updating clock3";
        time =quarter_length.addSecs(-1); // minus -1 sec to the time
        quarter_length = time;
        QString time_text = time.toString("mm : ss"); //displaying format
        ui->time->setText(time_text); //set the ui label to time_text
        ui->home_score->display(QString::fromStdString(std::to_string((this->score.first))));
        ui->away_score->display(QString::fromStdString(std::to_string((this->score.second))));
    } else {
        ui->end_msg->setVisible(true);
        timer->stop();
        s_timer->stop();
        ui->fourth_q->setVisible(true);
        ui->fourth_q->setText("Go to 4th");
        ui->fourth_q->setStyleSheet("font-weight: bold");
        ui->end_msg->setText("End of the Quarter 3");
        ui->tactics->setVisible(false);
        ui->def_tactic->setVisible(false);
        ui->tactics->setEnabled(false);
        ui->def_tactic->setEnabled(false);
        ui->sub->setVisible(true);
        ui->sub->setEnabled(true);
        quarter_length = QTime(0,1,30);

        ui->sub->setVisible(true);
        ui->tactics->setVisible(false);
        ui->def_tactic->setVisible(false);

        //save the state of the managers team and add energy to both teams
        engine->endOfQuarterRest(myuser, playingManagersTeam, playingOpponentsTeam);

    }
}
void NextGame::quarter_4_timing(){
    QTime stop_count(0,0,0);
    QTime time;
    if (quarter_length != stop_count){
        qDebug() << "updating clock4";
        time =quarter_length.addSecs(-1); // minus -1 sec to the time
        quarter_length = time;
        QString time_text = time.toString("mm : ss"); //displaying format
        ui->time->setText(time_text); //set the ui label to time_text
        ui->home_score->display(QString::fromStdString(std::to_string((this->score.first))));
        ui->away_score->display(QString::fromStdString(std::to_string((this->score.second))));
    } else {
        disconnect(timer,SIGNAL(timeout()),this,SLOT(quarter_4_timing()));
        disconnect(s_timer,SIGNAL(timeout()),this,SLOT(strat()));
        ui->end_msg->setVisible(true);
        timer->stop();
        s_timer->stop();
        ui->fourth_q->setVisible(false);
        ui->end_game->setVisible(true);
        ui->end_game->setText("End");
        ui->end_game->setStyleSheet("font-weight: bold");
        ui->tactics->setVisible(false);
        ui->def_tactic->setVisible(false);

        ui->sub->setVisible(false);

        ui->tactics->setEnabled(false);
        ui->def_tactic->setEnabled(false);
        ui->end_msg->setText("End of the game");
        quarter_length = QTime(0,1,30);

        //save the state of the managers team and add energy to both teams
        engine->endOfQuarterRest(myuser, playingManagersTeam, playingOpponentsTeam);

        //save the opponents team
        myleague->getThisWeeksOpponentTeam() = engine->copyTeam(playingOpponentsTeam);
    }
}

QTime stra_time(0,0,0);

void NextGame::strat(){

    QTime change_stra(0,0,3);
    if  (stra_time != change_stra){
        qDebug()<<"updating strategy function timer";
        stra_time = stra_time.addSecs(1);
    } else{

        int outcome = engine->getAttackResult(playingManagersTeam, playingOpponentsTeam, isManagerAttacking);
        QString highlight;

        qDebug()<<"outcome = " << outcome;
        if (isManagerAttacking){
            score.first += outcome;

            //add hightlight to highlights
            QPalette palette = ui->comments->palette();
            palette.setColor(QPalette::WindowText,Qt::red);
            ui->comments->setPalette(palette);

            highlight = engine->popMessage(playingManagersTeam, outcome);
        }
        else {
            score.second += outcome;

            //add highlight to highlights

            QPalette palette = ui->comments->palette();
            palette.setColor(QPalette::WindowText,Qt::blue);
            ui->comments->setPalette(palette);

            highlight = engine->popMessage(playingOpponentsTeam, outcome);
        }

        ui->comments->setText(highlight);

        //change state
        isManagerAttacking = not isManagerAttacking;
        stra_time=stra_time.addSecs(-3);
        qDebug()<<"stra_time function ="<<stra_time;
    }
}

void NextGame::on_start_clicked()
{
    ui->tactics->setVisible(true);
    ui->def_tactic->setVisible(true);
    ui->tactics->setEnabled(true);
    ui->def_tactic->setEnabled(true);
    ui->sub->setEnabled(false);
    ui->sub->setVisible(false);
    ui->start->setEnabled(false);
    ui->start->setVisible(false);
    ui->start->setEnabled(false);

    //get user's and opponents teams
    Team& initManagersTeam = myuser->team;
    Team& initOpponentsTeam = myleague->getThisWeeksOpponentTeam();

    //copy managers team to be able to apply changes to it and recover the initTeam for default tactic
    playingManagersTeam = engine->copyTeam(initManagersTeam);
    playingOpponentsTeam = engine->copyTeam(initOpponentsTeam);

    //show tactics button that was hidden and
    ui->start->setVisible(false);
    ui->tactics->setVisible(true);
    ui->def_tactic->setVisible(true);

    tactic_ingame = new Tactic_inGame(engine, &playingManagersTeam, &(myuser->team));
    //do for each quarter

    connect(timer,SIGNAL(timeout()),this,SLOT(quarter_1_timing()));
    connect(s_timer,SIGNAL(timeout()),this,SLOT(strat()));

    timer->start(1000); //scale time
    s_timer->start(1000);
}

void NextGame::on_second_q_clicked()
{
    ui->tactics->setVisible(true);
    ui->def_tactic->setVisible(true);
    ui->tactics->setEnabled(true);
    ui->def_tactic->setEnabled(true);
    ui->second_q->setVisible(false);
    ui->second_q->setEnabled(false);
    ui->end_msg->setVisible(false);
    ui->sub->setEnabled(false);
    ui->sub->setVisible(false);
    ui->quater->setText("Quarter: 2");
    disconnect(timer,SIGNAL(timeout()),this,SLOT(quarter_1_timing()));

    //get the teams that are playing
    Team& initManagersTeam = myuser->team;

    //copy managers team to be able to apply changes to it and recover the initTeam for default tactic
    playingManagersTeam = engine->copyTeam(initManagersTeam);

    //show tactics button that was hidden and
    ui->second_q->setVisible(false);
    ui->sub->setVisible(false);
    ui->tactics->setVisible(true);
    ui->def_tactic->setVisible(true);

    tactic_ingame = new Tactic_inGame(engine, &playingManagersTeam, &(myuser->team));

    connect(timer,SIGNAL(timeout()),this,SLOT(quarter_2_timing()));

    //connect(s_timer,SIGNAL(timeout()),this,SLOT(strat()));

    //do for each quarter
    timer->start(1000); //scale time
    s_timer->start(1000);

}

void NextGame::on_third_q_clicked()
{
    ui->tactics->setVisible(true);
    ui->def_tactic->setVisible(true);
    ui->tactics->setEnabled(true);
    ui->def_tactic->setEnabled(true);
    ui->third_q->setVisible(false);
    ui->third_q->setEnabled(false);
    ui->end_msg->setVisible(false);
    ui->sub->setEnabled(false);
    ui->sub->setVisible(false);
    ui->quater->setText("Quarter: 3");
    disconnect(timer,SIGNAL(timeout()),this,SLOT(quarter_2_timing()));

    //get the teams that are playing
    Team& initManagersTeam = myuser->team;

    //copy managers team to be able to apply changes to it and recover the initTeam for default tactic
    playingManagersTeam = engine->copyTeam(initManagersTeam);

    //show tactics button that was hidden and
    ui->third_q->setVisible(false);
    ui->sub->setVisible(false);
    ui->tactics->setVisible(true);
    ui->def_tactic->setVisible(true);

    tactic_ingame = new Tactic_inGame(engine, &playingManagersTeam, &(myuser->team));

    connect(timer,SIGNAL(timeout()),this,SLOT(quarter_3_timing()));
    //connect(s_timer,SIGNAL(timeout()),this,SLOT(strat()));

    timer->start(1000); //scale time
    s_timer->start(1000);

}

void NextGame::on_fourth_q_clicked()
{
    ui->tactics->setVisible(true);
    ui->def_tactic->setVisible(true);
    ui->tactics->setEnabled(true);
    ui->def_tactic->setEnabled(true);
    ui->fourth_q->setVisible(false);
    ui->fourth_q->setEnabled(false);
    ui->end_msg->setVisible(false);
    ui->sub->setEnabled(false);
    ui->sub->setVisible(false);
    ui->quater->setText("Quarter: 4");
    disconnect(timer,SIGNAL(timeout()),this,SLOT(quarter_3_timing()));

    //get the teams that are playing
    Team& initManagersTeam = myuser->team;

    //copy managers team to be able to apply changes to it and recover the initTeam for default tactic
    playingManagersTeam = engine->copyTeam(initManagersTeam);

    //show tactics button that was hidden and
    ui->fourth_q->setVisible(false);
    ui->sub->setVisible(false);
    ui->tactics->setVisible(true);
    ui->def_tactic->setVisible(true);

    tactic_ingame = new Tactic_inGame(engine, &playingManagersTeam, &(myuser->team));

    connect(timer,SIGNAL(timeout()),this,SLOT(quarter_4_timing()));
    //connect(s_timer,SIGNAL(timeout()),this,SLOT(strat()));
    timer->start(1000); //scale time
    s_timer->start(1000);

}

void NextGame::on_end_game_clicked()
{
    timer->stop();
    s_timer->stop();

    //call endOfMatchUpdate method of gameEngine
    int reward = engine->endOfMatchUpdate(myuser, myleague, myleague->getThisWeeksOpponentTeam(), score);

    //create a pop-up with the reward


    //When button is clicked I want to hide nextgame window and go back to mainwindow
    this->close();

    emit backButtonClicked(*this->myuser, *this->myleague);
    qDebug() << "return to mainwindow";


}

void NextGame::on_tactics_clicked()
{
    tactic_ingame->show();
}
