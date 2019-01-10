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
    typedef std::pair<Team&, Team&> Match;
    typedef std::vector<Match> MatchVector;

    //attributes
    int division;
    std::string season;
    std::vector<Team> teams;
    //constructors
    League(int div, std::string seas);
    League();
    //functions
    std::map<int, std::vector< std::tuple<int,int> > > calendar();
    std::map<int, std::vector< std::tuple<int,int> > > Calendar;
    int current_week;
    std::vector<Player> playermarket;

    const std::vector<std::pair<Team&, Team&>> getThisWeeksGames(){}
};

#endif // LEAGUE_H
