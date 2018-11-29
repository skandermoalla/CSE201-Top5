#include "League.hpp"
#include <string>

//random names for teams to be changed as well
std::list teamNames = {"Lakers","Cavaliers","Raptors","Warriors","Thunders","76ers","Bulls","Wizards","Celtics","Pacers","Nets","Hawks"};


League::League(int div, std::string seas){          //Takes arguments : division as an int and a season as a string
    division = division;
    season = seas;
    for (int i=0, i<12, i++){
        Team t=Team( teamNames[rand()%12] );   
        League::teams.push_back(t);
    }
}


League::calendar() {

}