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

    //constructors
    League(int div, std::string seas);
    League();

    //functions
    std::map<int, std::vector< std::pair<int,int> > > calendar();
    std::map<int, std::vector< std::pair<int,int> > > Calendar;
    int current_week;  //starts at 1 !!!
    std::vector<Player> playermarket;

    //scores of the games of the current week in the same order they are present in the calendar (not involving the user)
    std::vector< std::pair<int, int>> ThisWeeksScores;
    std::vector< std::pair<Team, Team> > ThisWeeksGames;

    const std::vector< std::pair<Team, Team> > getThisWeeksGames();
    std::vector<int> getAllUserMatches();  //a function who gets matches of user for each week

    Team& getThisWeeksOpponentTeam();  //gets this week's user opponent

};

#endif // LEAGUE_H
