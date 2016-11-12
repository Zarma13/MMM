#include "game.hpp"
#include "game_state_start.hpp"

int main()
{
	Game game;

	// Mettre l'état en état de démarrage
	game.pushState(new GameStateStart(&game));

	// Boucle du jeu
	game.gameLoop();

	return 0;
}