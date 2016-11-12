#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "game.hpp"
#include "game_state.hpp"

// Ajoute un �tat � la fin de la pile d'�tats
void Game::pushState(GameState* state) {
	this->states.push(state);
}

// Enleve un �tat de la pile d'�tats
void Game::popState() {
	delete this->states.top();
	this->states.pop();
}

// Changer d'�tat
void Game::changeState(GameState* state) {
	if (!this->states.empty())
		popState();
	pushState(state);
}

// Retourne le sommet de la pile d'�tat (premier �tat)
GameState* Game::peekState() {
	if (this->states.empty())
		return nullptr;
	return this->states.top();
}

// Boucle principale de l'�tat ou vont se d�rouler les actions
// Elle va effacer la fenetre, dessiner ce qui est dedans et ensuite l'afficher � l'�cran
void Game::gameLoop() {
	sf::Clock clock;

	while (this->window.isOpen()) {
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();
		float elapsedtime = elapsed.asMilliseconds();

		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update(dt);
		this->window.clear(sf::Color::Black);
		peekState()->draw(dt);
		this->window.display();
	}
}


Game::Game() {
	this->window.create(sf::VideoMode(600, 400), "MMM The game");
	//this->window.setFramerateLimit(60);
	this->window.setVerticalSyncEnabled(true);
}

Game::~Game() {
	while (!this->states.empty())
		popState();
}