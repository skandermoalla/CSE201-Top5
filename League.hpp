#include <string>
#include <map>
#include "Team.cpp"

class League{   //has 12 teams competing during 22 weeks
    public:
    //attributes
    int division;
    std::string season;
    std::list<Team> teams;

    //constructors
    League(int div, std::string seas);
    
    //functions
    std::map calendar();
}