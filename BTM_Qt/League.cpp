#include "League.h"
#include <utility>

//auxiliary function to find the intersection of two vectors

std::vector<int> intersection(const std::vector<int> vect1, const std::vector<int> vect2) {
    std::vector<int> intersect;
    for (std::vector<int>::const_iterator i = vect1.begin(); i != vect1.end(); i++) {
        for (std::vector<int>::const_iterator j = vect2.begin(); j != vect2.end(); j++) {
            if (*i == *j) {
                intersect.push_back(*i);
            }
        }
    }
    return intersect;
};
const std::string teamNames[] = { "Lakers","Cavaliers","Raptors","Warriors","Thunders","76ers","Bulls","Wizards","Celtics","Pacers","Nets","Hawks" };

League::League(int divi, std::string seas){          //Takes arguments : division as an int and a season as a string
    division = divi ;
    season = seas;
    int n = rand()%12 ;
    for (int i = 0; i < 12; i++) {
        Team t= Team( teamNames[(n + i) % 12] );
        League::teams.push_back(t);
    }
    for (int i=0; i<30 ; i++){
        playermarket.push_back(Player());
    }
}

League::League(){          //Takes arguments : division as an int and a season as a string
    division = 3 ;
    season = "1718";
    int n = rand()%12 ;
    for (int i = 0; i < 12; i++) {
        Team t= Team( teamNames[(n + i) % 12] );
        League::teams.push_back(t);
    }
    Calendar=calendar();
    current_week = 1;
    for (int i=0; i<30 ; i++){
        playermarket.push_back(Player());
    }
}

std::map<int, std::vector< std::tuple<int,int> > > League::calendar()
{
    std::map<int, std::vector< std::tuple<int, int> > > calendar;

    //creating map assigning its possible opponents to each team
    std::map<int, std::vector<int> > possibilities;
    for (int i = 1; i < 13; i++) {
        std::vector<int> teams = { 1,2,3,4,5,6,7,8,9,10,11,12 };
        teams.erase(teams.begin() + i - 1);
        possibilities[i] = teams;
    }

    //create list of matches for each week
    for (int w = 1; w < 23; w++) {
        std::vector<int> freeTeams = { 1,2,3,4,5,6,7,8,9,10,11,12 };
        while (freeTeams.size() > 0) {
            int t = freeTeams[0];

            std::vector<int> possible_opponents = intersection(freeTeams, possibilities[t] );

            int opponent = possible_opponents[0];  //taking the first possible and match-free opponent

            std::tuple<int, int> match = std::make_tuple(t, opponent);

            calendar[w].push_back(match);  //adding match to the list of matches of the week

            //deleting the teams which already have a match assigned to them
            freeTeams.erase(freeTeams.begin() + opponent - t);
            freeTeams.erase(freeTeams.begin());
        }
    }

    return calendar;
}


std::vector< int > League::getAllUserMatches() {
    std::vector< int > users_matches;
    for (int w = 1; w < 23; w++) {
        const std::vector< std::tuple<int,int> >& matches= this->Calendar[w];

        for (int i = 0; i < 12 ; i++) {
            const std::tuple<int,int>& match = matches[i];
            int t1= std::get<0>(match);
            int t2= std::get<1>(match);
            if(t1==1){
                users_matches.push_back( t2 );
            }
            if(t2==1){
                users_matches.push_back( t1 );
            }
        }
    }
    return users_matches;

}

/*const std::vector<std::pair<Team, Team>> League::getThisWeeksGames(){
    std::vector< std::tuple<int,int> > matches= this->Calendar[current_week];
    std::vector<std::pair<Team, Team>> matches_return;
    for (int i = 0; i < 12 ; i++) {
        std::tuple<int,int>  match = matches[i];
        int t1= std::get<0>(match);
        int t2= std::get<1>(match);
        if( t1 == 1 || t2 == 1){   //Checking if team 1 (user's team) is in the match
            matches.erase(matches.begin() + i);  //Removing user's team from list of matches
        }
        else {
            std::pair< Team, Team > match_return;
            match_return = std::make_pair(this->teams[t1-1], this->teams[t2-1]);
            matches_return.push_back(match_return);
        }


    }
    return matches_return;
}*/






