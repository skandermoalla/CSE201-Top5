//
//  Update_Teams.cpp
//
//
//  Written by Kevin on Dec 13th 9:30.
//   
//  To be used for both interactive games and non-interative games
//  A function that updates the overall attribute of 2 teams after a game.



#include <cmath>

void UpdateTeams(Team1,Team2,Winner){
    double Score1 = Team1.getOverall();
    double Score2 = Team2.getOverall();
    double ScoreMean = (Score1 + Score2)/2;
    double Q1 = pow(10.0,Score1/30);
    double Q2 = pow(10.0,Score2/30);
    double Exp = Q1/(Q1+Q2); //expectance for team1, between 0 and 1

    double Kfactor(Score){
        return 0.3*(100 - Score);
    }                      //K factor (to be improved), teams with higher scores gets smaller modifications
       
    if (Winner == 1){
        double Score1New = Score1 + (1-Exp)*KFactor(Score1);  
        double Score2New = Score2 - (1-Exp)*KFactor(ScoreMean);
    }

    else{
        double Score1New = Score1 - Exp*KFactor(ScoreMean);
        double Score2New = Score2 + Exp*KFactor(Score2);
    }

    if (Score1New < 10){          //set the minimum as 10 to prevent negative values
        Score1New = 10;
    }
    if (Score2New < 10){
        Score2New = 10;
    }
        
    Team1.setOverall(Score1New);
    Team2.setOverall(Score2New);
}