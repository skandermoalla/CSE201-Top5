#include <map>
#include <string>
#include <iterator>
#include <League.cpp>
#include <list>

std::map<int, std::string> calendar;

for (int i=0; i<7; i++) {
    std::list<string> matches_of_week;
    if (i != 6) {
        matches_of_week.push_back(League.teams[i]+"vs"+League.teams[i+1]); 
    }
    else {
        matches_of_week.push_back (League.teams[i]+"vs"+League.teams[0]);
    }
}

for (int i = 1; i < 23; i++) {
        calendar.insert(std::make_pair (i, matches_of_week[i-1]));
    }



