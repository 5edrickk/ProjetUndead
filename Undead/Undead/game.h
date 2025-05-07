#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

#include "constantes.h"
#include "functions.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "GameTile.h"
#include "GameWorld.h"
#include "menu.h"

class Game {
private:
	Player _player;

public:
	// Constructeurs
	Game();
	~Game();

	// Autres
	int mPlay();
};