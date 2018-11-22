#pragma once
#include "Team.hpp"
#include <string>
#include <list>


Team::Team(std::string na){ //takes a name and a list of attributes following this form (attack,defence,motivation)
    name = na;
    for (int i=0, i<12 , i++){
        Team::players.push_back(Player::Player());
    }
    for (int j=0, j<12, j++){
        age += players[j].age;
        height += players[j].height;
        weight += players[j].weight;
        
        attack += players[j].attack;
        defence += players[j].defence;
        sprint += players[j].sprint;
        rebound += players[j].rebound;
        passing += players[j].passing;
        handling += players[j].handling;

        shooting += players[j].shooting;
        stealing += players[j].stealing;
        block += players[j].block;
        jump += players[j].jump;
        strength += players[j].strength;
    }
    for(int l=0, l<12, l++){
        attributes[l] = attributes[l]/12; //equals the average of those same attributes for the players
    }
    motivation = 70; // arbitrary value chosen for the motivation of the team
}

void Team::Training(){     //increases team attributes by 1
    std::list<double> attributes;
    for( int i=, i<12, i++ ){
        attributes[i] +=1;
    }
}


