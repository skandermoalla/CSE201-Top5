// created by Joan Odeimi


#include "getAutomaticWinner-2.hpp"
#include <iostream>
#include "Team.h"
#include <cstdlib>
#include "League.h"

/* A function that returns the winner of the automated game and give the final score using a probabilistic approach
 depending on the overall attribute of each team.
 */

const int NUMBER_OF_DRAWS = 40;

std::pair<int, int> getAutomaticWinner(const Team Team1, const Team Team2) { //return a pair of scores ()
    
    const double total_1 = Team1.overallgeneral;      //an integer between 0 and 100
    const double total_2 = Team2.overallgeneral;
    const double p1 = total_1 / (total_1+total_2); //A number between 0 and 1
    /* const double p2 = total_2 / (total_1+total_2); */
    
    int c1 = 0;      //A counter to count the points that will make a team win
    int c2 = 0;
    
    for (int i =0; i<NUMBER_OF_DRAWS; i++){
        const double r = double(rand()) / (RAND_MAX);//A random number between 0 and 1
        if (r <= p1) {
            if (0.3 < r){
                c1 += 3;
            }
            else {
                c1 += 2;}
        }
        if (r > p1){
            if (0.3 < r){
                c2 += 3;
            }
            else {
                c2 += 2;}
        }
    }

    pair<int, int> t(c1, c2);
    return t;
}



/*
int main() {

}
*/
    

