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
		typeResult = 0,
		currentWaveWeight = 0,
		maxWaveWeight = 5,
		playerAnimationCooldown = 0,
		playerAnimationPosition = 0;

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
	// Texture vectors

	vector<string> vSpritePlayer;
	vector<string> vSpriteEnemy1;
	vector<string> vSpriteEnemy2;
	vector<string> vSpriteEnemy3;
	vector<string> vSpriteEnemy4;

	if ("assets/sprites/Crowstill.png") { vSpritePlayer.push_back("assets/sprites/Crowstill.png"); } else { return 1; }
	if ("assets/sprites/Crowstepleft.png") { vSpritePlayer.push_back("assets/sprites/Crowstepleft.png"); } else { return 1; }
	if ("assets/sprites/Crowstepright.png") { vSpritePlayer.push_back("assets/sprites/Crowstepright.png"); } else { return 1; }
	if ("assets/sprites/Crowhit.png") { vSpritePlayer.push_back("assets/sprites/Crowhit.png"); } else { return 1; }

	if ("assets/sprites/Enemy1still.png") { vSpriteEnemy1.push_back("assets/sprites/Enemy1still.png"); } else { return 1; }
	if ("assets/sprites/Enemy1down.png") { vSpriteEnemy1.push_back("assets/sprites/Enemy1down.png"); } else { return 1; }
	if ("assets/sprites/Enemy1up.png") { vSpriteEnemy1.push_back("assets/sprites/Enemy1up.png"); } else { return 1; }
	if ("assets/sprites/Enemy1hit.png") { vSpriteEnemy1.push_back("assets/sprites/Enemy1hit.png"); } else { return 1; }

	if ("assets/sprites/Enemy2still.png") { vSpriteEnemy2.push_back("assets/sprites/Enemy2still.png"); } else { return 1; }
	if ("assets/sprites/Enemy2down.png") { vSpriteEnemy2.push_back("assets/sprites/Enemy2down.png"); } else { return 1; }
	if ("assets/sprites/Enemy2up.png") { vSpriteEnemy2.push_back("assets/sprites/Enemy2up.png"); } else { return 1; }
	if ("assets/sprites/Enemy2hit.png") { vSpriteEnemy2.push_back("assets/sprites/Enemy2hit.png"); } else { return 1; }

	if ("assets/sprites/Enemy3still.png") { vSpriteEnemy3.push_back("assets/sprites/Enemy3still.png"); } else { return 1; }
	if ("assets/sprites/Enemy3down.png") { vSpriteEnemy3.push_back("assets/sprites/Enemy3down.png"); } else { return 1; }
	if ("assets/sprites/Enemy3up.png") { vSpriteEnemy3.push_back("assets/sprites/Enemy3up.png"); } else { return 1; }
	if ("assets/sprites/Enemy3hit.png") { vSpriteEnemy3.push_back("assets/sprites/Enemy3hit.png"); } else { return 1; }

	if ("assets/sprites/Enemy4still.png") { vSpriteEnemy4.push_back("assets/sprites/Enemy4still.png"); } else { return 1; }
	if ("assets/sprites/Enemy4down.png") { vSpriteEnemy4.push_back("assets/sprites/Enemy4down.png"); } else { return 1; }
	if ("assets/sprites/Enemy4up.png") { vSpriteEnemy4.push_back("assets/sprites/Enemy4up.png"); } else { return 1; }
	if ("assets/sprites/Enemy4hit.png") { vSpriteEnemy4.push_back("assets/sprites/Enemy4hit.png"); } else { return 1; }

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
	// Upgrade menu
	Camera viewUpgradeMenu(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2, 1.5f, 0.0f);
	//viewUpgradeMenu.msetViewPort(0, 0, 1, 1); // Set le view port pour couvrir tt la fenêtre

	// Upgrade button settings
	float buttonWidth = WINDOW_SIZE_X / 6,
		  buttonHeight = WINDOW_SIZE_Y / 2,
		  buttonPosY = WINDOW_SIZE_Y / 4,
		  buttonSpacingX = WINDOW_SIZE_X / 6 * 1.25;
	int textSize = 15;

	// Upgrade menu background
	//RectangleShape upgradeMenuBackground;
	//upgradeMenuBackground.setPosition(WINDOW_SIZE_X / 6.0, WINDOW_SIZE_Y / 3.35);
	//upgradeMenuBackground.setSize(Vector2f(WINDOW_SIZE_X / 1.5, WINDOW_SIZE_Y / 2.5));
	//upgradeMenuBackground.setFillColor(Color::Black);
	//upgradeMenuBackground.setOutlineColor(Color::White);
	//upgradeMenuBackground.setOutlineThickness(10);
	//vInterfaceElements.push_back(upgradeMenuBackground);

	// Upgrade buttons
	for (int i = 0; i < NUM_UPGRADE_BUTTONS; ++i) {

		//Background
		RectangleShape tempButton;
		tempButton.setPosition(buttonSpacingX + i * buttonWidth * 1.25, buttonPosY);

		tempButton.setSize(Vector2f(buttonWidth, buttonHeight));
		//tempButton.setFillColor(Color::Red);
		//tempButton.setOutlineColor(Color::White);
		//tempButton.setOutlineThickness(10);
		vInterfaceShapes.push_back(tempButton);

		//Title
		Text tempLabel;
		tempLabel.setFont(font);
		tempLabel.setString("Default");
		tempLabel.setCharacterSize(textSize);
		tempLabel.setFillColor(Color::Black);
		tempLabel.setPosition(tempButton.getPosition());
		vInterfaceTextes.push_back(tempLabel);

		//Slot
		tempLabel.setFont(font);
		tempLabel.setString("0");
		tempLabel.setCharacterSize(textSize);
		tempLabel.setFillColor(Color::Black);
		tempLabel.setPosition(tempButton.getPosition().x, buttonPosY + buttonHeight - textSize * 2);
		vInterfaceSlots.push_back(tempLabel);

		//Level
		tempLabel.setFont(font);
		tempLabel.setString("0");
		tempLabel.setCharacterSize(textSize);
		tempLabel.setFillColor(Color::Black);
		tempLabel.setPosition(tempButton.getPosition().x, buttonPosY + buttonHeight - textSize * 4);
		vInterfaceLevels.push_back(tempLabel);

		//Description
		tempLabel.setFont(font);
		tempLabel.setString("Default");
		tempLabel.setCharacterSize(textSize);
		tempLabel.setFillColor(Color::Black);
		tempLabel.setPosition(tempButton.getPosition().x, buttonPosY + buttonHeight - textSize * 6);
		vInterfaceDescriptions.push_back(tempLabel);

	}

	// Other UI elements
	Text deathScreenText;
	deathScreenText.setFont(font);
	deathScreenText.setString("MORT");
	deathScreenText.setCharacterSize(80);
	deathScreenText.setFillColor(Color::Red);
	deathScreenText.setPosition(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2);

	//========================================================================================================================
	// Joueur
	sf::RectangleShape sPlayer;

	sPlayer.setPosition(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2);
	sPlayer.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
	//sPlayer.setFillColor(sf::Color::Black);

	sPlayer.setOrigin(PLAYER_SIZE / 2, PLAYER_SIZE / 2); // Point central du joueur pour la rotation

	FloatRect sPlayerBounds = sPlayer.getGlobalBounds();

	_player.mInitialize();
	_player.mSetActive(0, true);

	Vector2f playerPosition = sPlayer.getPosition();

	//========================================================================================================================
	// Background
	Texture bkgTexture;
	if (!bkgTexture.loadFromFile("assets/backgrounds/background7.png"))
	{
		cout << "Error loading background texture" << endl;
		exit(1);
	}
	Sprite bkgSprite;
	bkgSprite.setTexture(bkgTexture);
	bkgSprite.setTextureRect(IntRect(0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y)); // Set the texture rectangle

	Camera viewDuJoueur(playerPosition.x, playerPosition.y, 0.5f,0.0f);
	viewDuJoueur.msetViewPort(0, 0, 1, 1); // Set le view port pour couvrir tt la fenêtre


	//Set les limites de la view pour ne montrer que la map
	Vector2f viewSize = viewDuJoueur.mGetView().getSize();
	FloatRect mapBounds = bkgSprite.getGlobalBounds();

	float halfWidth = viewSize.x / 2.f;
	float halfHeight = viewSize.y / 2.f;


	//========================================================================================================================
	// Boucle fenêtre : jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen())
	{
		// On inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		Event event;
		Vector2i souris = Mouse::getPosition(window);

		while (window.pollEvent(event))
		{
			// Évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == Event::Closed)
			{
				window.close();
			}

			// Détection des touches

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
		if (timeUpdate.asMilliseconds() >= 1000 / UPDATE_RATE && showUpgradeMenu == false && playerAlive == true) //En milisecondes (100.0f)
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

			// Wave
			if (killNumber >= KILLS_FOR_WAVE * waveNumber)
			{
				//window.setView(viewUpgradeMenu.mGetView());

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

			// Spawning
			if (spawnCooldown <= 0 && enemyCount < MAX_ENEMIES && currentWaveWeight < waveNumber * 5)
			{
				int side = rand() % 4 + 1; // Max, min

				Enemy tempEnemy;
				RectangleShape tempEnemyRect;

				do
				{
					typeResult = rand() % ENEMY_TYPE_NUMBER + 1; // Max, min
					tempEnemy.mSetEnemyType(typeResult, tempEnemyRect);

				} while ((tempEnemy.mGetSpawnWeight() > (waveNumber * 5) - currentWaveWeight) || (waveNumber < tempEnemy.mGetMinimumWave() || waveNumber > tempEnemy.mGetMaximumWave()));

				// Spawn on screen edges
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

				// Generate enemy
				tempEnemyRect.setPosition(tempEnemy.mGetPositionX(), tempEnemy.mGetPositionY());
				tempEnemyRect.setSize(sf::Vector2f(ENEMY_SIZE, ENEMY_SIZE));

				FloatRect sEnemeyBounds = tempEnemyRect.getGlobalBounds();

				vEnemies.push_back(tempEnemy);
				vEnemyShapes.push_back(tempEnemyRect);
				vEnemyBounds.push_back(sEnemeyBounds);

				// Values
				enemyCount++;
				spawnCooldown = MAX_SPAWN_COOLDOWN / waveNumber;	

				currentWaveWeight += tempEnemy.mGetSpawnWeight();
			}
			else
			{
				spawnCooldown--;
			}

			// Mouvement du joueur
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				
				_player.mSetPosY(fPlayerMove(1, _player.mGetPosX(), _player.mGetPosY()));


				/*_player.mSetPosY(fPlayerMove2(1, sPlayer, _player.mGetPosX(), _player.mGetPosY()));
				

				for (int i = 0; i < vEnemies.size(); i++)
				{
					vEnemies[i].mSetPositionY(vEnemies[i].mGetPositionY() + INCREMENT);
					vEnemyShapes[i].move(0, INCREMENT);
				}

				for (int i = 0; i < vProjectiles.size(); i++)
				{
					vProjectiles[i].mSetPositionY(vProjectiles[i].mGetPositionY() + INCREMENT);
					vProjectileShapes[i].move(0, INCREMENT);
				}*/

				playerAnimationCooldown -= 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				
				_player.mSetPosX(fPlayerMove(2, _player.mGetPosX(), _player.mGetPosY()));
				
				
				/*_player.mSetPosX(fPlayerMove2(2, sPlayer, _player.mGetPosX(), _player.mGetPosY()));

				

				for (int i = 0; i < vEnemies.size(); i++)
				{
					vEnemies[i].mSetPositionX(vEnemies[i].mGetPositionX() - INCREMENT);
					vEnemyShapes[i].move(-INCREMENT, 0);
				}

				for (int i = 0; i < vProjectiles.size(); i++)
				{
					vProjectiles[i].mSetPositionX(vProjectiles[i].mGetPositionX() - INCREMENT);
					vProjectileShapes[i].move(-INCREMENT, 0);
				}*/

				playerAnimationCooldown -= 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				_player.mSetPosY(fPlayerMove(3, _player.mGetPosX(), _player.mGetPosY()));
				
				
				/*_player.mSetPosY(fPlayerMove2(3, sPlayer, _player.mGetPosX(), _player.mGetPosY()));
				


				for (int i = 0; i < vEnemies.size(); i++)
				{
					vEnemies[i].mSetPositionY(vEnemies[i].mGetPositionY() - INCREMENT);
					vEnemyShapes[i].move(0, - INCREMENT);
				}

				for (int i = 0; i < vProjectiles.size(); i++)
				{
					vProjectiles[i].mSetPositionY(vProjectiles[i].mGetPositionY() - INCREMENT);
					vProjectileShapes[i].move(0, -INCREMENT);
				}*/

				playerAnimationCooldown -= 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				
				_player.mSetPosX(fPlayerMove(4, _player.mGetPosX(), _player.mGetPosY()));
				
				//_player.mSetPosX(fPlayerMove2(4, sPlayer, _player.mGetPosX(), _player.mGetPosY()));

				

				/*for (int i = 0; i < vEnemies.size(); i++)
				{
					vEnemies[i].mSetPositionX(vEnemies[i].mGetPositionX() + INCREMENT);
					vEnemyShapes[i].move(INCREMENT, 0);
				}

				for (int i = 0; i < vProjectiles.size(); i++)
				{
					vProjectiles[i].mSetPositionX(vProjectiles[i].mGetPositionX() + INCREMENT);
					vProjectileShapes[i].move(INCREMENT, 0);
				}*/

				playerAnimationCooldown -= 1;
			}
				
			sPlayer.setPosition(_player.mGetPosX(), _player.mGetPosY());

			playerPosition = sPlayer.getPosition();


			FloatRect sPlayerBounds = sPlayer.getGlobalBounds();

			fDebug(2, _player.mGetPosX(), _player.mGetPosY());

			//Mouvement du view du joueur (camera/background du joueur)
			float viewX = clamp(playerPosition.x, halfWidth, mapBounds.width - halfWidth);
			float viewY = clamp(playerPosition.y, halfHeight, mapBounds.height - halfHeight);

			viewDuJoueur.mSetPosition(viewX, viewY);
			viewDuJoueur.mUpdate();
			

			window.setView(viewDuJoueur.mGetView());

			// Rotation joueur par rapport a la souris (v.2 -> Capture seulement dans la "viewDuJoueur" et non dans tout l'ecran
			fDebug(3, Mouse::getPosition().x, Mouse::getPosition().y);
			sf::Vector2i mousePixelPos = sf::Mouse::getPosition(window);
			sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePixelPos, viewDuJoueur.mGetView());
			_player.mRotate(fWindowClamp(mouseWorldPos.x, 'x'), fWindowClamp(mouseWorldPos.y, 'y'), _player);
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
					//sProjectile.setFillColor(sf::Color::Red);
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

					cout << "Player HP : " << _player.mGetHealth() << endl;

					if (_player.mGetHealth() <= 0)
					{
						playerAlive = false;

						cout << "Player died" << endl;
					}
				}
			}
		
			// Défilement des ennemis
			for (int i = vEnemies.size() - 1; i >= 0; i--) //int i = 0; i < vEnemies.size(); i++ //int i = vEnemies.size() - 1; i >= 0; i--
			{
				if (vEnemies[i].mGetHealth() <= 0)
				{
					currentWaveWeight -= vEnemies[i].mGetSpawnWeight();

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
			window.draw(bkgSprite);

			// Dessin des ennemis
			for (int i = 0; i < vEnemyShapes.size(); i++)
			{

			// Dessin du joueur
				Texture tempTexture;

				if (vEnemies[i].mGetAnimationCooldown() <= 0)
				{
					if (vEnemies[i].mGetAnimationPosition() >= 3)
					{
						vEnemies[i].mSetAnimationPosition(0);
					}
					else
					{
						vEnemies[i].mSetAnimationPosition(vEnemies[i].mGetAnimationPosition() + 1);
					}

					vEnemies[i].mSetAnimationCooldown(ANIMATION_COOLDOWN);
				}
				else
				{
					vEnemies[i].mSetAnimationCooldown(vEnemies[i].mGetAnimationCooldown() - 1);
				}

				if (vEnemies[i].mGetID() == 1)
				{
					if (vEnemies[i].mGetAnimationPosition() == 0) { tempTexture.loadFromFile(vSpriteEnemy1[0]); }
					else if (vEnemies[i].mGetAnimationPosition() == 1) { tempTexture.loadFromFile(vSpriteEnemy1[1]); }
					else if (vEnemies[i].mGetAnimationPosition() == 2) { tempTexture.loadFromFile(vSpriteEnemy1[0]); }
					else if (vEnemies[i].mGetAnimationPosition() == 3) { tempTexture.loadFromFile(vSpriteEnemy1[2]); }

					if (vEnemies[i].mGetDmgEffectCooldown() > 0) { tempTexture.loadFromFile(vSpriteEnemy1[3]); }
				}
				else if (vEnemies[i].mGetID() == 2)
				{
					if (vEnemies[i].mGetAnimationPosition() == 0) { tempTexture.loadFromFile(vSpriteEnemy2[0]); }
					else if (vEnemies[i].mGetAnimationPosition() == 1) { tempTexture.loadFromFile(vSpriteEnemy2[1]); }
					else if (vEnemies[i].mGetAnimationPosition() == 2) { tempTexture.loadFromFile(vSpriteEnemy2[0]); }
					else if (vEnemies[i].mGetAnimationPosition() == 3) { tempTexture.loadFromFile(vSpriteEnemy2[2]); }

					if (vEnemies[i].mGetDmgEffectCooldown() > 0) { tempTexture.loadFromFile(vSpriteEnemy2[3]); }
				}
				else if (vEnemies[i].mGetID() == 3)
				{
					if (vEnemies[i].mGetAnimationPosition() == 0) { tempTexture.loadFromFile(vSpriteEnemy3[0]); }
					else if (vEnemies[i].mGetAnimationPosition() == 1) { tempTexture.loadFromFile(vSpriteEnemy3[1]); }
					else if (vEnemies[i].mGetAnimationPosition() == 2) { tempTexture.loadFromFile(vSpriteEnemy3[0]); }
					else if (vEnemies[i].mGetAnimationPosition() == 3) { tempTexture.loadFromFile(vSpriteEnemy3[2]); }

					if (vEnemies[i].mGetDmgEffectCooldown() > 0) { tempTexture.loadFromFile(vSpriteEnemy3[3]); }
				}

				vEnemyShapes[i].setTexture(&tempTexture);

				window.draw(vEnemyShapes[i]); 
			}

			// Dessin des projectiles
			for (int i = 0; i < vProjectileShapes.size(); i++)
			{
				Texture tempTexture; // On crée une texture pour le background
				tempTexture.loadFromFile("assets/sprites/Projectile.png"); // On charge la texture
				vProjectileShapes[i].setTexture(&tempTexture); // On applique la texture au background

				window.draw(vProjectileShapes[i]);
			}

			// Dessin du joueur
			Texture tempTexture;

			if (playerAnimationCooldown <= 0)
			{
				if (playerAnimationPosition >= 3)
				{
					playerAnimationPosition = 0;
				}
				else
				{
					playerAnimationPosition += 1;
				}

				playerAnimationCooldown = ANIMATION_COOLDOWN;
			}

				 if (playerAnimationPosition == 0) { tempTexture.loadFromFile(vSpritePlayer[0]); }
			else if (playerAnimationPosition == 1) { tempTexture.loadFromFile(vSpritePlayer[1]); }
			else if (playerAnimationPosition == 2) { tempTexture.loadFromFile(vSpritePlayer[0]); }
			else if (playerAnimationPosition == 3) { tempTexture.loadFromFile(vSpritePlayer[2]); }

			sPlayer.setTexture(&tempTexture);

			window.draw(sPlayer);

			// Dessin de l'interface
			if (showUpgradeMenu == true)
			{
				for (int i = 0; i < vInterfaceElements.size(); i++)
				{
					window.draw(vInterfaceElements[i]);
				}

				for (int i = 0; i < vInterfaceShapes.size(); i++)
				{
					Texture tempTexture; // On crée une texture pour le background
					tempTexture.loadFromFile("assets/interface/upgrade_card.png"); // On charge la texture
					vInterfaceShapes[i].setTexture(&tempTexture); // On applique la texture au background

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
			// Death screen
			if (playerAlive == false)
			{
					window.draw(deathScreenText);
			}

			// Fin de la frame courante, affichage de tout ce qu'on a dessiné
			window.display();

			clockDraw.restart(); // On remet l’horloge à 0
		}
	}
	return 0;
}
