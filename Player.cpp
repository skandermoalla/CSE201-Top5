//
//  Player.cpp
//  CSE Project
//
//  Created by Edison Reshketa on 19/11/2018.
//  Copyright © 2018 Edison Reshketa. All rights reserved.
//

#include "Player.hpp"

//names and surnames need to be updated.
std::string names[]={"edison","skander","michael","khoa","mamoun","yassine"};
std::string surnames[]={"edison","skander","michael","khoa","mamoun","yassine"};
std::string positions[]={"PG","SG","F","PF","C"};

//constructor when player position is not given
player::player()
{
    //choose a random numbers to select a surname
    int randomname=rand()%(sizeof(names)/sizeof(names[0]));
    name=names[randomname];
    
    //choose a random number to select a surname
    int randomsurname=rand()%(sizeof(surnames)/sizeof(surnames));
    surname=names[randomsurname];
    
    //position initialization
    position=positions[rand()%5];
    
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
    
    //generate a random number for the weight in an interval(0.9*height , 1.1*height)
    weight=rand()%(int(floor((height-100)*0.2))) + ((height-100)*0.9);
    
    //the next attributes have to depend on the league level when creating new players
    //for beginning we let the interval be [40,60]. It will be changed after.
    //we should work on these to make them more biased according to the player position.
    sprint=rand()%21 + 40;
    rebound=rand()%21 + 40;
    passing=rand()%21 + 40;
    handling=rand()%21 + 40;
    shooting=rand()%21 + 40;
    stealing=rand()%21 + 40;
    block=rand()%21 + 40;
    jump=rand()%21 + 40;
    strength=rand()%21 + 40;
}


//constructor when the player position is given
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
    
    //generate a random number for the weight in an interval(0.9*height , 1.1*height)
    weight=rand()%(int(floor((height-100)*0.2))) + ((height-100)*0.9);
    
    //the next attributes have to depend on the league level when creating new players
    //for beginning we let the interval be [40,60]. It will be changed after.
    //we should work on these to make them more biased according to the player position.
    sprint=rand()%21 + 40;
    rebound=rand()%21 + 40;
    passing=rand()%21 + 40;
    handling=rand()%21 + 40;
    shooting=rand()%21 + 40;
    stealing=rand()%21 + 40;
    block=rand()%21 + 40;
    jump=rand()%21 + 40;
    strength=rand()%21 + 40;

    market_value //TBD depending on the overall & the league division. 
};

