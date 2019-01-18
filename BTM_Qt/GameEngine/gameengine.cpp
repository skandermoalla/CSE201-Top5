#include "gameengine.h"
#include <memory>
#include <cmath>
#include <cstdlib>
#include <QDebug>
#include <map>
#include <string>
#include <iostream>

//GameEngine::tacticIdentifier[11] = {energy, motivation, shooting, stealing, sprint, rebound, passing, handling, block, jump, strength}
int GameEngine::FullCourtPress[11] = {-15,2,-1,5,2,3,0,0,5,0,4};
int GameEngine::FastBreak[11] = {-10,3,5,3,3,2,-2,+2,0,0,-2};
int GameEngine::ZoneDefence[11] = {-5,0,2,3,2,5,-3,0,-2,4,-2};
int GameEngine::FullTimeAttack[11] = {-10,5,4,0,-1,1,3,2,0,0,-1};

// map of tactics
std::map< std::string, int(*)[11] > GameEngine::tactics {
    {"FullCourtPress", &FullCourtPress},
    {"FastBreak", &FastBreak},
    {"ZoneDefence", &ZoneDefence},
    {"FullTimeAttack", &FullTimeAttack}
};

std::vector<QString> GameEngine::highlight_2 ={
    "What a dunk!!",
    "A nice finish with an acrobatic layup!",
    "Long two pointer!",
    "He comes up with the deuce!",
    "He slammed it home!","Up and in!",
    "Beautiful finish with the floater!",
    "BBQ Chicken Alert!!!",
    "Pull up jumper good!",
    "Driving baseline, it's good!"};

std::vector<QString> GameEngine::highlight_3 ={
    "Hits it from distance!",
    "Good from the perimeter!",
    "Nice 3 pointer!",
    "He lets it fly and it's good!",
    "Stepback 3!",
    "From 30 feets out!",
    "Knocks it down!",
    "Good from Curry range!",
    "Good from the hash!",
    "He banks home the 3!"};

std::vector<QString> GameEngine::highlight_0 ={
    "Missed it!",
    "Won't go in!",
    "Too bad he missed the shot!",
    "He gets rejected!",
    "Comes up empty!",
    "Airball!",
    "He got stripped",
    "It's a miss!",
    "He got blocked!",
    "No basket"};


GameEngine::GameEngine()
{
    qDebug()<<"Game Engine ready";

}

void GameEngine::simulateThisWeeksGames(League& league) const{
    const std::vector< std::pair< Team, Team > > thisWeeksGames = league.getThisWeeksGames(); //pair of references already
    for (std::vector< std::pair< Team, Team > >::const_iterator i = thisWeeksGames.begin(); i != thisWeeksGames.end(); i++) {
        simulateAutomatedGame(league, i->first, i->second);
    }
}

void GameEngine::simulateAutomatedGame(League& league, Team team1, Team team2) const{
    //Simulate the game and get its score
    std::pair< int, int > score = getAutomaticWinner(team1, team2);

    //record the score in the league scores
    league.ThisWeeksScores.push_back(score);

    //update the team players according to the game results
    updateTeamsOverall(league, team1, team2, score);
}


std::pair< int, int > GameEngine::getAutomaticWinner(const Team team1, const Team team2) const{
    const int NUMBER_OF_DRAWS = 40;

    const double total_1 = team1.overallgeneral;      //an integer between 0 and 100
    const double total_2 = team2.overallgeneral;

    const double p1 = total_1 / (total_1+total_2);
                                                                               //A number between 0 and 1
    // const double p2 = total_2 / (total_1+total_2);

    int c1 = 0;      //A counter to count the points that will make a team win
    int c2 = 0;

    double r;

    for (int i =0; i<NUMBER_OF_DRAWS; i++){
        r = double(rand()) / (RAND_MAX);//A random number between 0 and 1
        //team 1 attacks
        if (r <= p1) {
            if (0.3 < r){
                c1 += 3;
            }
            else {
                c1 += 2;}
        }
        //team2 attacks
        r = double(rand()) / (RAND_MAX);//A random number between 0 and 1
        if (r > p1){
            if (0.3 < r){
                c2 += 3;
            }
            else {
                c2 += 2;}
        }
    }

    std::pair< int, int > t(c1, c2);
    return t;
}

double KFactor(double overall) {
    return 0.3*(100 - overall);
}                      //Teams with higher scores gets smaller modifications


void GameEngine::updateTeamsOverall(League& league, Team& team1, Team& team2, std::pair< int, int > score) const{

    double ov1 = team1.overallgeneral;
    double ov2 = team2.overallgeneral;
    double ovMean = (ov1 + ov2)/2;
    double Q1 = std::pow(10.0,ov1/30);
    double Q2 = std::pow(10.0,ov2/30);
    double Exp = Q1/(Q1+Q2); //expectance for team1, between 0 and 1



    double ov1New;
    double ov2New;
    int mc1;
    int mc2;

    if (score.second > score.first) {
        ov1New = ov1 + (1-Exp)*KFactor(ov1);
        ov2New = ov2 - (1-Exp)*KFactor(ovMean);
        mc1 = -10;
        mc2 = 10; //to edit
    }

    else{
        ov1New = ov1 - Exp*KFactor(ovMean);
        ov2New = ov2 + Exp*KFactor(ov2);
        mc1 = 10;
        mc2 = -10;
    }

    if (ov1New < 10){          //set the minimum as 10 to prevent negative values
        ov1New = 10;
    }
    if (ov2New < 10){
        ov2New = 10;
    }


    if (ov1New > 100){          //set the max as 100
        ov1New = 100;
    }
    if (ov2New > 100){
        ov2New = 100;
    }

    setAfterMatchOverall(league, team1, int(ov1New - ov1), mc1);
    setAfterMatchOverall(league, team2, int(ov2New - ov2), mc2);
}

void GameEngine::setAfterMatchOverall(League& league, Team& team, const int change, const int motivationChange) const {
    for (std::vector< Player >::iterator player = team.players.begin(); player != team.players.end(); player++){
        player->afterMatchUpdate(change, motivationChange);
        team.update_overall();
    }
}

void GameEngine::applyTactic(Team& team,const  std::string tacticName) const{
    // modifiers of attributes [sprint;rebound;passing;handling;shooting;

    // decrese energy of the first five players

    // update the attributes of the first five players

    for (std::vector<Player>::iterator player = team.players.begin(); player != team.players.begin()+5; player++) {
        player->energy += (*tactics[tacticName])[0];
        player->motivation += (*tactics[tacticName])[1];
        player->shooting += (*tactics[tacticName])[2];
        player->stealing += (*tactics[tacticName])[3];
        player->sprint += (*tactics[tacticName])[4];
        player->rebound += (*tactics[tacticName])[5];
        player->passing += (*tactics[tacticName])[6];
        player->handling += (*tactics[tacticName])[7];
        player->block += (*tactics[tacticName])[8];
        player->jump += (*tactics[tacticName])[9];
        player->strength += (*tactics[tacticName])[10];
    }
     team.update_overall();
}

void GameEngine::getBacktoDefaultTactic(Team& playingTeam, Team& initTeam) const {
    // copy init tean attributes to playing team attributes except from energy
    // do not decrease energy
    //assuming the players are in the same order

    for (std::vector<Player>::iterator playingPlayer = playingTeam.players.begin(), initPlayer = initTeam.players.begin();
         playingPlayer != playingTeam.players.end() && initPlayer != initTeam.players.end();
         playingPlayer++, initPlayer++){

        playingPlayer->stealing = initPlayer->stealing;
        playingPlayer->block = initPlayer->block;
        playingPlayer->sprint = initPlayer->sprint;
        playingPlayer->rebound = initPlayer->rebound;
        playingPlayer->strength = initPlayer->strength;
        playingPlayer->shooting = initPlayer->shooting;
        playingPlayer->handling = initPlayer->handling;
        playingPlayer->passing = initPlayer->passing;
        playingPlayer->jump = initPlayer->jump;
        playingPlayer->motivation = initPlayer->motivation;

        //motivation and energy are not copied
    }
    playingTeam.update_overall();

}

Team GameEngine::copyTeam(Team team) const{
    return team;
}

int GameEngine::getAttackResult(Team& managersTeam, Team& oppentsTeam, bool isManagerAttacking) const{

    //get the players playing in managers team (first 5 in the list)
    //get the average attributes

    //same for opponents team but take all the players, (already strored in the team)

    // attack: (0.5*shooting, 0.05*sprint, 0.1*rebound, 0.2*passing, 0.15*block)
    //defense: (0.5*rebound, 0.3*stealing, 0.2*jump)

    double indAtt = 0;  //out of 100
    double indDef = 0;  //out of 100
    if (isManagerAttacking){
        for (std::vector< Player >::iterator player = managersTeam.players.begin(); player != managersTeam.players.begin()+5; player++){
            indAtt += (0.5*player->shooting + 0.05*player->sprint + 0.1*player->rebound + 0.2*player->passing + 0.15*player->block)*player->energy/100;

            qDebug()<<"manager's team member's enegery" << player->energy;
        }
        indAtt /= 5;
        indDef += (0.5*oppentsTeam.rebound + 0.3*oppentsTeam.stealing + 0.2*oppentsTeam.jump)*oppentsTeam.energy/100;
    qDebug()<<"opponents team energy" << oppentsTeam.energy;
    }
    else{
        for (std::vector< Player >::iterator player = managersTeam.players.begin(); player != managersTeam.players.begin()+5; player++){
            indDef += (0.5*player->rebound + 0.3*player->stealing + 0.2*player->jump)*player->energy/100;
        }
        indDef /= 5;
        indAtt += (0.5*oppentsTeam.shooting + 0.05*oppentsTeam.sprint + 0.1*oppentsTeam.rebound + 0.2*oppentsTeam.passing + 0.15*oppentsTeam.block)*oppentsTeam.energy/100;
    }

    qDebug()<<"indDef";
    qDebug()<<indDef;
    qDebug()<<"indAtt";
    qDebug()<<indAtt;


    //decrease the energy of the players playing (5first) for manager by some value
    // decrease energy of all players of opponents team
    // same total decrease

    for (std::vector< Player >::iterator player = managersTeam.players.begin(); player != managersTeam.players.begin()+5; player++){
        player->energy -= 2;
    }
    for (std::vector< Player >::iterator player = oppentsTeam.players.begin(); player != oppentsTeam.players.end(); player++){
        player->energy -= 2;
    }

    //do some Heuristics (include energy?) depending on whether it's attack or defence
    // return 0, 2, 3 respectively if attack failed, scored 2 points, scored 3points
    // optionally create a message " {playerName} scored a 3point! wow!! ... "
    double probSc = (1-log(1.25*indDef/indAtt))*indAtt/100; // <1 , can be negative
    qDebug()<< "probSc";
    qDebug()<< probSc;
    double r = (double)rand() / (RAND_MAX);
    qDebug()<<"r";
    qDebug()<<r;

    int res;

    if (r>=probSc){
        res =  0;
    }
    else if (r<probSc/3){
        res = 3;
    }
    else{
        res = 2;
    }

    //update both teams overall
    managersTeam.update_overall();
    oppentsTeam.update_overall();

    return res;
}

QString GameEngine::popMessage(Team& team, int outcome) const{
    QString message;
    if(outcome == 0){
        message = highlight_0[(std::rand()%10)] + " no points for " + QString::fromStdString(team.players[rand() % (4)].name) ;
    }
    else if (outcome == 2){
        message = highlight_2[(std::rand()%10)] + " 2 points from " + QString::fromStdString(team.players[rand() % (4)].name) ;
    }
    else {
        message = highlight_3[(std::rand()%10)] + " 3 points from " + QString::fromStdString(team.players[rand() % (4)].name) ;
    }
    return message;
};

void GameEngine::endOfQuarterRest(User* manager, Team& managersTeam, Team& oppentsTeam) const{
    //default tactic
    getBacktoDefaultTactic(managersTeam, manager->team);

    //Add 70 energy to the first 5 players
    for (std::vector< Player >::iterator player = managersTeam.players.begin(); player != managersTeam.players.begin()+5; player++){
        player->energy = std::min(player->energy+30, 100);
    }

    //Add 10 energy to the rest of the players
    for (std::vector< Player >::iterator player = managersTeam.players.begin()+5; player != managersTeam.players.end(); player++){
        player->energy = std::min(player->energy+10, 100);
    }

    //Add 30 energy to the players of the opponent team
    for (std::vector< Player >::iterator player = oppentsTeam.players.begin(); player != oppentsTeam.players.end(); player++){
        player->energy = std::min(player->energy+30, 100);
    }

    //update managers'team
    manager->team = copyTeam(managersTeam);
}

void GameEngine::endOfMatchUpdate(User *manager, League &league, Team &opponentsTeam, std::pair< int, int > score) const{
    updateTeamsOverall(league, manager->team, opponentsTeam, score);
    int reward;
    if (score.first > score.second) {
        reward = 1000; //To be modified.
    }
    else {
        reward = 200; //To be modified.
    }
    manager->budget += reward;
}
