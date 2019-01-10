#ifndef GAMEENGINE_H
#define GAMEENGINE_H


#include "Team.h"
#include "Player.h"
#include "League.h"

class GameEngine
{
public:
    GameEngine();

    //methods

    //simulates the games that the manager is not playing for the current League's week
    void simulateThisWeeksGames(League& league);

    //simulates a Game not involving the manager between two teams and update their attributes according to the final score
    void simulateAutomatedGame(League& league, Team& team1, Team& team2);

    // (loading...)
    void playThisWeeksGame(League& league, Team& opponentsTeam);

private:
    //returns the outcome of a automatic game (scoreOfTeam1, scoreOfTeam2)
    std::pair<int, int> getAutomaticWinner(Team& team1, Team& team2);

   //updates the attributes of the teams after a game according to its outcome
    void updateTeamsOverall(League& league, Team& team1, Team& team2, std::pair<int, int> score);

};

#endif // GAMEENGINE_H
