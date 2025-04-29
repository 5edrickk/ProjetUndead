#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

#include "constantes.h"
#include "functions.h"
#include "player.h"

using namespace sf;
using namespace std;

int main() {

	//========================================================================================================================
	// Variables
	int time = 0;

	//========================================================================================================================
	// Objets de classes
	Clock clockUpdate;
	Time timeUpdate;

	Clock clockDraw;
	Time timeDraw;

	Player player;

	//========================================================================================================================
	// Render window
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), GAME_NAME, sf::Style::Close);
	window.setFramerateLimit(FRAMERATE);

	//========================================================================================================================
	// Background
	sf::RectangleShape sBackground;

	sBackground.setPosition(0, 0);
	sBackground.setSize(sf::Vector2f(WINDOW_SIZE_X, WINDOW_SIZE_Y));
	sBackground.setFillColor(sf::Color::White);
	sBackground.setOutlineColor(sf::Color::Black);
	sBackground.setOutlineThickness(5);
	
	//========================================================================================================================
	// Joueur
	sf::RectangleShape sPlayer;

	sPlayer.setPosition(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2);
	sPlayer.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
	sPlayer.setFillColor(sf::Color::Blue);

	sPlayer.setOrigin(PLAYER_SIZE / 2, PLAYER_SIZE / 2); // Point central du joueur pour la rotation
	
	//========================================================================================================================
	// Joueur hitbox
	FloatRect sPlayerBounds = sPlayer.getGlobalBounds();

	//========================================================================================================================
	// Boucle fenêtre : jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen())
	{
		// On inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		Event event;

		while (window.pollEvent(event))
		{
			// Évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == Event::Closed)
			{
				window.close();
			}
			// Détection des touches
			else if (event.type == Event::KeyPressed)
			{
				switch (event.key.code) {
				case Keyboard::Escape:
					window.close();
					break;
				}
			}
		}

		//========================================================================================================================
		// Boucle fenêtre > Boucle update
		timeUpdate = clockUpdate.getElapsedTime(); //Prends le temps de l’horloge
		if (timeUpdate.asMilliseconds() >= UPDATE_RATE) //En milisecondes (100.0f)
		{
			// Mouvement du joueur
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				player.mSetPosY(fPlayerMove(1, sPlayer, player.mGetPosX(), player.mGetPosY()));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				player.mSetPosX(fPlayerMove(2, sPlayer, player.mGetPosX(), player.mGetPosY()));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				player.mSetPosY(fPlayerMove(3, sPlayer, player.mGetPosX(), player.mGetPosY()));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				player.mSetPosX(fPlayerMove(4, sPlayer, player.mGetPosX(), player.mGetPosY()));
			}

			fDebug(3, Mouse::getPosition(window).x, Mouse::getPosition(window).y);
			player.mRotate(fWindowClamp(Mouse::getPosition(window).x, 'x'), fWindowClamp(Mouse::getPosition(window).y, 'y'), player);
			sPlayer.rotate(-player.mGetRotation() - sPlayer.getRotation());

			// Défilement des ennemis

			// Défilement des projectiles

			time++;

			clockUpdate.restart(); // On remet l’horloge à 0
		}

		//========================================================================================================================
		// Boucle fenêtre > Boucle visuelle
		timeDraw = clockDraw.getElapsedTime(); //Prends le temps de l’horloge
		if (timeDraw.asMilliseconds() >= 1000/FRAMERATE) //En milisecondes (100.0f)
		{
			// Effacement de la fenêtre en noir
			window.clear();

			// C'est ici qu'on dessine tout
			window.draw(sBackground);
			window.draw(sPlayer);

			// Fin de la frame courante, affichage de tout ce qu'on a dessiné
			window.display();

			clockDraw.restart(); // On remet l’horloge à 0
		}
	}
	
	//========================================================================================================================
	// Fin
	cout << endl;
	system("pause");
	return 0;

}
