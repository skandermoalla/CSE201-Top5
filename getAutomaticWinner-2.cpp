#include <iostream>
#include "Team.hpp"
#include <cstdlib>

/* A function that returns the winner of the automated game: either 0 (for Team1) or 1 (for Team2) using a probabilistic approach
depending on the overall attribute of each team. 
*/

const int NUMBER_OF_DRAWS = 100;

int getAutomaticWinner(const Team Team1, const Team Team2) {

    const int total_1 = Team1.getOverall;      //an integer between 0 and 100
    const int total_2 = Team2.getOverall;
    const double p1 = total_1 / 100;                 //A number between 0 and 1
    const double p2 = total_2 / 100;


    int c1 = 0;      //A counter to count the points that will make a team win
    int c2 = 0;

    for (int i =0; i<NUMBER_OF_DRAWS; i++){
        const double r = double(rand()) / (RAND_MAX);        //A random number between 0 and 1
        if (r < p1) {
            c1++
            } 
        if (r < p2){
            c2++
        }
    }

    if (c1 == c2){          //in case c1 = c2, the teams are really close in level, so we toss a toin to get the winner
       const double coin = (double) rand() / (RAND_MAX) ;
       if (coin < 0.5){
           return 0
           else{
               return 1
           }
       }

    }

    if (c1 < c2){
        return 1
    else{
        return 0
    }
    }



}
