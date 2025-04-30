#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

#include "constantes.h"
#include "functions.h"
#include "player.h"
#include "enemy.h"
#include "Background.h"
#include "menu.h"

class Game {
private:
	Player _player;
	Enemy _enemies[MAX_ENEMIES];

public:
	// Constructeurs
	Game();
	~Game();

	// Autres
	int mPlay();
};