#ifndef GAMEENGINE_H
#define GAMEENGINE_H


#include "Team.h"
#include "Player.h"
#include "League.h"
#include "User.h"

//Testing the new branch

class GameEngine
{
public:
    GameEngine();

    static std::map<std::string, int(*)[11]> tactics;
    static int FullCourtPress[11];
    static int FastBreak[11];
    static int ZoneDefence[11];
    static int FullTimeAttack[11];

    //methods

    //simulates the games that the manager is not playing for the current League's week
    void simulateThisWeeksGames(League& league) const;

    //simulates a Game not involving the manager between two teams and update their attributes according to the final score
    void simulateAutomatedGame(League& league, Team team1, Team team2) const;

    // (loading...)
    void playThisWeeksGame(User& manager, League& league, Team& opponentsTeam) const;

    void applyTactic(Team& team, const std::string tacticName) const;

    void getBacktoDefaultTactic(Team& playingTeam, Team& initTeam) const;

    Team copyTeam(Team team) const;

    int getAttackResult(Team& managersTeam, Team& oppentsTeam, bool isManagerAttacking) const;

    void endOfQuarterRest(User* manager, Team& managersTeam, Team& oppentsTeam) const;

    void endOfMatchUpdate(User* manager, League& league, Team& opponentsTeam ,std::pair< int, int > score)const ;


private:
    //returns the outcome of a automatic game (scoreOfTeam1, scoreOfTeam2)
    std::pair< int, int > getAutomaticWinner(const Team team1, const Team team2) const;

   //updates the attributes of the teams after a game according to its outcome
    void updateTeamsOverall(League& league, Team& team1, Team& team2, std::pair< int, int > score) const;

    void setAfterMatchOverall(League& league,Team& team, const int change, const int motivationChange) const;


};

#endif // GAMEENGINE_H
