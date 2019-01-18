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
{   //the idea is to create a league from reading the file
    //then modify the teams of the league by reading each team's file

    std::ifstream leaguefile;
    leaguefile.open("league.txt");
    int division,week;
    std::string season,photoloc1,photoloc2;
    //read the division, season and week of the league
    leaguefile>>division>>season>>week;
    //Now we create the league
    League* league = new League(division,season);
    league->week=week; //modify the week of the league


    std::ifstream myfile;
    std::vector<std::string> files = {"team0.txt","team1.txt","team2.txt","team3.txt","team4.txt","team5.txt","team6.txt","team7.txt","team8.txt","team9.txt","team10.txt","team11.txt"};
    int age,height,weight,sprint,rebound,passing,handling,shooting,stealing,block,jump,strength,motivation,energy;
    double attack,defence,overallgeneral,marketvalue;
    //modify the teams of the league created based on the files
    for (int j=0;j<12;j++){
    myfile.open(files[j]);
    std::string name;
    int points,nrplayers,gamesplayed;
    myfile>>name>>points>>nrplayers>>gamesplayed;
    std::cout<<name<<std::endl; //name of the team
    std::cout<<points<<std::endl; //points of the team
    league->teams[j].name=name;
    league->teams[j].points=points;
    league->teams[j].gamesplayed=gamesplayed;
    std::string playername,playersurname,playerposition;
    for (int i=0;i<nrplayers;i++){
        //get the players information
        myfile>>playername>>playersurname>>playerposition;
        league->teams[j].players[i].name=playername;
        league->teams[j].players[i].surname=playersurname;
        league->teams[j].players[i].position=playerposition;
        myfile>>age>>height>>weight>>sprint>>rebound>>passing>>handling>>shooting>>stealing>>block>>jump>>strength>>motivation>>energy>>attack>>defence>>overallgeneral>>marketvalue>>photoloc1>>photoloc2;
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
        league->teams[j].players[i].photoadress=QString::fromStdString(photoloc1+" "+photoloc2);
        league->teams[j].update_overall();
    }
    for (int j=nrplayers;j<12;j++){
        league->teams[j].players.erase(league->teams[j].players.begin()+j-1);
    }

    myfile.close();
        }


    //create the user team and update it based on the file
    std::ifstream userfile("user.txt");
    std::string username,teamname,nationality;
    int budget;
    userfile>>username>>teamname>>nationality>>budget;
    User* myuser=new User(username,teamname,nationality); 


    //now update the user team
    std::ifstream team0("team0.txt");
    std::string name,playername,playersurname,playerposition;;
    int points,nrplayers,gamesplayed;
    team0>>name>>points>>nrplayers>>gamesplayed;
    myuser->team.name=name;
    myuser->team.points=points;
    myuser->resuming=true;
    myuser->team.gamesplayed=gamesplayed;

    for (int i=0;i<nrplayers;i++){
        team0>>playername>>playersurname>>playerposition>>age>>height>>weight>>sprint>>rebound>>passing>>handling>>shooting>>stealing>>block>>jump>>strength>>motivation>>energy>>attack>>defence>>overallgeneral>>marketvalue>>photoloc1>>photoloc2;
        std::cout<<playername<<" "<<playersurname<<" "<<playerposition<<std::endl;
        std::cout<<age<<" "<<height<<" "<<weight<<" "<<sprint<<" "<<rebound<<" "<<passing<<" "<<handling<<" "<<shooting<<" "<<stealing<<" "<<block<<" "<<jump<<" "<<strength<<" "<<motivation<<" "<<energy<<" "<<attack<<" "<<defence<<" "<<overallgeneral<<" "<<marketvalue<<" "<<photoloc1+photoloc2<<std::endl;
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
        myuser->team.players[i].photoadress=QString::fromStdString(photoloc1+" "+photoloc2);
        myuser->team.update_overall();
    }
    for (int j=nrplayers;j<12;j++){
        myuser->team.players.erase(myuser->team.players.begin()+j-1);
    }
    team0.close();
    userfile.close();

    //update the ranking of the league
    league->ranking=league->teams;
    sort(league->ranking.begin(),league->ranking.end(),league->comparepoints);

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
