#include "menu.h"
#include "constantes.h"
#include "player.h" 
#include "game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace sf;
using namespace std;




Menu::Menu() {

    inSubMenu = false; // Par défaut, le menu principal est visible
    inHighScore = false;
    //========================================================================================================================
    // Charger la police
    if (!font.loadFromFile("assets/Menu/fonts/Nosifer-Regular.ttf")) {
        cout << "Erreur chargement police";
    }
    //========================================================================================================================
    // Charger l'image de fond
    if (bgTexture.loadFromFile("assets/Menu/background.jpg")) {
        background.setTexture(bgTexture);
    }
    //========================================================================================================================
    // Charger la musique de fond
    if (!backgroundMusic.openFromFile("assets/Menu/music1.ogg")) {
        cout << "Erreur chargement musique";
    }
    else {
        backgroundMusic.setLoop(true); 
        backgroundMusic.play(); 
    }
    //========================================================================================================================
    // Charger le son du click
    if (!clickBuffer.loadFromFile("assets/Menu/click.ogg")) 
    {
        cout << "Erreur chargement son click";
    }
    else 
    {
        clickSound.setBuffer(clickBuffer);
    }
    //========================================================================================================================
    // Fond de la barre de volume
    volumeBarBack.setSize(Vector2f(200, 20));
    volumeBarBack.setFillColor(Color(100, 100, 100));
    volumeBarBack.setPosition(540, 550);
    //========================================================================================================================
    // Remplissage dynamique
    volumeBarFill.setSize(Vector2f(backgroundMusic.getVolume() * 2, 20)); // 
    volumeBarFill.setFillColor(Color::Green);
    volumeBarFill.setPosition(540, 550);
    //========================================================================================================================
    // Texte volume
    volumeText.setFont(font);
    volumeText.setCharacterSize(25);
    volumeText.setFillColor(Color::White);
    volumeText.setPosition(640, 520); // Centré au-dessus de la barre
    volumeText.setOrigin(volumeText.getLocalBounds().width / 2, 0);
    volumeText.setString("Volume : " + std::to_string((int)backgroundMusic.getVolume()) + "%");


    //========================================================================================================================
    // Configuration des éléments du menu principal
    float startY = 300;            
    float spacing = 90.f;

    string labels[4] = { "Commencer une Partie", "Parametres", "Tutoriel", "Quitter" };

    for (int i = 0; i < 4; i++) 
    {
        mainItems[i].setFont(font);
        mainItems[i].setString(labels[i]);
        mainItems[i].setCharacterSize(40);

        FloatRect bounds = mainItems[i].getLocalBounds();
        mainItems[i].setOrigin(bounds.width / 2, bounds.height / 2);
        mainItems[i].setPosition(640, startY + i * spacing);
        mainItems[i].setFillColor(Color::Yellow);
    }
    //========================================================================================================================
    // Configuration des éléments du sous-menu
    startY = 300;
    spacing = 80.f;
    string subLabels[3] = { "Lancer la partie", "High Score", "Retour" };

    for (int i = 0; i < 3; i++) 
    {
        subItems[i].setFont(font);
        subItems[i].setString(subLabels[i]);
        subItems[i].setCharacterSize(35);

        FloatRect bounds = subItems[i].getLocalBounds();
        subItems[i].setOrigin(bounds.width / 2, bounds.height / 2);
        subItems[i].setPosition(640, startY + i * spacing);
        subItems[i].setFillColor(Color::Cyan);
    }
    //========================================================================================================================
    // Configuration du titre

    titre.setFont(font);
    titre.setString("UNDEAD GAME");
    titre.setCharacterSize(80);
    titre.setStyle(sf::Text::Bold);
    FloatRect titreBounds = titre.getLocalBounds();
    titre.setOrigin(titreBounds.left + titreBounds.width / 2.0f, titreBounds.top + titreBounds.height / 2.0f);
    titre.setPosition(640, 80);  

    //========================================================================================================================
    // Ajout d’un menu pour les paramètres
    string settingsLabels[3] = { "Pause Musique", "Volume +", "Volume -" };
    for (int i = 0; i < 3; i++) {
        settingsItems[i].setFont(font);
        settingsItems[i].setString(settingsLabels[i]);
        settingsItems[i].setCharacterSize(35);
        FloatRect bounds = settingsItems[i].getLocalBounds();
        settingsItems[i].setOrigin(bounds.width / 2, bounds.height / 2);
        settingsItems[i].setPosition(640, 300 + i * 80);
        settingsItems[i].setFillColor(Color::White);
    }

    //========================================================================================================================
    // Configuration du Retour de Score
    retourScore.setFont(font);
    retourScore.setString("Retour");
    retourScore.setCharacterSize(30);
    retourScore.setFillColor(Color::Red);

    FloatRect retourBounds = retourScore.getLocalBounds();
    retourScore.setOrigin(retourBounds.width / 2, retourBounds.height / 2);
    retourScore.setPosition(640, 650);  // En bas au centre

    //========================================================================================================================
    // Configuration du Retour de paramettres
    retourParametres.setFont(font);
    retourParametres.setString("Retour");
    retourParametres.setCharacterSize(30);
    retourParametres.setFillColor(Color::White);

    FloatRect retourParamBounds = retourParametres.getLocalBounds();
    retourParametres.setOrigin(retourParamBounds.width / 2, retourParamBounds.height / 2);
    retourParametres.setPosition(640, 650);  

    //========================================================================================================================
    // Configuration du Tutoriel

    sf::Text line;
    line.setFont(font);
    line.setCharacterSize(15);
    line.setFillColor(Color::Green);

    std::vector<std::string> lines = {
    " TUTORIEL : Comment bien jouer a UNDEAD GAME ?",
    "",
    " Controles de base :",
    " - W : Avancer",
    " - A : Aller a gauche",
    " - S : Reculer",
    " - D : Aller a droite",
    " - Souris : Viser dans toutes les directions",
    "",
    " Objectif : Survis face aux vagues de morts-vivants !",
    " - Tire pour les eliminer et gagner des points.",
    " - Chaque seconde compte, la difficulte augmente.",
    "",
    " Conseils pour survivre :",
    " - Bouge constamment pour eviter detre encercle.",
    " - Oriente-toi avec la souris pour viser precisement.",
    " - Ne gaspille pas tes tirs, vise bien.",
    " - Surveille les coins : ne te fais pas pieger !",
    "",
    " Pour marquer un maximum de points :",
    " - Enchaine les eliminations sans te faire toucher.",
    " - Plus tu survis, plus ton score combo augmente.",
    " - Bat ton record dans le menu High Score !",
    "",
    " Appuie sur Echap pour revenir au menu principal."
    };

    

    for (const auto& text : lines) {
        line.setString(text);
        line.setPosition(100.f, startY);
        tutorialText.push_back(line);
        startY += 30.f; // Espace entre les lignes
    }

}

//========================================================================================================================

void Menu::loadScores() {

    ifstream fichier("highscore.txt");
    if (!fichier.is_open()) {
        std::cerr << "Erreur ouverture fichier highscore.txt";
        nbScores = 0;
        return;
    }

    nbScores = 0;
    while (fichier >> noms[nbScores] >> scores[nbScores] && nbScores < MAX_SCORES) {
        nbScores++;
    }
    fichier.close();

    // Tri décroissant
    for (int i = 0; i < nbScores - 1; ++i) {
        for (int j = 0; j < nbScores - i - 1; ++j) {
            if (scores[j] < scores[j + 1]) {
                std::swap(scores[j], scores[j + 1]);
                std::swap(noms[j], noms[j + 1]);
            }
        }
    }

    
    for (int i = 0; i < nbScores; ++i) 
    {
        scoreTexts[i].setFont(font);
        scoreTexts[i].setCharacterSize(30);
        scoreTexts[i].setFillColor(Color::White);
       
        FloatRect bounds = scoreTexts[i].getLocalBounds();
        scoreTexts[i].setOrigin(bounds.width / 2, bounds.height / 2);
        scoreTexts[i].setPosition(640, 200 + i * 40);  // Centrage horizontal et espacement vertical

        string line = noms[i] + " - " + std::to_string(scores[i]);
        scoreTexts[i].setString(line);
    }
}
//========================================================================================================================
void Menu::addScore(const string& nom, int score)
{
    if (nbScores < MAX_SCORES) {
        noms[nbScores] = nom;
        scores[nbScores] = score;
        nbScores++;
    }
    else 
    {
        // Remplacer le score le plus bas si le tableau est plein
        if (score > scores[MAX_SCORES - 1]) {
            noms[MAX_SCORES - 1] = nom;
            scores[MAX_SCORES - 1] = score;
        }
    }

    // Tri des scores
    for (int i = 0; i < nbScores - 1; ++i) {
        for (int j = 0; j < nbScores - i - 1; ++j) {
            if (scores[j] < scores[j + 1]) {
                std::swap(scores[j], scores[j + 1]);
                std::swap(noms[j], noms[j + 1]);
            }
        }
    }

    // Sauvegarder les scores dans le fichier
    std::ofstream fichier("highscore.txt", std::ios::app);
    for (int i = 0; i < nbScores; ++i) {
        fichier << noms[i] << " " << scores[i] << "";
    }
    fichier.close();
}

//========================================================================================================================

void Menu::draw(sf::RenderWindow& window) 
{
    window.clear();
    window.draw(background);
   window.draw(titre);

    // Animation du titre
    float delta = animationClock.restart().asSeconds();
    animationTime += delta;
    hue += delta * 60.f;
    if (hue > 360.f) hue -= 360.f;

    float c = 255.f, x = 255.f * (1 - abs(fmod(hue / 60.0, 2) - 1));
    Color animatedColor;
    if (hue < 60) animatedColor = Color(c, x, 0);
    else if (hue < 120) animatedColor = Color(x, c, 0);
    else if (hue < 180) animatedColor = Color(0, c, x);
    else if (hue < 240) animatedColor = Color(0, x, c);
    else if (hue < 300) animatedColor = Color(x, 0, c);
    else animatedColor = Color(c, 0, x);

    // Effet de rebond vertical
    float bounce = sin(animationTime * 2.f) * 10.f;

    // Effet d’agrandissement/zoom progressif
    float scale = 1.f + 0.05f * sin(animationTime * 1.5f);
    titre.setScale(scale, scale);
    titre.setPosition(640, 80 + bounce);
    titre.setFillColor(animatedColor);
    window.draw(titre);  // Afficher le titre animé

    if (inHighScore)
    {
        for (int i = 0; i < nbScores; ++i)
        { 
            window.draw(scoreTexts[i]);
        }
        window.draw(retourScore);
    }
    else if (inSubMenu) 
    {
        for (int i = 0; i < 3; i++)
            window.draw(subItems[i]);
    }
    else if (inSettings) 
    {
        float vol = backgroundMusic.getVolume();
        volumeBarFill.setSize(Vector2f(vol * 2, 20)); // max 200px
        volumeText.setString("Volume : " + to_string((int)vol) + "%");
        FloatRect volBounds = volumeText.getLocalBounds();
        volumeText.setOrigin(volBounds.width / 2, 0);

        for (int i = 0; i < 3; i++) 
        {
            window.draw(settingsItems[i]);
        }
            window.draw(volumeText);
            window.draw(volumeBarBack);
            window.draw(volumeBarFill);
            window.draw(retourParametres);
    }
    else if (inTutorial) 
    {
        for (const auto& line : tutorialText)
        {
            sf::Text tempLine = line;
            sf::Vector2f pos = tempLine.getPosition();
            pos.y -= tutorialScrollOffset;  // appliquer l’offset
            tempLine.setPosition(pos);

             //afficher uniquement les lignes visibles
            if (pos.y + tempLine.getCharacterSize() > 0 && pos.y < 720)
                window.draw(tempLine);
        }
    }
    else 
    {
        for (int i = 0; i < 4; i++)
            window.draw(mainItems[i]);
    }
    window.display();
}
//========================================================================================================================
void Menu::moveUp() 
{

    if (inSettings) 
    {
        if (selectedSettingsIndex > 0) 
            selectedSettingsIndex--;
        updateColors();
        return;
    }
    else if (inSubMenu) 
    {
        if (selectedSubIndex > 0) 
            selectedSubIndex--;
    }
    else 
    {
        if (selectedMainIndex > 0) 
            selectedMainIndex--;
    }
    updateColors();
}
//========================================================================================================================
void Menu::moveDown() 
{
    if (inSettings) {
        if (selectedSettingsIndex < 2)
            selectedSettingsIndex++;
        updateColors();
        return;
    }
    else if (inSubMenu) 
    {
        if (selectedSubIndex < 2) 
            selectedSubIndex++;
    }
    else 
    {
        if (selectedMainIndex < 3) 
            selectedMainIndex++;
    }
    updateColors();
}
//========================================================================================================================
void Menu::updateColors()
{
    // Mise à jour des couleurs pour le menu principal
    for (int i = 0; i < 4; i++) {
        if (i == selectedMainIndex) {
            mainItems[i].setFillColor(Color::Yellow);  
        }
        else {
            mainItems[i].setFillColor(Color::White);  
        }
    }

    // Mise à jour des couleurs pour le sous-menu
    for (int i = 0; i < 3; i++) {
        if (i == selectedSubIndex) {
            subItems[i].setFillColor(Color::Cyan);  
        }
        else {
            subItems[i].setFillColor(Color::White); 
        }
    }
}

void Menu::handleMouse(const Vector2f& pos)
{
    if (inHighScore) 
    {
        if (retourScore.getGlobalBounds().contains(pos)) {
            inHighScore = false;
            inSubMenu = false;
            updateColors();
            return;
        }
    }
    else if (inSettings)
    {
        if (retourParametres.getGlobalBounds().contains(pos)) {
            inSettings = false;
            updateColors();
            return;
        }

        for (int i = 0; i < 3; i++)
        {
            if (settingsItems[i].getGlobalBounds().contains(pos)) {
                selectedSettingsIndex = i;
                updateColors();
            }
        }
    }
    else if (inSubMenu) 
    {
       for (int i = 0; i < 3; i++) 
       {
            if (subItems[i].getGlobalBounds().contains(pos)) 
            {
                selectedSubIndex = i;
                updateColors();
            }
       }
    }
    else {
        for (int i = 0; i < 4; i++) 
        {
            if (mainItems[i].getGlobalBounds().contains(pos)) 
            {
                selectedMainIndex = i;
                updateColors();
            }
        }
    }
}

void Menu::select() 
{
    playClickSound();
    if (inSettings) 
    {
        switch (selectedSettingsIndex) 
        {
        case 0:
            if (backgroundMusic.getStatus() == Music::Playing)
                backgroundMusic.pause();
            else
                backgroundMusic.play();
            break;
        case 1:
            backgroundMusic.setVolume(min(100.f, backgroundMusic.getVolume() + 10));
            break;
        case 2:
            backgroundMusic.setVolume(max(0.f, backgroundMusic.getVolume() - 10));
            break;
        }
        return;
    }
    else if (inSubMenu) 
    {
        switch (selectedSubIndex) 
        {
        case 0: 
            cout << "Lancer la partie";
            {
                Game game;
                game.mPlay();
            }
            break;
        case 1: 
            cout << "High Score"; 
            loadScores();
            inHighScore = true;
            break;
        case 2: 
            inSubMenu = false;
            inHighScore = false;
            break;
        }

    }
    else 
    {
        switch (selectedMainIndex) 
        {
        case 0: 
            inSubMenu = true;
            break;
        case 1:
            cout << "Paramètres";
            inSettings = true;
            break;
        case 2:
            cout << "Tutoriel";
            inTutorial = true;
            break;
        case 3:
            exit(0);
            break;
        }
        
    }
    if (Keyboard::isKeyPressed(Keyboard::BackSpace)) 
    {
        inSettings = false;
        updateColors();
    }
}


void Menu::boucleAffiche(sf::RenderWindow& window)
{

    
        while (window.isOpen()) 
        {
            Event event;
            
            while (window.pollEvent(event)) 
            {
                if (event.type == Event::Closed) 
                {
                    window.close();
                }
                else if (event.type == Event::KeyPressed) 
                {
                    switch (event.key.code) 
                    {
                    case Keyboard::Escape:
                        window.close();
                        break;
                    case Keyboard::W:
                        moveUp();
                        if (inTutorial) tutorialScrollOffset = max(0.f, tutorialScrollOffset - 30.f);
                        break;
                    case Keyboard::S:
                        moveDown();
                        if (inTutorial) tutorialScrollOffset += 30.f;
                        break;
                    case Keyboard::Enter:
                        select();
                        break;
                    default:
                        break;
                    }
                }
                else if (event.type == Event::MouseMoved)
                {
                    // Détection de la position pour hover
                    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                    handleMouse(mousePos);  // met à jour les couleurs selon la position
                }
                else if (event.type == Event::MouseWheelScrolled)
                {
                    if (inTutorial)
                    {
                        tutorialScrollOffset -= event.mouseWheelScroll.delta * 30.f;
                        if (tutorialScrollOffset < 0.f)
                            tutorialScrollOffset = 0.f;
                    }
                }

                else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
                {
                    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                    handleMouse(mousePos);  // met à jour l’élément sélectionné
                    select();               // effectue l’action de sélection
                }
                
            }
            draw(window);
           
        }

            
}

void Menu::playClickSound()
{
    clickSound.play();
}
