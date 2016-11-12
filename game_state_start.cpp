#include <SFML/Graphics.hpp>

#include "Game_state_start.hpp"
#include "Game_state.hpp"


// Définition de la fonction Draw pour dessiner la fenetre
void GameStateStart::draw(const float dt){
	this->game->window.clear(sf::Color(144, 152, 152));
	this->game->window.draw(nameGame);
	this->game->window.draw(NewGame);
	this->game->window.draw(LoadGame);
	this->game->window.draw(selector);
}

void GameStateStart::update(const float dt){

}

// Définition de la fonction GameStateStart qui chargera les élément de la fenetre
GameStateStart::GameStateStart(Game* game){
	this->game = game;
	if(!font.loadFromFile("arial.ttf")){}
	
	nameGame.setFont(font);
	nameGame.setFillColor(sf::Color::Black);
	nameGame.setString("Donjon Pyramidal");
	nameGame.setPosition(100,50);
	nameGame.setCharacterSize(50);
	nameGame.setStyle(sf::Text::Italic);
	
	NewGame.setFont(font);
	NewGame.setString("New Game");
	NewGame.setFillColor(sf::Color::White);
	sf::FloatRect textRect = NewGame.getLocalBounds();
	NewGame.setOrigin(textRect.width/2,textRect.height/1);
	NewGame.setPosition(sf::Vector2f(this->game->window.getSize().x*0.25, this->game->window.getSize().y/2));
	
	LoadGame.setFont(font);
	LoadGame.setString("Load Game");
	LoadGame.setFillColor(sf::Color::White);
	textRect = LoadGame.getLocalBounds();
	LoadGame.setOrigin(textRect.width/2,textRect.height/1);
	LoadGame.setPosition(sf::Vector2f(this->game->window.getSize().x*0.75, this->game->window.getSize().y/2));
	
	selector.setSize(sf::Vector2f(190, 60));
	selector.setOutlineColor(sf::Color(154, 218, 221));
	selector.setFillColor(sf::Color::Transparent);
	selector.setOutlineThickness(5);
	textRect = selector.getLocalBounds();
	selector.setOrigin(textRect.width/2,textRect.height/2);
	selector.setPosition(sf::Vector2f(this->game->window.getSize().x*0.25, this->game->window.getSize().y/2));
}

// Gestion des évènements
void GameStateStart::handleInput()
{
	sf::Event event;
	while(this->game->window.pollEvent(event))
	{
		switch(event.type)
		{
			/* Close the window */
			case sf::Event::Closed:{
				game->window.close();
				break;
			}
			// Si touche pressée
			case sf::Event::KeyPressed:{
				if(event.key.code == sf::Keyboard::Escape)
					this->game->window.close();
				if(event.key.code == sf::Keyboard::Space){
					//SafeGuard(this->game->getSafeGuardList(), "papy", "vieux", 88, "level-2");
				}
				if(event.key.code == sf::Keyboard::Return && selector.getPosition() == sf::Vector2f(this->game->window.getSize().x*0.75, this->game->window.getSize().y/2))
					this->loadgame();
				if(event.key.code == sf::Keyboard::Return && selector.getPosition() == sf::Vector2f(this->game->window.getSize().x*0.25, this->game->window.getSize().y/2))
					this->loadcre();
				if(event.key.code == sf::Keyboard::Right)
					selector.setPosition(sf::Vector2f(this->game->window.getSize().x*0.75, this->game->window.getSize().y/2));
				if(event.key.code == sf::Keyboard::Left)
					selector.setPosition(sf::Vector2f(this->game->window.getSize().x*0.25, this->game->window.getSize().y/2));
				break;
			}
			default:
			break;
		}
	}
}


// Démarrer le jeu
void GameStateStart::loadgame(){
	//this->game->pushState(new GameStateStartPageLoadGame(this->game));
}void GameStateStart::loadcre(){
	//this->game->pushState(new GameStateCreate(this->game));
}