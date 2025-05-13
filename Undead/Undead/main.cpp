#include "game.h"

using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Undead Game");
	Menu menu;  // Crée une instance du menu

	// Lance la boucle d'affichage du menu
	menu.boucleAffiche(window);

	// Start
	Game game;
	game.mPlay();

	//========================================================================================================================
	// Fin
	cout << endl;
	system("pause");
	return 0;

}
