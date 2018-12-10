//
//  Market.cpp
//  Basketball
//
//  Created by Edison Reshketa on 10/12/2018.
//  Copyright © 2018 Edison Reshketa. All rights reserved.
//

#include "Market.hpp"
Market::Market()
{
    for (int i=0; i<11; i++) {
        Player p=Player();
        Market::players.push_back(p); //initializes a list of players
    }
};
