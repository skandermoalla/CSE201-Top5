#ifndef LEAGUE_H
#define LEAGUE_H


#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include "Team.h"
#pragma once
class League{   //has 12 teams competing during 22 weeks
public:
    //attributes
    int division;
    std::string season;
    std::vector<Team> teams;
    int current_week;  //Warning!! Starts at week 1


    //constructors
    League(int div, std::string seas);
    League();

    //functions
    std::map<int, std::vector< std::tuple<int,int> > > calendar();
    std::map<int, std::vector< std::tuple<int,int> > > Calendar;

    //needed for the GameEngine asap plz
    //a vector < (team1*, team2*), (team1*, team2*), ...> of pairs of pointers to teams playing against each other
    std::vector<std::pair<Team*, Team*>> getThisWeeksGames();

};

#endif // LEAGUE_H
