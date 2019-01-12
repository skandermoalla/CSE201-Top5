#include "gameengine.h"
#include <memory>
#include <cmath>
#include <cstdlib>

GameEngine::GameEngine()
{

}

void GameEngine::simulateThisWeeksGames(League& league) const{
    const std::vector< std::pair< Team, Team > > thisWeeksGames = league.getThisWeeksGames(); //pair of references already
    for (std::vector< std::pair< Team, Team > >::const_iterator i = thisWeeksGames.begin(); i != thisWeeksGames.end(); i++) {
        simulateAutomatedGame(league, i->first, i->second);
    }
}

void GameEngine::simulateAutomatedGame(League& league, Team team1, Team team2) const{
    std::pair< int, int > score = getAutomaticWinner(team1, team2);
    std::pair<Team, Team> match(team1,team2);
    //league.ThisWeeksScores.insert(std::pair< std::pair<Team, Team>, std::pair<int, int>>(match, score));
    league.ThisWeeksScores.push_back(score);
    updateTeamsOverall(league, team1, team2, score);
}

void GameEngine::playThisWeeksGame(User& manager, League& league, Team& opponentsTeam)const {

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
}                      //K factor (to be improved), teams with higher scores gets smaller modifications


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
