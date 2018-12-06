#include "League.hpp"
#include <string>
#include <list>

//random names for teams to be changed as well
std::list teamNames = {"Lakers","Cavaliers","Raptors","Warriors","Thunders","76ers","Bulls","Wizards","Celtics","Pacers","Nets","Hawks"};


League::League(int divi, std::string seas){          //Takes arguments : division as an int and a season as a string
    division = divi ;
    season = seas;
    for (int i=0, i<12, i++){
        Team t=Team( teamNames[rand()%12] );   
        League::teams.push_back(t);
    }

    /*std::map<std::string, double,std::list> attributes;
    attributes["season"] = seas;
    attributes["division"] = divi;
    */
}


League::calendar() {
    std::map<int,std::list> calendar;
    for (int i, i=0, i<12, i++){   //iterating over each team
        for (int w, w=1, w++){   //iterating over all weeks for each team
        std::string match= teams[i].name +' vs. '+ teams[w%11].name ;
        calendar[w].push_back(match);
        }
    }
    return calendar;
}


