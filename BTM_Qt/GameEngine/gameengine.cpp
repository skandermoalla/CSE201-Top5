#include "gameengine.h"

GameEngine::GameEngine()
{

}

void GameEngine::simulateThisWeeksGames(League& league){
    std::vector<std::pair<Team*, Team*>> thisWeeksGames = league.getThisWeeksGames();
    for (std::vector<std::pair<Team*, Team*>>::iterator i = thisWeeksGames.begin(); i != thisWeeksGames.end(); i++) {
        Team* team1 = (*i).first;
        Team* team2 = (*i).second;
    }
}

void GameEngine::simulateAutomatedGame(League& league, Team& team1, Team& team2){

}

void GameEngine::playThisWeeksGame(League& league, Team& opponentsTeam){

}

std::pair<int, int> GameEngine::getAutomaticWinner(Team& team1, Team& team2){

}

void GameEngine::updateTeamsOverall(League& league, Team& team1, Team& team2, std::pair<int, int> score){

}
