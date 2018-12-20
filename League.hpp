//
//  League.hpp
//  Basketball
//


#ifndef League_hpp
#define League_hpp
#include "Market.hpp"
#include <stdio.h>
#include <vector>
#include <map>
class League{   //has 12 teams competing during 22 weeks
public:
    //attributes
    int division;
    std::string season;
    std::vector<Team> teams;
    std::string teamNames[1000];
    //constructors
    League(int div, std::string seas);
    
    //functions
    std::map<int, std::vector< std::tuple<int,int> > > calendar();
    std::vector<int> opponents_user();    
};

#endif /* League_hpp */
