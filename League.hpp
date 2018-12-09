#pragma once 
#include <string>
#include <map>
#include <tuple>
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
	std::map<int, std::list< std::tuple<int,int> > > calendar();
    
}

//Possible implementation of a get attribute function, would need to implement a dictionarry to get all the attributes values

/*template < typename T> T get_attribute(std::string attributeName){
	return attributes[attributeName];  //here attributes would be a dictionnary instead of a list
}

template <typename T> void set_attribute(std::string attributeName, T value){
	attributes[attributeName] = value;  //same comment as before for attributes
}

*/;
