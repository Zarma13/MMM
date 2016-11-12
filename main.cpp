#include "game.hpp"
#include "game_state_start.hpp"

int main()
{
	Game game;

	// Mettre l'�tat en �tat de d�marrage
	game.pushState(new GameStateStart(&game));

	// Boucle du jeu
	game.gameLoop();

	return 0;
}