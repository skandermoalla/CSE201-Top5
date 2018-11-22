#pragma once
#include "Player.cpp"
#include <iostream>
#include <string>
using std namespace 

class Team {
    public:
        string name;
        std::list<Player> players;
        double attack;
        double defence;
        double motivation;
        double sprint;
        double rebound;
        double passing;
        double handling;
        double attributes = {attack,defence,motivation,sprint,rebound,passing,handling};  //array of all numeral attributes of the Team to use in methods

    int age;
    int height;
    int weight;
    int sprint;
    int rebound;
    int passing;
    int handling;
    int shooting;
    int stealing;
    int block;
    int jump;
    int strength;
    double overall;
        Team(string na,double attributes);  //Constructs a Team
        void Training(); //Trains team by increasing attributes



}
