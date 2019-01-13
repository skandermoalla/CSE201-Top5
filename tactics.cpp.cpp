#include "Team.hpp"

void tactic(t, Team team){   // t is a tactic chosen by the manager of the team  

if (t == 'Attack'){
    Team.attack += 5;
    Team.energy -= 2;
    Team.defence -= 3;
}

if (t == 'Defence'){
    Team.attack -= 5;
    Team.defence += 5;
}

if (t == 'Motivation'){
    Team.energy -= 3;
    Team.motivation += 3;
}

if (t == 'foot break'){
    Team.defence += 2;
    Team.motivation += 2;
    Team.energy -= 2;
    Team.attack -= 2;
}




}