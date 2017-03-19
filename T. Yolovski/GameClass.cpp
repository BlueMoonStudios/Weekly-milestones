#include "GameClass.h"

Game::Game()
{
};

Game::Game(int currentRound, int enemyLifePoints, int playerLifePoints)
{
	currentRound = 0;
	enemyLifePoints = 20;
	playerLifePoints = 30;
};


int Game::getPlayerLifePoints()
{
	return _playerLifePoints;
}

int Game::setCurrentRound()
{
	_currentRound++;
	return _currentRound;
}

int Game::getEnemyPoints()
{
	return _enemyLifePoints;
}
