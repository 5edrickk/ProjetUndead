#include "game.h"

using namespace sf;
using namespace std;

using namespace std;

Game::Game()
{

}

Game::~Game()
{

}

int Game::mPlay()
{

	//========================================================================================================================
	// Variables
	srand(time(0));

	int time = 0,
		enemyCount = 0,
		waveNumber = 0;

	vector<Enemy> vEnemies;
	vector<RectangleShape> vEnemyShapes;
	vector<FloatRect> vEnemyBounds;

	vector<Projectile> vProjectiles;
	vector<RectangleShape> vProjectileShapes;
	vector<FloatRect> vProjectileBounds;

	//========================================================================================================================
	// Objets de classes
	Clock clockUpdate;
	Time timeUpdate;

	Clock clockDraw;
	Time timeDraw;

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

	FloatRect sPlayerBounds = sPlayer.getGlobalBounds();

	_player.mInitialize();
	_player.mSetActive(0, true);

	//========================================================================================================================
	// Boucle de menu principal
	int choix = afficherMenuPrincipal(window);

	do
	{
		if (choix == 1) {
			cout << "Vous avez choisi de jouer !" << endl;
			// Lancer le jeu
		}
		else if (choix == 2) {
			cout << "Paramètres sélectionnés" << endl;
			// Afficher ou gérer les paramètres
		}
		else if (choix == 3) {
			cout << "Affichage du tutoriel" << endl;
			// Afficher le tutoriel
		}
		else if (choix == 4 || choix == -1) {
			cout << "Quitter le jeu" << endl;
			return 0;
			// Fermer le jeu
		}
	} while (choix == 2 || choix == 3);

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

			if (DEBUG == true)
			{
				cout << time << " / ================================" << endl;
			}

			if (SHOW_SETTINGS_ON_DEBUG == true)
			{
				cout << GAME_NAME << " : " << FRAMERATE << "FPS / " << UPDATE_RATE << "Hz / " << WINDOW_SIZE_X << "x" << WINDOW_SIZE_Y << "px / " << INCREMENT << "inc." << endl;
			}

			// Vague
			if (enemyCount == 0)
			{
				waveNumber++;

				for (int i = 0; i < 5 * waveNumber; i++)
				{
					int side = rand() % 4 + 1;

					Enemy tempEnemy;
					RectangleShape tempEnemyRect;

					// Max, min
					if (side == 1)
					{
						tempEnemy.mSetPositionX(rand() % WINDOW_SIZE_X + 0);
						tempEnemy.mSetPositionY(0);
					}
					else if (side == 2)
					{
						tempEnemy.mSetPositionX(0);
						tempEnemy.mSetPositionY(rand() % WINDOW_SIZE_Y + 0);
					}
					else if (side == 3)
					{
						tempEnemy.mSetPositionX(rand() % WINDOW_SIZE_X + 0);
						tempEnemy.mSetPositionY(WINDOW_SIZE_Y);
					}
					else 
					{
						tempEnemy.mSetPositionX(WINDOW_SIZE_X);
						tempEnemy.mSetPositionY(rand() % WINDOW_SIZE_Y + 0);
					}

					tempEnemyRect.setPosition(tempEnemy.mGetPositionX(), tempEnemy.mGetPositionY());
					tempEnemyRect.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
					tempEnemyRect.setFillColor(sf::Color::Blue);

					FloatRect sEnemeyBounds = tempEnemyRect.getGlobalBounds();

					vEnemies.push_back(tempEnemy);
					vEnemyShapes.push_back(tempEnemyRect);
					vEnemyBounds.push_back(sEnemeyBounds);

					enemyCount++;
					tempEnemy.~Enemy();
				}
			}

			// Mouvement du joueur
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				_player.mSetPosY(fPlayerMove(1, sPlayer, _player.mGetPosX(), _player.mGetPosY()));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				_player.mSetPosX(fPlayerMove(2, sPlayer, _player.mGetPosX(), _player.mGetPosY()));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				_player.mSetPosY(fPlayerMove(3, sPlayer, _player.mGetPosX(), _player.mGetPosY()));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				_player.mSetPosX(fPlayerMove(4, sPlayer, _player.mGetPosX(), _player.mGetPosY()));
			}

			fDebug(2, _player.mGetPosX(), _player.mGetPosY());

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
			_player.mRotate(fWindowClamp(Mouse::getPosition(window).x, 'x'), fWindowClamp(Mouse::getPosition(window).y, 'y'), _player);
			sPlayer.rotate(-_player.mGetRotation() - sPlayer.getRotation());

			// Attaque du joueur
			for (int i = 0; i < PLAYER_ABILITY_SLOTS; i++)
			{
				if (_player.mCheckAttack(i) == true)
				{ 
					Projectile tempProjectile;
					tempProjectile.mCloneFromAbility(_player.mGetAbility(i));
					tempProjectile.mInitializeMovement(_player.mGetRotation(), tempProjectile.mGetSpeed());

					RectangleShape sProjectile;
					sProjectile.setPosition(_player.mGetPosX() + PLAYER_SIZE / 2, _player.mGetPosY() + PLAYER_SIZE / 2);
					sProjectile.setSize(sf::Vector2f(tempProjectile.mGetSize(), tempProjectile.mGetSize()));
					sProjectile.setFillColor(sf::Color::Red);
					sProjectile.setOrigin(tempProjectile.mGetSize() / 2, tempProjectile.mGetSize() / 2);

					FloatRect sProjectileBounds = sProjectile.getGlobalBounds();

					vProjectiles.push_back(tempProjectile);
					vProjectileShapes.push_back(sProjectile);
					vProjectileBounds.push_back(sProjectileBounds);
					_player.mAttacked(i);

					tempProjectile.~Projectile();
					fDebug(5, i);
				}
				else 
				{
					_player.mDecreaseCooldown(i);
					fDebug(6, i);
				}
			}

			fDebug(7, vProjectiles.size());

			// Défilement des projectiles
			for (int i = vProjectiles.size() - 1; i >= 0; i--) //int i = 0; i < vProjectiles.size(); i++ //int i = vProjeectiles.size() - 1; i >= 0; i--
			{
				vProjectiles[i].mSetLifetime(vProjectiles[i].mGetLifetime() - 1);

				if (vProjectiles[i].mGetLifetime() <= 0)
				{
					vProjectiles.erase(vProjectiles.begin() + i);
					vProjectileShapes.erase(vProjectileShapes.begin() + i);
					vProjectileBounds.erase(vProjectileBounds.begin() + i);
				}
				else
				{
					vProjectiles[i].mSetPositionX(vProjectiles[i].mGetPositionX() + vProjectiles[i].mGetVelocityX());
					vProjectiles[i].mSetPositionY(vProjectiles[i].mGetPositionY() + vProjectiles[i].mGetVelocityY());

					vProjectileShapes[i].move(vProjectiles[i].mGetVelocityX(), -vProjectiles[i].mGetVelocityY());
					vProjectileBounds[i] = vProjectileShapes[i].getGlobalBounds();
				}
			}

			// Collision des projectiles
			for (int i = 0; i < vProjectiles.size(); i++)
			{
				for (int j = 0; j < vEnemies.size(); j++)
				{
					if (vProjectileBounds[i].intersects(vEnemyBounds[j]))
					{
						vProjectiles[i].mSetLifetime(0);

						vEnemies[j].mSetHealth(vEnemies[j].mGetHealth() - vProjectiles[i].mGetDamage());
					}
				}
			}
		
			// Défilement des ennemis
			for (int i = vEnemies.size() - 1; i >= 0; i--) //int i = 0; i < vEnemies.size(); i++ //int i = vEnemies.size() - 1; i >= 0; i--
			{
				if (vEnemies[i].mGetHealth() <= 0)
				{
					vEnemies.erase(vEnemies.begin() + i);
					vEnemyShapes.erase(vEnemyShapes.begin() + i);
					vEnemyBounds.erase(vEnemyBounds.begin() + i);
				}
				else
				{
					vEnemies[i].mInitializeMovement(_player.mGetPosX(), _player.mGetPosY());

					vEnemies[i].mSetPositionX(vEnemies[i].mGetPositionX() + vEnemies[i].mGetVelocityX());
					vEnemies[i].mSetPositionY(vEnemies[i].mGetPositionY() + vEnemies[i].mGetVelocityY());

					vEnemyShapes[i].move(vEnemies[i].mGetVelocityX(), vEnemies[i].mGetVelocityY());

					vEnemyBounds[i] = vEnemyShapes[i].getGlobalBounds();
				}
			}
			
			clockUpdate.restart(); // On remet l'horloge � 0
		}

		//========================================================================================================================
		// Boucle fenêtre > Boucle visuelle
		timeDraw = clockDraw.getElapsedTime(); //Prends le temps de l’horloge
		if (timeDraw.asMilliseconds() >= 1000 / 60) //En milisecondes (100.0f)
		{
			// Effacement de la fenêtre en noir
			window.clear();

			// On dessine le background
			background[bkg].draw(window); // On dessine le background

			// Dessin des ennemis
			for (int i = 0; i < vEnemyShapes.size(); i++)
			{
				window.draw(vEnemyShapes[i]);
			}

			// Dessin du joueur
			window.draw(sPlayer);

			// Dessin des projectiles
			for (int i = 0; i < vProjectileShapes.size(); i++)
			{
				window.draw(vProjectileShapes[i]);
			}

			// Fin de la frame courante, affichage de tout ce qu'on a dessiné
			window.display();

			clockDraw.restart(); // On remet l’horloge à 0
		}
	}
}