#pragma once

#include "constantes.h"
#include "constantes.h"
#include "player.h"  // Pour accéder aux dimensions ou constantes similaires
#include "game.h" 

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class Menu
{
private:
    sf::Font font;
    sf::Music backgroundMusic;
    sf::Text mainItems[4];
    sf::Text subItems[3];
    sf::Text retourScore;
    sf::Text retourParametres;
    int selectedMainIndex = 0;
    int selectedSubIndex = 0;
    bool inSubMenu = false;
    int selectedSettingsIndex = 0;
    sf::Text settingsItems[3];
    bool inSettings = false;
    bool inTutorial = false;
    std::vector<sf::Text> tutorialText;
    float tutorialScrollOffset = 0.f;


    sf::Texture bgTexture;
    sf::Sprite background;
    sf::SoundBuffer clickBuffer;
    sf::Sound clickSound;
    sf::Text titre;
    float animationTime = 0.f;
    sf::Clock animationClock;
    float hue = 0.f;

    static const int MAX_SCORES = 10;
    std::string noms[MAX_SCORES];
    int scores[MAX_SCORES];
    int nbScores = 0;
    bool inHighScore = false;

    sf::Text scoreTexts[MAX_SCORES];

    sf::RectangleShape volumeBarBack;
    sf::RectangleShape volumeBarFill;
    sf::Text volumeText;

public:
    Menu();
    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();
    void updateColors();
    void handleMouse(const sf::Vector2f& pos);
    void select();
    void loadScores();
    void addScore(const std::string& nom, int score);
    void boucleAffiche(sf::RenderWindow& window);
    void playClickSound();
    
};
