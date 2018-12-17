//
//  interactive_game_1.cpp
//
//  Written by Kevin on Dec 13th 9:30.
//   
//  A function that plays an interactive game, returns the scores and winner.
//  More subfunctions to be added.

#include <list>
#include <iostream>
#include <cmath>


void PlayInteractive(TeamUser,Team2){   //team objects
    std::list <Player> lpp;   //list of players playing
    std::list <Player> lsp;   //list of substitute players
    int Score1 = 0;
    int Score2 = 0;
    int Winner = 0;

    void ChangePlayer(Team){

    }  //to be done. change lpp and lsp, interaction with user.

    void PrintScore(Score1,Score2){
    std::cout<<"The score is"<<Score1<<"vs"<<Score2<<std::endl;
    }

    void UpdateScore(prob,status){
    if (status == 1){
        Score1 += prob*8;
    }
    else {
        Score2 += prob*8;
    }
    }

    void UpdateEnergy(){
        for (std::list<Player>::iterator i=lpp.begin();i!=lpp.end();i++){
            i.energy -= 5;
        }
        for (std::list<Player>::iterator i=lsp.begin();i!=lsp.end();i++){
            i.energy += 5;
        }
    }

    void PlayRound(prob,status){
        UpdateScore(prob,status);    
        UpdateEnergy();
    }

    for (int i=0; i<30; i++){
        PrintScore(Score1,Score2);
        PrintStatus(i);
        ChangePlayer(UserTeam);

        int status = Status(i);
        compute_prob(lpp, status);
        PlayRound(compute_prob(),status);
    }

    if (Score1 < Score2){        
        Winner = 1;
    }
    if (Score1 = Score2){        //if the scores are equal, user wins
        Score1 += 1;
    }
    return (Score1,Score2,Winner);
}
