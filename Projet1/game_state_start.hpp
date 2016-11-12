#ifndef MENU_PRINCIPAL_HPP
#define MENU_PRINCIPAL_HPP

#include <SFML/Graphics.hpp>

#include "Game_state.hpp"

// Déclaration de la classe MenuPrincipal
class MenuPrincipal : public GameState
{
private:
	// Déclaration des variables
	void loadgame();
	void loadcre();
	sf::Text nameGame;
	sf::Text NewGame;
	sf::Text LoadGame;
	sf::Font font;
	sf::RectangleShape selector;
public:
	// Déclaration des fonctions
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	// Déclaration du constructeur
	MenuPrincipal(Game* game);
};
#endif