#pragma once

class Game
{
public:
		
		Game(int currentRound, int enemyLifePoints, int playerLifePoints);
		Game();

		int	getPlayerLifePoints(); 
		int setCurrentRound();
		int getEnemyPoints();

private:
	int _currentRound;
	int _enemyLifePoints;
	int _playerLifePoints;
};
