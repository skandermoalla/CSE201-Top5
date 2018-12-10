//
//  Team.hpp
//  Basketball
//
//  Created by Edison Reshketa on 10/12/2018.
//  Copyright © 2018 Edison Reshketa. All rights reserved.
//

#ifndef Team_hpp
#define Team_hpp
#include "Player.hpp"
#include <stdio.h>
#include <string>
#include <vector>
#pragma once
class Team {
public:
    Team(std::string na);
    std::string name;
    std::vector<Player> players;
    //All attributes are are the averages over all the players
    int division;
    double age;
    double height;
    double defence;
    double motivation;
    double sprint;
    double rebound;
    double passing;
    double handling;
    double shooting;
    double stealing;
    double block;
    double jump;
    double strength;
    double weight;
    double attack;
    double overall;
    double energy;
    void Training(); //Trains team by increasing attributes
    
    
    
};
#endif /* Team_hpp */
