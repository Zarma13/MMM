#ifndef GAME_STATE_START_HPP
#define GAME_STATE_START_HPP

#include <SFML/Graphics.hpp>

#include "Game_state.hpp"

// D�claration de la classe GameStateStart
class GameStateStart : public GameState
{
private:
	// D�claration des variables
	void loadgame();
	void loadcre();
	sf::Text nameGame;
	sf::Text NewGame;
	sf::Text LoadGame;
	sf::Font font;
	sf::RectangleShape selector;
public:
	// D�claration des fonctions
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	// D�claration du constructeur
	GameStateStart(Game* game);
};
#endif