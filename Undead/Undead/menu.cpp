#include "menu.h"
#include "constantes.h"
#include "player.h"  // Pour accéder aux dimensions ou constantes similaires

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>

using namespace sf;
using namespace std;

struct ScoreEntry {
    string nom;
    int score;
};

// Fonction pour lire les meilleurs scores depuis un fichier
vector<ScoreEntry> lireTousLesScores() {
    vector<ScoreEntry> scores;
    ifstream fichier("highscore.txt");
    if (!fichier.is_open()) return scores;

    string nom;
    int score;
    while (fichier >> nom >> score) {
        scores.push_back({ nom, score });
    }

    fichier.close();
    sort(scores.begin(), scores.end(), [](const ScoreEntry& a, const ScoreEntry& b) {
        return a.score > b.score;  // Tri décroissant
        });

    return scores;
}

// Fonction pour afficher les scores dans un tableau
void afficherTableauScores(RenderWindow& window, Font& font) {
    auto scores = lireTousLesScores();

    RectangleShape fond(Vector2f(window.getSize()));
    fond.setFillColor(Color(0, 0, 0, 220));

    Text titre;
    titre.setFont(font);
    titre.setString("Meilleurs Scores");
    titre.setCharacterSize(40);
    titre.setFillColor(Color::Yellow);
    titre.setPosition(100, 50);

    vector<Text> textes;
    int yOffset = 120;

    for (size_t i = 0; i < scores.size() && i < 10; ++i) {
        Text ligne;
        ligne.setFont(font);
        ligne.setCharacterSize(26);
        ligne.setFillColor(Color::White);
        ligne.setString(to_string(i + 1) + ". " + scores[i].nom + " - " + to_string(scores[i].score));
        ligne.setPosition(100, yOffset + i * 40);
        textes.push_back(ligne);
    }

    // Bouton retour
    RectangleShape boutonRetour(Vector2f(200, 50));
    boutonRetour.setFillColor(Color(100, 100, 255));
    boutonRetour.setPosition(100, window.getSize().y - 80);

    Text texteRetour;
    texteRetour.setFont(font);
    texteRetour.setString("Retour");
    texteRetour.setCharacterSize(24);
    texteRetour.setFillColor(Color::White);
    texteRetour.setPosition(130, window.getSize().y - 75);

    while (window.isOpen()) {
        Event event;
        Vector2i souris = Mouse::getPosition(window);
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return;
            }
            if (event.type == Event::MouseButtonPressed && boutonRetour.getGlobalBounds().contains(Vector2f(souris))) {
                return; // Quitter la vue des scores
            }
        }

        boutonRetour.setFillColor(boutonRetour.getGlobalBounds().contains(Vector2f(souris)) ? Color::Red : Color(100, 100, 255));

        window.clear();
        window.draw(fond);
        window.draw(titre);
        for (const auto& t : textes) window.draw(t);
        window.draw(boutonRetour);
        window.draw(texteRetour);
        window.display();
    }
}

int afficherMenuJouer(RenderWindow& window, Font& font) {
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("assets/Menu/background.jpg");
    Sprite backgroundSprite(backgroundTexture);

    const float BUTTON_WIDTH = PLAYER_SIZE *12 ;
    const float BUTTON_HEIGHT = PLAYER_SIZE * 2;
    const float BUTTON_SPACING = 40;
    Vector2f windowCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);

    string labels[] = { "Lancer la partie", "High Score", "Retour" };
    RectangleShape boutons[3];
    Text textes[3];

    for (int i = 0; i < 3; ++i) {
        boutons[i].setSize(Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
        boutons[i].setOrigin(BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2);
        boutons[i].setPosition(windowCenter.x, windowCenter.y + i * (BUTTON_HEIGHT + BUTTON_SPACING));
        boutons[i].setFillColor(Color(100, 100, 255));
        boutons[i].setOutlineThickness(4);
        boutons[i].setOutlineColor(Color::White);

        textes[i].setFont(font);
        textes[i].setString(labels[i]);
        textes[i].setCharacterSize(30);
        textes[i].setFillColor(Color::White);

        FloatRect textRect = textes[i].getLocalBounds();
        textes[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        textes[i].setPosition(boutons[i].getPosition());
    }

    while (window.isOpen()) {
        Event event;
        Vector2i souris = Mouse::getPosition(window);

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return -1;
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                for (int i = 0; i < 3; ++i) {
                    if (boutons[i].getGlobalBounds().contains(Vector2f(souris))) {
                        if (i == 0) return 1; // Lancer la partie
                        else if (i == 1) afficherTableauScores(window, font); // Affiche les scores
                        else if (i == 2) return 3; // Retour
                    }
                }
            }
        }

        for (int i = 0; i < 3; ++i) {
            boutons[i].setFillColor(boutons[i].getGlobalBounds().contains(Vector2f(souris)) ? Color::Red : Color(100, 100, 255));
        }

        window.clear();
        window.draw(backgroundSprite);
        for (int i = 0; i < 3; ++i) {
            window.draw(boutons[i]);
            window.draw(textes[i]);
        }
        window.display();
    }

    return -1;
}

int afficherTutoriel(RenderWindow& window, Font& font) {
    // Charger l'image ou texture du tutoriel (remplace par une vidéo si nécessaire avec une lib externe)
    Texture tutoTexture;
    if (!tutoTexture.loadFromFile("assets/Menu/tutoriel.jpg")) {
        cerr << "Erreur chargement tutoriel" << endl;
        return -1;
    }
    Sprite tutoSprite(tutoTexture);

    // Créer le bouton Retour
    RectangleShape boutonRetour(Vector2f(200, 60));
    boutonRetour.setPosition(window.getSize().x / 2 - 100, window.getSize().y - 100);
    boutonRetour.setFillColor(Color(100, 100, 255));
    boutonRetour.setOutlineThickness(3);
    boutonRetour.setOutlineColor(Color::White);

    Text texteRetour;
    texteRetour.setFont(font);
    texteRetour.setString("Retour");
    texteRetour.setCharacterSize(24);
    texteRetour.setFillColor(Color::White);
    texteRetour.setPosition(boutonRetour.getPosition().x + 50, boutonRetour.getPosition().y + 10);

    while (window.isOpen()) {
        Event event;
        Vector2i souris = Mouse::getPosition(window);

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return -1;
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                if (boutonRetour.getGlobalBounds().contains(Vector2f(souris))) {
                    return 3; // Retour
                }
            }
        }

        boutonRetour.setFillColor(
            boutonRetour.getGlobalBounds().contains(Vector2f(souris)) ? Color::Red : Color(100, 100, 255));

        window.clear();
        window.draw(tutoSprite);
        window.draw(boutonRetour);
        window.draw(texteRetour);
        window.display();
    }

    return -1;
}



int afficherMenuPrincipal(RenderWindow& window) {
    // Charger la police
    Font font;
    if (!font.loadFromFile("assets/Menu/fonts/Nosifer-Regular.ttf")) {  
        cerr << "Erreur chargement police" << endl;
        return -1;
    }


    // Charger la musique de fond
    Music backgroundMusic;
    if (!backgroundMusic.openFromFile("assets/Menu/music1.ogg")) { 
        cerr << "Erreur chargement musique" << endl;
        return -1;
    }
    backgroundMusic.setLoop(true);
    backgroundMusic.play();  // Joue la musique en boucle

    // Charger l'image de fond
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/Menu/background.jpg")) {  // Assure-toi que l'image est dans le bon répertoire
        cerr << "Erreur chargement image de fond" << endl;
        return -1;
    }
    Sprite backgroundSprite(backgroundTexture);

    // Dimensions des boutons basées sur PLAYER_SIZE pour cohérence avec le jeu
    const float BUTTON_WIDTH = PLAYER_SIZE * 15;
    const float BUTTON_HEIGHT = PLAYER_SIZE * 2;
    const float BUTTON_SPACING = 35;
    const float CORNER_RADIUS = 20;  // Rayon des coins arrondis

    Vector2f windowCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);

    // Options du menu
    string labels[] = { "Commencer un Partie", "Parametres", "Tutoriel", "Quitter" };
    RectangleShape boutons[4];
    Text textes[4];
   

    // Créer et styliser les boutons et textes
    for (int i = 0; i < 4; ++i) {
        boutons[i].setSize(Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
        boutons[i].setOrigin(BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2);
        boutons[i].setPosition(windowCenter.x, windowCenter.y + i * (BUTTON_HEIGHT + BUTTON_SPACING));

        // Style de bordure pour les boutons
        boutons[i].setOutlineThickness(5);  // Épaisseur de la bordure
        boutons[i].setOutlineColor(Color::White);  // Couleur de la bordure (ici noire)
        boutons[i].setFillColor(Color(100, 100, 255));  // Couleur initiale

        textes[i].setFont(font);
        textes[i].setString(labels[i]);
        textes[i].setCharacterSize(30);  // Plus gros pour être lisible
        textes[i].setFillColor(Color::White);  // Couleur blanche pour le texte

        FloatRect textRect = textes[i].getLocalBounds();
        textes[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        textes[i].setPosition(boutons[i].getPosition());
    }
    

    // Texte animé du titre "UNDEAD"
    Text titre;
    titre.setFont(font);
    titre.setString("UNDEAD GAME");
    titre.setCharacterSize(80);
    titre.setStyle(Text::Bold);
    titre.setPosition(windowCenter.x, windowCenter.y - 160);
    FloatRect titreBounds = titre.getLocalBounds();
    titre.setOrigin(titreBounds.left + titreBounds.width / 2.0f, titreBounds.top + titreBounds.height / 2.0f);

    Clock animationClock;
    float hue = 0.f;

    // Boucle de gestion de la fenêtre
    while (window.isOpen()) {
        Event event;
        Vector2i souris = Mouse::getPosition(window);

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return -1;
            }

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                for (int i = 0; i < 4; ++i) {
                    if (boutons[i].getGlobalBounds().contains(Vector2f(souris))) {
                        if (i == 0) {
                            // Appel à afficherMenuJouer
                            int resultat = afficherMenuJouer(window, font);

                            if (resultat == -1) {
                                return -1;  // Si un problème survient dans afficherMenuJouer
                            }
                            else if (resultat == 1)
                            {
                                return 1;
                            }
                        }

                        else if (i == 1) {
                            return 1; // Paramètres
                        }
                        else if (i == 2) {
                            int resultat = afficherTutoriel(window, font); // Tutoriel
                            if (resultat == -1) return -1;
                        }
                        else if (i == 3) {
                            continue;  // Quitter
                        }
                        
                    }
                }
            }
        }
            
    

        // Survol de la souris sur les boutons
        for (int i = 0; i < 4; ++i) {
            if (boutons[i].getGlobalBounds().contains(Vector2f(souris))) {
                boutons[i].setFillColor(Color::Red);    // Changer la couleur survolée

                // Augmenter la taille du bouton pour un effet visuel
                boutons[i].setScale(1.1f, 1.1f);  // Agrandir légèrement
                
            }
            else {
                boutons[i].setFillColor(Color(100, 100, 255));  // Couleur normale
            }
        }
        // Animation de la couleur du titre
        hue += animationClock.restart().asSeconds() * 60;
        if (hue > 360.f) hue -= 360.f;

        float c = 255, x = 255 * (1 - abs(fmod(hue / 60.0, 2) - 1));
        Color animatedColor;
        if (hue < 60) animatedColor = Color(c, x, 0);
        else if (hue < 120) animatedColor = Color(x, c, 0);
        else if (hue < 180) animatedColor = Color(0, c, x);
        else if (hue < 240) animatedColor = Color(0, x, c);
        else if (hue < 300) animatedColor = Color(x, 0, c);
        else animatedColor = Color(c, 0, x);

        titre.setFillColor(animatedColor);

        // Effacer la fenêtre et redessiner le menu
        window.clear(Color(30, 30, 30));  // Fond sombre pour un meilleur contraste
        // Dessiner l'image de fond
        window.draw(backgroundSprite);
        window.draw(titre);
        for (int i = 0; i < 4; ++i) {
            window.draw(boutons[i]);
            window.draw(textes[i]);
        }

        window.display();
    }

    return -1;  // Retourne -1 si la fenêtre est fermée sans option sélectionnée
}

