#include "GameEngine.hpp"

void GameEngine::playAutomatedGame(League league, Team team1, Team team2) {
    int winner = getAutomaticWinner(team1, team2);
    updateTeams(team1, team2, winner);
    updateLeague(league, team1, team2, winner);
    }

void GameEngine::playSimulatedGame(League league, Manager manager, Team oppTeam) {
    int winner = getSimulatedWinner(manager, oppTeam);
    updateTeams(manager.team, oppTeam, winner);
    updateLeague(league, manager.team, oppTeam, winner);
}