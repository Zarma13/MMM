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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				shape.setPosition(posx += 1, 100);
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
		//MODIF
	}

	return 0;
}