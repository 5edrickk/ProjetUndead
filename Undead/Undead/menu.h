#pragma once
#include <SFML/Graphics.hpp>

int lireHighScore();
void ecrireHighScore(int nouveauScore);
//void afficherNouvelHighScore(sf::RenderWindow& window, int nouveauScore);
int afficherMenuJouer(sf::RenderWindow& window, sf::Font& font);
int afficherMenuPrincipal(sf::RenderWindow& window);