#pragma once
class GameWorld
{
private:
	
	Vector2i _exitPos; // Position of the exit tile
	Vector2i _playerPos; // Position of the player tile
	std::vector<sf::Vector2i> _enemyPos; // Positions of the enemy tiles
	void setUpInitialState(); // Set up the initial state of the game world
	void setUpTiles(); // Set up the tiles in the game world
	void setUpEnemyPositions(); // Set up the enemy positions

public:
	int _gridlength;
	vector<vector<GameTile*>> _tiles; // 2D vector of GameTile pointers

	GameWorld();
};

