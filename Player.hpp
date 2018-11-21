//
//  Player.hpp
//  CSE Project
//
//  Created by Edison Reshketa on 19/11/2018.
//  Copyright © 2018 Edison Reshketa. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp
#include <stdio.h>
#pragma once
#include <string>
#include <list>
class player{
public:
    //constuctors
    player();
    player(std::string pos);

    //player attributes
    std::string name;
    std::string surname;
    std::string position; // PG=pointguard SG=shootingguard F=forward PF=powerforward C=center
    int age;
    int height;
    int weight;
    int attack;
    int defene;
    int sprint;
    int rebound;
    int passing;
    int handling;
    int overall;

};

#endif /* Player_hpp */
