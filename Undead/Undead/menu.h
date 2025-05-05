#pragma once

#include "constantes.h"
#include "player.h"  // Pour accéder aux dimensions ou constantes similaires

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int lireHighScore();
void ecrireHighScore(int nouveauScore);
//void afficherNouvelHighScore(sf::RenderWindow& window, int nouveauScore);
int afficherMenuJouer(sf::RenderWindow& window, sf::Font& font);
int afficherMenuPrincipal(sf::RenderWindow& window);