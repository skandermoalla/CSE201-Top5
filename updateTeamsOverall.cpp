#include <cmath>


void GameEngine::updateTeamsOverall(League& league, Team& team1, Team& team2, std::pair<int, int> score){

    double ov1 = team1.overallgeneral;
    double ov2 = team2.overallgeneral;
    double ovMean = (ov1 + ov2)/2;
    double Q1 = std::pow(10.0,ov1/30);
    double Q2 = std::pow(10.0,ov2/30);
    double Exp = Q1/(Q1+Q2); //expectance for team1, between 0 and 1

    double Kfactor(double overall){
        return 0.3*(100 - overall);
    }                      //K factor (to be improved), teams with higher scores gets smaller modifications
       
    if score[1] > score[0]{
        double ov1New = ov1 + (1-Exp)*KFactor(ov1);  
        double ov2New = ov2 - (1-Exp)*KFactor(ovMean);
    }

    else{
        double ov1New = ov1 - Exp*KFactor(ovMean);
        double ov2New = ov2 + Exp*KFactor(ov2);
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
    
    void GameEngine::setOverall(Team& team, double overallNew, double overall) {
        for (int i=0; i<12 ; i++){
            team.players[i].afterMatchUpdate(overallNew-overall);
            team.update_overall();
    }

    team1.setOverall(ov1New, ov1);
    team2.setOverall(ov2New, ov2);
}

