#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100);
	shape.setFillColor(sf::Color::Green);
	int pos_x = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::key.LEFT)
				sf::CircleShape shape(pos_x++);
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}