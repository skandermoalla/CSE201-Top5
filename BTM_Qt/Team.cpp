#include "Team.h"

Team::Team(std::string na){ //takes a name
    name = na;
    for (int i=0; i<12 ; i++){
        Player p=Player();
        players.push_back(p);
    }
/*    division = League.division;
    for (int j=0; j<12; j++)
        players[j].division = division; */
    for (int j=0; j<12; j++){
        age += players[j].age;
        height += players[j].height;
        weight += players[j].weight;

        sprint += players[j].sprint;
        rebound += players[j].rebound;
        passing += players[j].passing;
        handling += players[j].handling;

        shooting += players[j].shooting;
        stealing += players[j].stealing;
        block += players[j].block;
        jump += players[j].jump;
        strength += players[j].strength;
        motivation += players[j].motivation;
        energy += players[j].energy;
    }
    age = age/12;
    height = height/12 ;
    weight = weight/12;

    attack =attack/12;
    defence =defence/12;
    sprint =sprint/12;
    rebound =rebound/12;
    passing =passing/12;
    handling = handling/12;

    shooting = shooting/12;
    stealing = stealing/12;
    block = block/12;
    jump = jump/12;
    strength = strength/12;
    motivation = motivation/12;
    update_overall();
};
Team::Team(){ //takes a name
    name = "RANDOM";
    for (int i=0; i<12 ; i++){
        Player p=Player();
        players.push_back(p);
    }
/*    division = League.division;
    for (int j=0; j<12; j++)
        players[j].division = division; */
    for (int j=0; j<12; j++){
        age += players[j].age;
        height += players[j].height;
        weight += players[j].weight;

        sprint += players[j].sprint;
        rebound += players[j].rebound;
        passing += players[j].passing;
        handling += players[j].handling;

        shooting += players[j].shooting;
        stealing += players[j].stealing;
        block += players[j].block;
        jump += players[j].jump;
        strength += players[j].strength;
        motivation += players[j].motivation;
        energy += players[j].energy;
    }
    age = age/12;
    height = height/12 ;
    weight = weight/12;

    attack =attack/12;
    defence =defence/12;
    sprint =sprint/12;
    rebound =rebound/12;
    passing =passing/12;
    handling = handling/12;

    shooting = shooting/12;
    stealing = stealing/12;
    block = block/12;
    jump = jump/12;
    strength = strength/12;
    motivation = motivation/12;
    update_overall();
};

void Team::Training(){     //increases team attributes by 1
    attack += 1;
    defence += 1;
    sprint += 1;
    rebound += 1;
    passing += 1;
    handling += 1;

    shooting += 1;
    stealing += 1;
    block += 1;
    jump += 1;
    strength += 1;
    motivation += 1;
};

void Team::update_overall(){
     overallgeneral = sprint*0.1 + rebound*0.05 + passing*0.15 + handling*0.15 + shooting*0.2 + stealing*0.05 + block*0.05 + jump*0.1 +strength*0.15;
}
