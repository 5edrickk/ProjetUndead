#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "constantes.h"

void fDebug(int code, int param1 = 0, int param2 = 0);

int fWindowClamp(int value, char direction);

int fPlayerMove2(int direction, sf::RectangleShape& player, int posX, int posY);

int fPlayerMove(int direction, int posX, int posY);

void fInitialize();

void fTriggerUpgrade(int upgradeNumber);