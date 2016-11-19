#ifndef GAME_STATE_START_HPP
#define GAME_STATE_START_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Game_state.hpp"

// Déclaration de la classe GameStateStart
class GameStateStart : public GameState
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
	sf::Music music;
	float x = 0;
public:
	// Déclaration des fonctions
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	void load_music(std::string title);
	void levitating_title();

	// Déclaration du constructeur
	GameStateStart(Game* game);
};
#endif