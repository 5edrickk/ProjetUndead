#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

#include "constantes.h"
#include "functions.h"
#include "player.h"
#include "Background.h"
#include "menu.h"

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
	int bkg = 0,
		lastbkg = 0;

	Background background[BACKGROUND_NUMBER]; // On crée un tableau de Backgrounds
	for (int i = 0; i < BACKGROUND_NUMBER; i++)
	{
		background[i].setBackground(background[i].getBackground()); // On initialise le background
		Texture textureBackground; // On crée une texture pour le background
		textureBackground.loadFromFile("assets/backgrounds/background" + std::to_string(i) + ".png"); // On charge la texture
		background[i].setTexture(textureBackground, 0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y); // On applique la texture au background
		
	}

	//========================================================================================================================
	// Joueur
	sf::RectangleShape sPlayer;

	sPlayer.setPosition(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2);
	sPlayer.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
	sPlayer.setFillColor(sf::Color::Black);

	sPlayer.setOrigin(PLAYER_SIZE / 2, PLAYER_SIZE / 2); // Point central du joueur pour la rotation

	//========================================================================================================================
	// Boucle de menu principal
	int choix = afficherMenuPrincipal(window);

	if (choix == 1) {
		sf::Font font;
		font.loadFromFile("assets/Menu/fonts/Arial_Bold_Italic.ttf");
		int sousChoix = afficherMenuJouer(window, font);

		if (sousChoix == 1) {
			// Lancer la partie ici
			// demarrerPartie(window);
		}
		else if (sousChoix == 2) {
			// Voir les meilleurs scores ici
			/*cout<< afficherNouvelHighScore(window);*/
		}
		// Retour ne fait rien, il retourne au menu principal
	}
	else if (choix == 2) {
		std::cout << "Paramètres sélectionnés" << endl;
		// Afficher ou gérer les paramètres
	}
	else if (choix == 3) {
		std::cout << "Affichage du tutoriel" << endl;
		// Afficher le tutoriel
	}
	else if (choix == 4 || choix == -1) {
		std::cout << "Quitter le jeu" << endl;
		window.close();
		return 0;
		// Fermer le jeu
	}
	
	//========================================================================================================================
	// Joueur hitbox
	FloatRect sPlayerBounds = sPlayer.getGlobalBounds();

	//========================================================================================================================
	// Boucle fenêtre : jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen())
	{
		// On inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		Event event;
		int dir = 0;

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

		// Boucle fenêtre > Boucle update
		timeUpdate = clockUpdate.getElapsedTime(); //Prends le temps de l�horloge
		if (timeUpdate.asMilliseconds() >= UPDATE_RATE) //En milisecondes (100.0f)
		{
			// Clear console on tick (constantes)
			if (CLEAR_CONSOLE_ON_TICK == true) { system("cls"); }

			// Tick console
			time++;
			cout << time << " / ================================" << endl;

			if (SHOW_SETTINGS_ON_DEBUG == true)
			{
				cout << GAME_NAME << " : " << FRAMERATE << "FPS / " << UPDATE_RATE << "Hz / " << WINDOW_SIZE_X << "x" << WINDOW_SIZE_Y << "px / " << INCREMENT << "inc." << endl;
			}

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

			fDebug(2, player.mGetPosX(), player.mGetPosY());
	
			//Défilement du joueur
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

      // Rotation joueur par rapport a la souris
			fDebug(3, Mouse::getPosition(window).x, Mouse::getPosition(window).y);
			player.mRotate(fWindowClamp(Mouse::getPosition(window).x, 'x'), fWindowClamp(Mouse::getPosition(window).y, 'y'), player);
			sPlayer.rotate(-player.mGetRotation() - sPlayer.getRotation());

			// D�filement des ennemis

			// D�filement des projectiles

			clockUpdate.restart(); // On remet l�horloge � 0
		}

		//========================================================================================================================
		// Boucle fenêtre > Boucle visuelle
		timeDraw = clockDraw.getElapsedTime(); //Prends le temps de l’horloge
		if (timeDraw.asMilliseconds() >= 1000/FRAMERATE) //En milisecondes (100.0f)
		{
			// Effacement de la fenêtre en noir
			window.clear();

			// On dessine le background
			background[bkg].draw(window); // On dessine le background

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
