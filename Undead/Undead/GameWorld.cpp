#include <SFML/Graphics.hpp>
#include "GameWorld.h"

using namespace std;
using namespace sf;

void GameWorld::setUpInitialState()
{
	_exitPos = Vector2i(1, 0);
	_playerPos = Vector2i(_gridlength-1,_gridlength-1);
	setUpEnemyPositions();
	setUpTiles(); 
}

void GameWorld::setUpTiles()
{
	_tiles.clear();

	vector<GameTile*> primeiraRow;
	
	primeiraRow.push_back(new GameTile("/assets/backgrounds/background0.png", 100, 0, true, false));
	primeiraRow.push_back(new GameTile("/assets/backgrounds/background0.png", 200, 0, true, false));
	primeiraRow.push_back(new GameTile("/assets/backgrounds/background0.png", 300, 0, true, false));
	primeiraRow.push_back(new GameTile("/assets/backgrounds/background0.png", 400, 0, true, false));
	primeiraRow.push_back(new GameTile("/assets/backgrounds/background0.png", 500, 0, true, false));
	primeiraRow.push_back(new GameTile("/assets/backgrounds/background0.png", 600, 20, true, false));
	primeiraRow.push_back(new GameTile("/assets/backgrounds/background0.png", 700, 0, true, false));
	primeiraRow.push_back(new GameTile("/assets/backgrounds/background0.png", 800, 0, true, false));
	primeiraRow.push_back(new GameTile("/assets/backgrounds/background0.png", 900, 0, true, false));

	_tiles.push_back(primeiraRow);


	/*vector<GameTile*> firstRow;
	for (int i = 1; i < _gridlength; i++)
	{
		firstRow.push_back(new GameTile("/assets/backgrounds/background0.png", i * 100, 0, true, false));
	}
	_tiles.push_back(firstRow);*/
	
	vector<GameTile*> secondRow;
	for (int i = 0; i < _gridlength; i++)
	{
		if (i != 0)
		secondRow.push_back(new GameTile("/assets/backgrounds/background0.png", i * 100, 80, true, false));
		
	}
	_tiles.push_back(secondRow);

	vector<GameTile*> thirdRow;
	for (int i = 0; i < _gridlength; i++)
	{
		if (i != 0)
			thirdRow.push_back(new GameTile("/assets/backgrounds/background0.png", i * 100, 160, true, false));

	}
	_tiles.push_back(thirdRow);

	vector<GameTile*> fourthRow;
	for (int i = 0; i < _gridlength; i++)
	{
		if (i != 0)
			fourthRow.push_back(new GameTile("/assets/backgrounds/background0.png", i * 100, 240, true, false));

	}
	_tiles.push_back(fourthRow);

	vector<GameTile*> fifthRow;
	for (int i = 0; i < _gridlength; i++)
	{
		if (i != 0)
			fifthRow.push_back(new GameTile("/assets/backgrounds/background0.png", i * 100, 320, true, false));

	}
	_tiles.push_back(fifthRow);

	vector<GameTile*> sixthRow;
	for (int i = 0; i < _gridlength; i++)
	{
		if (i != 0)
			sixthRow.push_back(new GameTile("/assets/backgrounds/background0.png", i * 100, 400, true, false));

	}
	_tiles.push_back(sixthRow);

	vector<GameTile*> seventhRow;
	for (int i = 0; i < _gridlength; i++)
	{
		if (i != 0)
			seventhRow.push_back(new GameTile("/assets/backgrounds/background0.png", i * 100, 480, true, false));

	}
	_tiles.push_back(seventhRow);

	vector<GameTile*> eighthRow;
	for (int i = 0; i < _gridlength; i++)
	{
		if (i != 0)
			eighthRow.push_back(new GameTile("/assets/backgrounds/background0.png", i * 100, 560, true, false));

	}
	_tiles.push_back(eighthRow);

	vector<GameTile*> ninthRow;
	for (int i = 0; i < _gridlength; i++)
	{
		if (i != 0)
			ninthRow.push_back(new GameTile("/assets/backgrounds/background0.png", i * 100, 640, true, false));

	}
	_tiles.push_back(ninthRow);

}

void GameWorld::setUpEnemyPositions()
{
	_enemyPos.clear();
	_enemyPos.push_back(Vector2i(0, 2));
	_enemyPos.push_back(Vector2i(6, 0));
	_enemyPos.push_back(Vector2i(2, 7));
}

GameWorld::GameWorld()
{
	_gridlength = 8;
	_exitPos = Vector2i(0, 0);
	_playerPos = Vector2i(0, 0);
	_enemyPos.clear();
	setUpInitialState();
	setUpTiles();
	setUpEnemyPositions();
}
