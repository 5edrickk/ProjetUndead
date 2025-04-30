#include "menu.h"

using namespace sf;
using namespace std;

int afficherMenuPrincipal(RenderWindow& window) {
    // Charger la police
    Font font;
    if (!font.loadFromFile("assets/Menu/fonts/Arial_Bold_Italic.ttf")) {  
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
    const float BUTTON_WIDTH = PLAYER_SIZE * 6;
    const float BUTTON_HEIGHT = PLAYER_SIZE * 2;
    const float BUTTON_SPACING = 30;
    const float CORNER_RADIUS = 20;  // Rayon des coins arrondis

    Vector2f windowCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);

    // Options du menu
    string labels[] = { "Jouer", "Paramètres", "Tutoriel", "Quitter" };
    RectangleShape boutons[4];
    Text textes[4];
   

    // Créer et styliser les boutons et textes
    for (int i = 0; i < 4; ++i) {
        boutons[i].setSize(Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
        boutons[i].setOrigin(BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2);
        boutons[i].setPosition(windowCenter.x, windowCenter.y + i * (BUTTON_HEIGHT + BUTTON_SPACING));

        // Style de bordure pour les boutons
        boutons[i].setOutlineThickness(5);  // Épaisseur de la bordure
        boutons[i].setOutlineColor(Color::Black);  // Couleur de la bordure (ici noire)
        boutons[i].setFillColor(Color(100, 100, 255));  // Couleur initiale

        textes[i].setFont(font);
        textes[i].setString(labels[i]);
        textes[i].setCharacterSize(30);  // Plus gros pour être lisible
        textes[i].setFillColor(Color::White);  // Couleur blanche pour le texte

        FloatRect textRect = textes[i].getLocalBounds();
        textes[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        textes[i].setPosition(boutons[i].getPosition());
    }

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
                        return i + 1;  // 1: Jouer, 2: Paramètres, etc.
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

        // Effacer la fenêtre et redessiner le menu
        window.clear(Color(30, 30, 30));  // Fond sombre pour un meilleur contraste

        // Dessiner l'image de fond
        window.draw(backgroundSprite);
        
        for (int i = 0; i < 4; ++i) {
            window.draw(boutons[i]);
            window.draw(textes[i]);
        }

        window.display();
    }

    return -1;  // Retourne -1 si la fenêtre est fermée sans option sélectionnée
}

