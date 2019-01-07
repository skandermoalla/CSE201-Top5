
/*
The goal of the following algorithms is to build a function that returns the probability that the manager's team 
scores, or that the opponent team scores depending on the state of the game: attack or defense.
*/


#include <iostream>
#include <vector>
#include "Team.hpp"
#include <cstdlib>

int status(const int i){   // A function that returns the state of the game: 1 for attack and 0 for defence  
    if (i%2 == 1) {
        return 1;
    }
    else{
        return 0;
    }
}


void printStatus(const int i){ // A function that prints the status of the game
    const int stat = status(i);
    if (stat == 1){
        std::cout<< "The manager's team is attacking" << std::endl;
    }
    else{
       std::cout<< "The manager's team is defending" << std::endl; 
    }
}


/* 
This function returns the probability that the attacking team scores. The probability computed depends 
on the attack or defence caracteristics of each team; and on the strength of the manager's team. 
*/

double computeProbability(std::vector<Player> lpp, const int i, Team team2){ // lpp is the vector of the 5 players playing

    if (status(i) == 1){                                              // The manager's team is attacking

        int attackScore = 0;
        int strength = 0;
                                                          
        for (std::vector<Player>::iterator P = lpp.begin(); P = lpp.end(); P++){     //iterate on the vector of the
            attackScore += P.attack;                                           //5 players that are playing          
            strength += P.strength;
    }
    const double attackScore1 = attackScore/5;
    const double strength1 = strength/5;
    const int defence2 = Team2.defence;
    const double p = max(0, (attackScore1+strength1)/200 - defence2/300); 

    }
    else{                                                           // The manager's team is defending
        int defenceScore = 0;
        int strength = 0;

        for (std::vector<Player>::iterator P = lpp.begin(); P = lpp.end(); P++){
            defenceScore += P.defence;
            strength += P.strength;
    }
    const int attack2 = Team2.attack;
    const double strength1 = strength/5; 
    const double defenceScore1 = defenceScore/5;
    const double p = max(0, attack2 - (defenceScore1+strength1)/300); 
}
return p;
}
