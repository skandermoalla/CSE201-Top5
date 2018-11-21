//
//  Player.cpp
//  CSE Project
//
//  Created by Edison Reshketa on 19/11/2018.
//  Copyright © 2018 Edison Reshketa. All rights reserved.
//

#include "Player.hpp"

std::string names[]={"edison","skander","michael","khoa","mamoun","yassine"};
std::string surnames[]={"edison","skander","michael","khoa","mamoun","yassine"};
std::string positions[]={"PG","SG","F","PF","C"};
player::player(std::string pos)
{
    //choose a random numbers to select a surname
    int randomname=rand()%(sizeof(names)/sizeof(names[0]));
    name=names[randomname];
    //choose a random number to select a surname
    int randomsurname=rand()%(sizeof(surnames)/sizeof(surnames));
    surname=names[randomsurname];
    
    //position initialization
    position=pos;
    
    //generate a random number in [18,30] for the age of the player;
    age=rand()%13 + 18;
    
    //generate a random  number for the height in an interval which depends on the player position
    if (position=="PG")
        height=rand()%11 + 180;
    else if (position=="SG")
        height=rand()%11 + 185;
    else if (position=="F")
        height=rand()%11 + 190;
    else if (position=="PG")
        height=rand()%11 + 195;
    else
        height=rand()%11+203;
    
    
    
};

player::player()
{
    
}

