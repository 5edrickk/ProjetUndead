#include "game.h"

using namespace std;

int main() {
	//========================================================================================================================
	// Boucle de menu principal
  /*
	int choix = afficherMenuPrincipal(window);

	if (choix == 1) {
		sf::Font font;
		font.loadFromFile("assets/Menu/fonts/Arial_Bold_Italic.ttf");
		int sousChoix = afficherMenuJouer(window, font);

		if (sousChoix == 1) {
			// Lancer la partie ici
			// demarrerPartie(window);
		}
		else if (sousChoix == 2) {
			// Voir les meilleurs scores ici
			//cout<< afficherNouvelHighScore(window);
		}
		// Retour ne fait rien, il retourne au menu principal
	}
	else if (choix == 2) {
		std::cout << "Paramètres sélectionnés" << endl;
		// Afficher ou gérer les paramètres
	}
	else if (choix == 3) {
		std::cout << "Affichage du tutoriel" << endl;
		// Afficher le tutoriel
	}
	else if (choix == 4 || choix == -1) {
		std::cout << "Quitter le jeu" << endl;
		window.close();
		return 0;
		// Fermer le jeu
	}
*/
  //========================================================================================================================
	// Start
	Game game;
	game.mPlay();

	system("pause");
	return 0;

}
