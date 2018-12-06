#pragma once
#include "League.hpp"
#include "Team.hpp"
class GameEngine {
    private:
        int getAutomaticWinner(League league, Team team1, Team team2);
        void updateTeams(Team team1, Team team2, int winner);
        void updateLeague(League league, Team team1, Team team2, int winner);
    public:
        void playAutomatedGame(League league, Team team1, Team team2);
        void playSimulatedGame(League league, Manager manager, Team oppTeam);
}