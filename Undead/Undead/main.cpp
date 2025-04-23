#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

#include "constantes.h"
#include "functions.h"

using namespace sf;
using namespace std;

int main() {

	//========================================================================================================================
	// Variables
	int vCharacterPositionX = WINDOW_SIZE_X / 2 - PLAYER_SIZE / 2,
		vCharacterPositionY = WINDOW_SIZE_Y / 2 - PLAYER_SIZE / 2;

	//========================================================================================================================
	// Objets de classes
	Clock clock;
	Time time;

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
	// Boucle fen�tre : jusqu'� ce que la fen�tre soit ferm�e
	while (window.isOpen())
	{
		// On inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		Event event;

		while (window.pollEvent(event))
		{
			// �v�nement "fermeture demand�e" : on ferme la fen�tre
			if (event.type == Event::Closed)
			{
				window.close();
			}
			else if (event.type == Event::KeyPressed)
			{
				switch (event.key.code) {
				case Keyboard::Escape:
					window.close();
					break;
					// Movement switch case
				case Keyboard::W:
					if (vCharacterPositionY > 0)
					{
						sPlayer.move(0, -INCREMENT);
						vCharacterPositionY -= INCREMENT;
					}
					else { fDebug(1); }

					fDebug(2, vCharacterPositionX, vCharacterPositionY);
					break;
				case Keyboard::D:
					if (vCharacterPositionX < WINDOW_SIZE_X - PLAYER_SIZE)
					{
						sPlayer.move(INCREMENT, 0);
						vCharacterPositionX += INCREMENT;
					}
					else { fDebug(1); }

					fDebug(2, vCharacterPositionX, vCharacterPositionY);
					break;
				case Keyboard::S:
					if (vCharacterPositionY < WINDOW_SIZE_Y - PLAYER_SIZE)
					{
						sPlayer.move(0, INCREMENT);
						vCharacterPositionY += INCREMENT;
					}
					else { fDebug(1); }

					fDebug(2, vCharacterPositionX, vCharacterPositionY);
					break;
				case Keyboard::A:
					if (vCharacterPositionX > 0)
					{
						sPlayer.move(-INCREMENT, 0);
						vCharacterPositionX -= INCREMENT;
					}
					else { fDebug(1); }

					fDebug(2, vCharacterPositionX, vCharacterPositionY);
					break;
				}
			}
		}

		//========================================================================================================================
		// Boucle fen�tre > Boucle temps
		time = clock.getElapsedTime(); //Prends le temps de l�horloge
		if (time.asMilliseconds() >= 100.0f) //En milisecondes
		{

			// Effacement de la fen�tre en noir
			window.clear();

			// C'est ici qu'on dessine tout
			window.draw(sBackground);
			window.draw(sPlayer);

			// Fin de la frame courante, affichage de tout ce qu'on a dessin�
			window.display();

			clock.restart(); // On remet l�horloge � 0

		}
	}
	
	//========================================================================================================================
	// Fin
	cout << endl;
	system("pause");
	return 0;

}
