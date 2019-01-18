#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "startmenu.h"
#include  <QMessageBox>
#include <fstream>
#include <iostream>

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_start_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to start a game? All your saves will be lost",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            this -> close();
            startmenu->show();
        }
        else if (reply == QMessageBox::No)
        {}

}

void MainMenu::on_resume_clicked()
{   std::ifstream leaguefile;
    leaguefile.open("/tmp/league.txt");
    int division,week;
    std::string season;
    leaguefile>>division>>season>>week;
    League* league = new League(division,season);
    league->week=week;


    std::ifstream myfile;
    std::vector<std::string> files = {"/tmp/team0.txt","/tmp/team1.txt","/tmp/team2.txt","/tmp/team3.txt","/tmp/team4.txt","/tmp/team5.txt","/tmp/team6.txt","/tmp/team7.txt","/tmp/team8.txt","/tmp/team9.txt","/tmp/team10.txt","/tmp/team11.txt"};
    int age,height,weight,sprint,rebound,passing,handling,shooting,stealing,block,jump,strength,motivation,energy;
    double attack,defence,overallgeneral,marketvalue;
    for (int j=0;j<12;j++){
    myfile.open(files[j]);
    std::string name;
    int points;
    myfile>>name>>points;
    std::cout<<name<<std::endl;
    std::cout<<points<<std::endl;
    league->teams[j].name=name;
    league->teams[j].points=points;
    std::string playername,playersurname,playerposition;
    for (int i=0;i<12;i++){
        myfile>>playername>>playersurname>>playerposition;
        league->teams[j].players[i].name=playername;
        league->teams[j].players[i].surname=playersurname;
        league->teams[j].players[i].position=playerposition;
        myfile>>age>>height>>weight>>sprint>>rebound>>passing>>handling>>shooting>>stealing>>block>>jump>>strength>>motivation>>energy>>attack>>defence>>overallgeneral>>marketvalue;
        league->teams[j].players[i].age=age;
        league->teams[j].players[i].weight=weight;
        league->teams[j].players[i].sprint=sprint;
        league->teams[j].players[i].rebound=rebound;
        league->teams[j].players[i].passing=passing;
        league->teams[j].players[i].handling=handling;
        league->teams[j].players[i].shooting=shooting;
        league->teams[j].players[i].stealing=stealing;
        league->teams[j].players[i].block=block;
        league->teams[j].players[i].jump=jump;
        league->teams[j].players[i].strength=strength;
        league->teams[j].players[i].motivation=motivation;
        league->teams[j].players[i].energy=energy;
        league->teams[j].players[i].attack=attack;
        league->teams[j].players[i].defence=defence;
        league->teams[j].players[i].overallgeneral=overallgeneral;
        league->teams[j].players[i].marketvalue=marketvalue;
        league->teams[j].update_overall();
    }

    myfile.close();
        }

    std::ifstream userfile;
    userfile.open("/tmp/user.txt");
    std::string username,teamname,nationality;
    int budget;
    userfile>>username>>teamname>>nationality>>budget;
    User* myuser=new User(username,teamname,nationality);
    std::string playername,playersurname,playerposition;
    std::ifstream team0("/tmp/team0.txt");
    std::string name;
    int points;
    team0>>name>>points;
    myuser->team.name=name;
    myuser->team.points=points;

    for (int i=0;i<12;i++){
        team0>>playername>>playersurname>>playerposition>>age>>height>>weight>>sprint>>rebound>>passing>>handling>>shooting>>stealing>>block>>jump>>strength>>motivation>>energy>>attack>>defence>>overallgeneral>>marketvalue;
        std::cout<<playername<<" "<<playersurname<<" "<<playerposition<<std::endl;
        std::cout<<age<<" "<<height<<" "<<weight<<" "<<sprint<<" "<<rebound<<" "<<passing<<" "<<handling<<" "<<shooting<<" "<<stealing<<" "<<block<<" "<<jump<<" "<<strength<<" "<<motivation<<" "<<energy<<" "<<attack<<" "<<defence<<" "<<overallgeneral<<" "<<marketvalue<<std::endl;
        myuser->team.players[i].name=playername;
        myuser->team.players[i].surname=playersurname;
        myuser->team.players[i].position=playerposition;
        myuser->team.players[i].age=age;
        myuser->team.players[i].height=height;
        myuser->team.players[i].weight=weight;
        myuser->team.players[i].sprint=sprint;
        myuser->team.players[i].rebound=rebound;
        myuser->team.players[i].passing=passing;
        myuser->team.players[i].handling=handling;
        myuser->team.players[i].shooting=shooting;
        myuser->team.players[i].stealing=stealing;
        myuser->team.players[i].block=block;
        myuser->team.players[i].jump=jump;
        myuser->team.players[i].strength=strength;
        myuser->team.players[i].motivation=motivation;
        myuser->team.players[i].energy=energy;
        myuser->team.players[i].attack=attack;
        myuser->team.players[i].defence=defence;
        myuser->team.players[i].overallgeneral=overallgeneral;
        myuser->team.players[i].marketvalue=marketvalue;
        myuser->team.update_overall();
    }
    team0.close();
    userfile.close();


    mainwindow=new MainWindow(*myuser, *league);
    this -> hide();
    mainwindow->show();




}

void MainMenu::on_quit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                        "Are you sure you want to leave the game?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            this -> close();
        }
        else if (reply == QMessageBox::No)
        {}
}
