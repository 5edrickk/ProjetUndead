#pragma once

#include "constantes.h"
#include "constantes.h"
#include "player.h"  // Pour accéder aux dimensions ou constantes similaires

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>

//int lireHighScore();
//void ecrireHighScore(int nouveauScore);
//void afficherNouvelHighScore(sf::RenderWindow& window, int nouveauScore);
int afficherMenuJouer(sf::RenderWindow& window, sf::Font& font);
int afficherMenuPrincipal(sf::RenderWindow& window);

//int lireTousLesScores();
void afficherTableauScores(sf::RenderWindow& window, sf::Font& font);
int afficherTutoriel(sf::RenderWindow& window, sf::Font& font);