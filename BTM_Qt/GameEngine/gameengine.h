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

    static std::vector<QString> highlight_0;
    static std::vector<QString> highlight_2;
    static std::vector<QString> highlight_3;

    //methods

    //simulates the games that the manager is not playing for the current League's week
    void simulateThisWeeksGames(League& league) const;

    //simulates a Game not involving the manager between two teams and update their attributes according to the final score
    void simulateAutomatedGame(League& league, Team team1, Team team2) const;

    //applies a tactic withtin a game played by the manager
    void applyTactic(Team& team, const std::string tacticName) const;

    //applies the default tactic to the manager's team while playing
    void getBacktoDefaultTactic(Team& playingTeam, Team& initTeam) const;

    //return a clone of the team
    Team copyTeam(Team team) const;

    //simulates the outcome of an attack/defence
    int getAttackResult(Team& managersTeam, Team& oppentsTeam, bool isManagerAttacking) const;

    //adds energy to players at the end of a quarter
    void endOfQuarterRest(User* manager, Team& managersTeam, Team& oppentsTeam) const;

    //updates the manager's status at the end of a match and return the reward
    int endOfMatchUpdate(User* manager, League* league, Team& opponentsTeam ,std::pair< int, int > score)const ;

    //returns a highlight depending on the outcome
    QString popMessage(Team& team, int outcome) const;

    //computes the points added to each team after simulate the week's games
    void updateThisWeeksRanking(League* league) const;


private:
    //returns the outcome of a automatic game (scoreOfTeam1, scoreOfTeam2)
    std::pair< int, int > getAutomaticWinner(const Team team1, const Team team2) const;

   //updates the attributes of the teams after a game according to its outcome
    void updateTeamsOverall(League& league, Team& team1, Team& team2, std::pair< int, int > score) const;

    //updates the team players after a match
    void setAfterMatchOverall(League& league,Team& team, const int change, const int motivationChange) const;

    void seachTeamAndUpdatePoints(League* league,std::string teamName, int points) const;

};

#endif // GAMEENGINE_H
