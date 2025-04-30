#include "menu.h"
#include "player.h" // pour accéder aux constantes ou dimensions similaires
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int afficherMenuPrincipal(RenderWindow& window) {
    Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        cerr << "Erreur chargement police" << endl;
        return -1;
    }

    const float BUTTON_WIDTH = PLAYER_SIZE * 4;
    const float BUTTON_HEIGHT = PLAYER_SIZE * 1.5;
    const float BUTTON_SPACING = 30;

    Vector2f windowCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);

    string labels[] = { "Jouer", "Paramètres", "Tutoriel", "Quitter" };
    RectangleShape boutons[4];
    Text textes[4];

    for (int i = 0; i < 4; ++i) {
        boutons[i].setSize(Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
        boutons[i].setOrigin(BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2);
        boutons[i].setPosition(windowCenter.x, windowCenter.y + i * (BUTTON_HEIGHT + BUTTON_SPACING));
        boutons[i].setFillColor(Color(100, 100, 255));

        textes[i].setFont(font);
        textes[i].setString(labels[i]);
        textes[i].setCharacterSize(24);
        textes[i].setFillColor(Color::White);

        FloatRect textRect = textes[i].getLocalBounds();
        textes[i].setOrigin(textRect.left + textRect.width / 2.0f,
            textRect.top + textRect.height / 2.0f);
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
                for (int i = 0; i < 4; ++i) {
                    if (boutons[i].getGlobalBounds().contains(Vector2f(souris))) {
                        return i + 1; // 1: Jouer, 2: Paramètres, etc.
                    }
                }
            }
        }

        for (int i = 0; i < 4; ++i) {
            if (boutons[i].getGlobalBounds().contains(Vector2f(souris))) {
                boutons[i].setFillColor(Color(150, 150, 255));
            }
            else {
                boutons[i].setFillColor(Color(100, 100, 255));
            }
        }

        window.clear(Color(30, 30, 30));
        for (int i = 0; i < 4; ++i) {
            window.draw(boutons[i]);
            window.draw(textes[i]);
        }
        window.display();
    }

    return -1;
}


