#include "game.h"

using namespace std;
using namespace sf;

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

	bool playerAlive = true,
		showUpgradeMenu = false;

	int time = 0,
		enemyCount = 0,
		waveNumber = 0,
		spawnCooldown = 0,
		killNumber = 0,
		typeResult = 0;

	int upgradeID[3],
		upgradeSlot[3],
		upgradeLevel[3];

	Abilities temporaryAbilityClones[3];

	vector<Enemy> vEnemies;
	vector<RectangleShape> vEnemyShapes;
	vector<FloatRect> vEnemyBounds;

	vector<Projectile> vProjectiles;
	vector<RectangleShape> vProjectileShapes;
	vector<FloatRect> vProjectileBounds;

	vector<RectangleShape> vInterfaceElements;
	vector<RectangleShape> vInterfaceShapes;
	vector<Text> vInterfaceTextes;
	vector<Text> vInterfaceSlots;
	vector<Text> vInterfaceLevels;
	vector<Text> vInterfaceDescriptions;

	Font font;
	if (!font.loadFromFile("assets/Menu/fonts/Nosifer-Regular.ttf")) {
		cerr << "Erreur chargement police" << endl;
		return -1;
	}

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
	// Upgrade menu

	// Upgrade button settings
	float buttonWidth = WINDOW_SIZE_X / 6;
	float buttonHeight = WINDOW_SIZE_Y / 2;
	float buttonPosY = WINDOW_SIZE_Y / 4;
	float buttonSpacingX = WINDOW_SIZE_X / 6 * 1.25;

	// Upgrade menu background
	RectangleShape upgradeMenuBackground;
	upgradeMenuBackground.setPosition(WINDOW_SIZE_X / 6.0, WINDOW_SIZE_Y / 3.35);
	upgradeMenuBackground.setSize(Vector2f(WINDOW_SIZE_X / 1.5, WINDOW_SIZE_Y / 2.5));
	upgradeMenuBackground.setFillColor(Color::Black);
	upgradeMenuBackground.setOutlineColor(Color::White);
	upgradeMenuBackground.setOutlineThickness(10);
	vInterfaceElements.push_back(upgradeMenuBackground);

	// Upgrade buttons
	for (int i = 0; i < NUM_UPGRADE_BUTTONS; ++i) {

		//Background
		RectangleShape tempButton;
		tempButton.setPosition(buttonSpacingX + i * buttonWidth * 1.25, buttonPosY);
		tempButton.setSize(Vector2f(buttonWidth, buttonHeight));
		tempButton.setFillColor(Color::Red);
		tempButton.setOutlineColor(Color::White);
		tempButton.setOutlineThickness(10);
		vInterfaceShapes.push_back(tempButton);

		//Title
		Text tempLabel;
		tempLabel.setFont(font);
		tempLabel.setString("Default");
		tempLabel.setCharacterSize(15);
		tempLabel.setFillColor(Color::Black);
		tempLabel.setPosition(tempButton.getPosition());
		vInterfaceTextes.push_back(tempLabel);

		//Slot
		tempLabel.setFont(font);
		tempLabel.setString("0");
		tempLabel.setCharacterSize(15);
		tempLabel.setFillColor(Color::Black);
		tempLabel.setPosition(tempButton.getPosition().x, tempButton.getPosition().y + 200);
		vInterfaceSlots.push_back(tempLabel);

		//Level
		tempLabel.setFont(font);
		tempLabel.setString("0");
		tempLabel.setCharacterSize(15);
		tempLabel.setFillColor(Color::Black);
		tempLabel.setPosition(tempButton.getPosition().x, tempButton.getPosition().y + 150);
		vInterfaceLevels.push_back(tempLabel);

		//Description
		tempLabel.setFont(font);
		tempLabel.setString("Default");
		tempLabel.setCharacterSize(15);
		tempLabel.setFillColor(Color::Black);
		tempLabel.setPosition(tempButton.getPosition().x, tempButton.getPosition().y + 100);
		vInterfaceDescriptions.push_back(tempLabel);

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
		Vector2i souris = Mouse::getPosition(window);
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

			// Upgrade menu
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				for (int i = 0; i < NUM_UPGRADE_BUTTONS; i++)
				{
					if (vInterfaceShapes[i].getGlobalBounds().contains(Vector2f(souris)))
					{
						_player.mUpdateAbility(upgradeID[i], upgradeSlot[i], upgradeLevel[i]); //ID, slot, level
						showUpgradeMenu = false;
					}
				}
			}
		}

		//========================================================================================================================
		// Boucle fenêtre > Boucle update
		timeUpdate = clockUpdate.getElapsedTime(); //Prends le temps de l'horloge
		if (timeUpdate.asMilliseconds() >= 1000 / UPDATE_RATE && showUpgradeMenu == false) //En milisecondes (100.0f)
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
			if (killNumber >= KILLS_FOR_WAVE * waveNumber)
			{
				waveNumber++;
				killNumber = 0;
				cout << "Wave " << waveNumber << endl;

				// Generate upgrades
				for (int i = 0; i < 3; i++)
				{
					int slotIndex = rand() % PLAYER_ABILITY_SLOTS; // [0, 4]
					upgradeSlot[i] = slotIndex;

					int existingID = _player.mCheckAbilityID(slotIndex);

					if (existingID == 0) // If no ability assigned yet
					{
						int newAbilityID = rand() % PLAYER_UPGRADE_TYPE_NUMBER + 1; // [1, N]
						upgradeID[i] = newAbilityID;
						upgradeLevel[i] = 1;
					}
					else // Upgrade existing ability
					{
						upgradeID[i] = existingID;
						upgradeLevel[i] = _player.mCheckAbilityLevel(slotIndex) + 1;
					}

					temporaryAbilityClones[i].mSetAbilityType(upgradeID[i], upgradeSlot[i], upgradeLevel[i]);

					cout << "Slot: " << slotIndex << " | Ability ID: " << upgradeID[i] << " | Upgrade Level: " << upgradeLevel[i] << endl;
				}

				// Update UI
				for (int i = 0; i < NUM_UPGRADE_BUTTONS; i++)
				{
					vInterfaceTextes[i].setString(temporaryAbilityClones[i].mGetUpgradeName());
					vInterfaceSlots[i].setString("Slot " + to_string(upgradeSlot[i] + 1));
					vInterfaceLevels[i].setString("Level " + to_string(upgradeLevel[i]));
					vInterfaceDescriptions[i].setString(temporaryAbilityClones[i].mGetUpgradeText());
				}

				showUpgradeMenu = true;
			}

			// Enemy type selection
			if (killNumber == 0 || killNumber >= waveNumber / 3)
			{
				typeResult = rand() % ENEMY_TYPE_NUMBER + 1; // Max, min
			}

			// Spawning
			if (spawnCooldown <= 0 && enemyCount < MAX_ENEMIES)
			{
				int side = rand() % 4 + 1; // Max, min

				Enemy tempEnemy;
				RectangleShape tempEnemyRect;

				tempEnemy.mSetEnemyType(typeResult, tempEnemyRect);

				if (side == 1)
				{
					tempEnemy.mSetPositionX(rand() % WINDOW_SIZE_X + 0); // Max, min
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
				tempEnemyRect.setSize(sf::Vector2f(ENEMY_SIZE, ENEMY_SIZE));

				FloatRect sEnemeyBounds = tempEnemyRect.getGlobalBounds();

				vEnemies.push_back(tempEnemy);
				vEnemyShapes.push_back(tempEnemyRect);
				vEnemyBounds.push_back(sEnemeyBounds);

				enemyCount++;
				spawnCooldown = MAX_SPAWN_COOLDOWN;

				spawnCooldown = spawnCooldown / waveNumber;
			}
			else
			{
				spawnCooldown--;
			}

			// Mouvement du joueur
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				_player.mSetPosY(fPlayerMove(1, sPlayer, _player.mGetPosX(), _player.mGetPosY()));

				for (int i = 0; i < vEnemies.size(); i++)
				{
					vEnemies[i].mSetPositionY(vEnemies[i].mGetPositionY() + INCREMENT);
					vEnemyShapes[i].move(0, + INCREMENT);
				}

				for (int i = 0; i < vProjectiles.size(); i++)
				{
					vProjectiles[i].mSetPositionY(vProjectiles[i].mGetPositionY() + INCREMENT);
					vProjectileShapes[i].move(0, +INCREMENT);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				_player.mSetPosX(fPlayerMove(2, sPlayer, _player.mGetPosX(), _player.mGetPosY()));

				for (int i = 0; i < vEnemies.size(); i++)
				{
					vEnemies[i].mSetPositionX(vEnemies[i].mGetPositionX() - INCREMENT);
					vEnemyShapes[i].move(-INCREMENT, 0);
				}

				for (int i = 0; i < vProjectiles.size(); i++)
				{
					vProjectiles[i].mSetPositionY(vProjectiles[i].mGetPositionY() - INCREMENT);
					vProjectileShapes[i].move(-INCREMENT, 0);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				_player.mSetPosY(fPlayerMove(3, sPlayer, _player.mGetPosX(), _player.mGetPosY()));

				for (int i = 0; i < vEnemies.size(); i++)
				{
					vEnemies[i].mSetPositionY(vEnemies[i].mGetPositionY() - INCREMENT);
					vEnemyShapes[i].move(0, - INCREMENT);
				}

				for (int i = 0; i < vProjectiles.size(); i++)
				{
					vProjectiles[i].mSetPositionY(vProjectiles[i].mGetPositionY() - INCREMENT);
					vProjectileShapes[i].move(0, -INCREMENT);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				_player.mSetPosX(fPlayerMove(4, sPlayer, _player.mGetPosX(), _player.mGetPosY()));

				for (int i = 0; i < vEnemies.size(); i++)
				{
					vEnemies[i].mSetPositionX(vEnemies[i].mGetPositionX() + INCREMENT);
					vEnemyShapes[i].move(INCREMENT, 0);
				}

				for (int i = 0; i < vProjectiles.size(); i++)
				{
					vProjectiles[i].mSetPositionY(vProjectiles[i].mGetPositionY() + INCREMENT);
					vProjectileShapes[i].move(INCREMENT, 0);
				}
			}

			FloatRect sPlayerBounds = sPlayer.getGlobalBounds();

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
					tempProjectile.mSetPositionX(_player.mGetPosX());
					tempProjectile.mSetPositionY(_player.mGetPosY());

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
					if (vProjectiles[i].mGetBounceAmount() > 0 && (vProjectiles[i].mGetPositionX() <= 0 || vProjectiles[i].mGetPositionX() >= WINDOW_SIZE_X || vProjectiles[i].mGetPositionY() <= 0 || vProjectiles[i].mGetPositionY() >= WINDOW_SIZE_Y))
					{
						if (vProjectiles[i].mGetPositionX() <= 0 || vProjectiles[i].mGetPositionX() >= WINDOW_SIZE_X)
						{
							vProjectiles[i].mSetVelocityX(-vProjectiles[i].mGetVelocityX());
							vProjectiles[i].mSetBounceAmount(vProjectiles[i].mGetBounceAmount() - 1);
						}

						if  (vProjectiles[i].mGetPositionY() <= 0 || vProjectiles[i].mGetPositionY() >= WINDOW_SIZE_Y)
						{
							vProjectiles[i].mSetVelocityY(-vProjectiles[i].mGetVelocityY());
							vProjectiles[i].mSetBounceAmount(vProjectiles[i].mGetBounceAmount() - 1);
						}
					}
					
					vProjectiles[i].mSetPositionX(vProjectiles[i].mGetPositionX() + vProjectiles[i].mGetVelocityX());
					vProjectiles[i].mSetPositionY(vProjectiles[i].mGetPositionY() + vProjectiles[i].mGetVelocityY());
					
					vProjectileShapes[i].move(vProjectiles[i].mGetVelocityX(), -vProjectiles[i].mGetVelocityY());
					vProjectileBounds[i] = vProjectileShapes[i].getGlobalBounds();
				}
			}

			for (int i = 0; i < vEnemies.size(); i++)
			{
				vEnemies[i].mDamageEffectTick(vEnemyShapes[i]);
			}

			// Collision des projectiles
			for (int i = 0; i < vProjectiles.size(); i++)
			{
				for (int j = 0; j < vEnemies.size(); j++)
				{
					if (vProjectileBounds[i].intersects(vEnemyBounds[j]) && vProjectiles[i].mGetCanDamage() == true)
					{
						vEnemies[j].mDamageEffect(vEnemyShapes[j]);
						vEnemies[j].mSetHealth(vEnemies[j].mGetHealth() - vProjectiles[i].mGetDamage());

						if (vProjectiles[i].mGetPierceAmount() > 0)
						{
							vProjectiles[i].mSetPierceAmount(vProjectiles[i].mGetPierceAmount() - 1);
						}
						else
						{
							vProjectiles[i].mSetCanDamage(false);
							vProjectiles[i].mSetLifetime(0);
						}
					}
				}
			}

			// Collision des ennemis avec le joueur
			for (int i = 0; i < vEnemies.size(); i++)
			{
				if (sPlayerBounds.intersects(vEnemyBounds[i]))
				{
					_player.mSetHealth(_player.mGetHealth() - vEnemies[i].mGetDamage());

					if (_player.mGetHealth() <= 0)
					{
						playerAlive = false;
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

					enemyCount--;
					killNumber++;
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
		if (timeDraw.asMilliseconds() >= 1000 / FRAMERATE) //En milisecondes (100.0f)
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

			// Dessin de l'interface
			if (showUpgradeMenu == true)
			{
				for (int i = 0; i < vInterfaceElements.size(); i++)
				{
					window.draw(vInterfaceElements[i]);
				}

				for (int i = 0; i < vInterfaceShapes.size(); i++)
				{
					window.draw(vInterfaceShapes[i]);
				}

				for (int i = 0; i < vInterfaceTextes.size(); i++)
				{
					window.draw(vInterfaceTextes[i]);
				}

				for (int i = 0; i < vInterfaceSlots.size(); i++)
				{
					window.draw(vInterfaceSlots[i]);
				}

				for (int i = 0; i < vInterfaceLevels.size(); i++)
				{
					window.draw(vInterfaceLevels[i]);
				}

				for (int i = 0; i < vInterfaceDescriptions.size(); i++)
				{
					window.draw(vInterfaceDescriptions[i]);
				}
			}

			// Fin de la frame courante, affichage de tout ce qu'on a dessiné
			window.display();

			clockDraw.restart(); // On remet l’horloge à 0
		}
	}
}