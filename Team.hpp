#pragma once
#include "Player.cpp"
#include <string>
#include <list>


class Team {
    public:
        std::string name;
        std::list<Player> players;
        //All attributes are are the averages over all the players
        int division;
        double age;
        double height;
        double weight;
        double attack;
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
        double overall;
        std::list<double> attributes = {attack,defence,motivation,sprint,rebound,passing,handling,shooting,stealing,block,jump,strength};  //array of all numeral attributes of the Team to use in methods

        Team(std::string na,double attributes);  //Constructs a Team
        void Training(); //Trains team by increasing attributes



}
