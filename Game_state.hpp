#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "game.hpp"


// Declaration de la classe GameState
class GameState
{
private:

public:
	Game *game;

	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handleInput() = 0;
};
#endif