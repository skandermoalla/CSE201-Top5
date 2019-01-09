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
    update_overall();
};

void Team::Training1(){     //defesive training
    for (int i=0; i<12 ; i++){
        double r = ((double) rand() / (RAND_MAX));
        if (r<=0.5){
            players[i].rebound+=2;
            players[i].stealing+=1;
            players[i].strength+=1;
            players[i].block+=1;
        }
        players[i].energy-=10;
        players[i].update_overall();
    }
    update_overall();

};
void Team::Training2(){     //shooting training
    for (int i=0; i<12 ; i++){
        double r = ((double) rand() / (RAND_MAX));
        if (r<=0.6){
            players[i].shooting+=2;
            players[i].jump+=1;
            players[i].passing+=1;
            players[i].handling+=1;
        }
        players[i].energy-=14;
        players[i].update_overall();
    }
    update_overall();

};
void Team::Training3(){     //Physical training
    for (int i=0; i<12 ; i++){
        double r = ((double) rand() / (RAND_MAX));
        if (r<=0.7){
            players[i].strength+=2;
       }
        if (r<=0.3){
            players[i].jump+=2;
            players[i].passing+=2;
            players[i].sprint+=3;
       }
        if (r<=0.2){
            players[i].handling+=2;
       }
        players[i].energy-=18;
        players[i].update_overall();
    }
    update_overall();

};
void Team::Training4(){     //Physical training
    for (int i=0; i<12 ; i++){
        double r = ((double) rand() / (RAND_MAX));
        if (r<=0.7){
            players[i].motivation+=4;
       }
        if (r<=0.2){
            players[i].jump+=2;
            players[i].passing+=2;
            players[i].sprint+=3;
       }
        if (r<=0.2){
            players[i].handling+=2;
            players[i].shooting+=1;
            players[i].rebound+=1;
       }
        players[i].energy-=5;
        players[i].update_overall();
    }
    update_overall();

};


void Team::update_overall(){
    age=0;
    height=0;
    weight=0;
    sprint=0;
    rebound=0;
    passing=0;
    handling=0;
    shooting=0;
    stealing=0;
    block=0;
    jump=0;
    strength=0;
    motivation=0;
    energy=0;
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
    overallgeneral = sprint*0.1 + rebound*0.05 + passing*0.15 + handling*0.15 + shooting*0.2 + stealing*0.05 + block*0.05 + jump*0.1 +strength*0.15;
}
