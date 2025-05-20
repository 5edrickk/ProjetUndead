#include "game.h"

using namespace std;

int main() {

	// Lance la boucle d'affichage du menu
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Undead Game");
	Menu menu;  // Crée une instance du menu
	menu.boucleAffiche(window);
	
	// Start
	Game game;
	game.mPlay();

	system("pause");
	return 0;

}
