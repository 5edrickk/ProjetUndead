#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <vector>

#include "constantes.h"
#include "functions.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "Background.h"
#include "menu.h"

class Game {
private:
	Player _player;
	Projectile _tempProjectile;

public:
	// Constructeurs
	Game();
	~Game();

	// Autres
	int mPlay();
};