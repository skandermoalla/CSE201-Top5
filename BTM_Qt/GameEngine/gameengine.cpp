#include "gameengine.h"
#include <memory>
GameEngine::GameEngine()
{

}

void GameEngine::simulateThisWeeksGames(League& league) const{
    const std::vector<std::pair<Team*, Team*>> thisWeeksGames = league.getThisWeeksGames();
    for (std::vector<std::pair<Team*, Team*>>::const_iterator i = thisWeeksGames.begin(); i != thisWeeksGames.end(); i++) {
        simulateAutomatedGame(league, *i->first, *i->second);
    }
}

void GameEngine::simulateAutomatedGame(League& league, Team& team1, Team& team2) const{
    std::pair<int, int> score = getAutomaticWinner(team1, team2);
    updateTeamsOverall(league, team1, team2, score);
}

void GameEngine::playThisWeeksGame(League& league, Team& opponentsTeam)const{

}

std::pair<int, int> GameEngine::getAutomaticWinner(const Team& team1, const Team& team2) const{

}

void GameEngine::updateTeamsOverall(League& league, Team& team1, Team& team2, std::pair<int, int> score) const {

}
