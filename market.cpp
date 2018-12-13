//
//  Market.cpp
//  Basketball
//


#include "Market.hpp"
Market::Market()
{
    for (int i=0; i<11; i++) {
        Player p=Player();
        Market::players.push_back(p); //initializes a list of players
    }
};
