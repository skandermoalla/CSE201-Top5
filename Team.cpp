#pragma once

#include "Team.hpp"
#include <iostream>
#include <string>
#include <list>
#include <cmath>

Team::Team(string na){ //takes a name and a list of attributes following this form (attack,defence,motivation)
    name = na;
    for (int i=0, i<12 , i++){
        Team::players.push_back(Player::Player());
    }
    for (int j=0, j<12, j++){
        attack += players[j].attack;
        defence += players[j].defence;
        sprint += players[j].sprint;
        rebound += players[j].rebound;
        passing += players[j].passing;
        handling += players[j].handling;
    }
    for(int l=0, l<12, l++){
        attributes[l] = attributes[l]/12; //equals the average of those same attributes for the players
    }
    motivation = 70;
}

void Team::Training(){     //increases team attributes by 1
    std::list<double> attributes;
    for( int i=, i<12, i++ ){
        attributes[i] +=1;
    }
}


