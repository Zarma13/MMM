#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>

class Player
{

private:
	std::string m_name;
	unsigned int m_life;
	unsigned int m_size;

public:
	//D�claration des constructeurs
	Player();
	Player(std::string name, unsigned int life, unsigned int size);

	//d�claration du destructeur
	~Player();

};

#endif