#ifndef GAME_HPP
#define GAME_HPP

#include <stack>
#include <SFML/Graphics.hpp>

class GameState;

// D�claration de la classe Game
class Game {
public:
	float elapsedtime;
	std::stack<GameState*> states;
	sf::RenderWindow window;
	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* peekState();

	void gameLoop();

	Game();
	~Game();
	// D�claration du getter

};
#endif