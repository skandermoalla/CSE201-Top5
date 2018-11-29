#pragma once
#include "Player.cpp"
#include <string>
#include <list>
#include <vector>

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
