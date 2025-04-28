#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

#include "constantes.h"
#include "functions.h"
#include "player.h"
#include "Background.h"

using namespace sf;
using namespace std;

int main() {

	//========================================================================================================================
	// Variables

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
	Background background[5]; // On cr�e un tableau de Backgrounds
	for (int i = 0; i < 5; i++)
	{
		background[i].setBackground(background[i].getBackground()); // On initialise le background
		Texture textureBackground; // On cr�e une texture pour le background
		textureBackground.loadFromFile("assets/backgrounds/background" + std::to_string(i) + ".png"); // On charge la texture
		background[i].setTexture(textureBackground, 0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y); // On applique la texture au background

	}
	int bkg = 0;
	int lastbkg=5;
	//========================================================================================================================
	// Joueur
	sf::RectangleShape sPlayer;

	sPlayer.setPosition(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2);
	sPlayer.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
	sPlayer.setFillColor(sf::Color::Black);

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
		int dir = 0;

		while (window.pollEvent(event))
		{
			// �v�nement "fermeture demand�e" : on ferme la fen�tre
			if (event.type == Event::Closed)
			{
				window.close();
			}
			// D�tection des touches
			else if (event.type == Event::KeyPressed)
			{
				switch (event.key.code) {
				case Keyboard::Escape:
					window.close();
					break;
				case Keyboard::W:
					dir = 1;
					break;
				case Keyboard::D:
					dir = 2;
					break;
				case Keyboard::S:
					dir = 3;
					break;
				case Keyboard::A:
					dir = 4;
					break;
				default:
					break;
				}

			}
		}

		//========================================================================================================================

		// Boucle fen�tre > Boucle update
	
	


			//Defilement du joueur
			
			switch (dir)
			{
			case 1: // Haut
				bkg = 1; 
				lastbkg = bkg;
				
				break;
			case 2: // Droite
				bkg = 2;
				lastbkg = bkg;
				break;
			case 3: // Bas
				bkg = 3;
				lastbkg = bkg;
				break;
			case 4: // Gauche
				bkg = 4;
				lastbkg = bkg;
				break;
			default:
				bkg = lastbkg;
				break;
			}
			
			// D�filement des ennemis

			// D�filement des projectiles



		//========================================================================================================================
		// Boucle fen�tre > Boucle visuelle
		//timeDraw = clockDraw.getElapsedTime(); //Prends le temps de l�horloge
		//if (timeDraw.asMilliseconds() >= 1000/FRAMERATE) //En milisecondes (100.0f)
		//{
			// Effacement de la fen�tre en noir
			window.clear();

			// On dessine le background
			background[bkg].draw(window); // On dessine le background



			window.draw(sPlayer);
			// Fin de la frame courante, affichage de tout ce qu'on a dessin�
			window.display();

	//		clockDraw.restart(); // On remet l�horloge � 0
	//	}
	}
	
	//========================================================================================================================
	// Fin
	std::cout << endl;
	system("pause");
	return 0;

}
