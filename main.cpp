#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(10);
	shape.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				shape.setPosition(shape.getPosition().x, shape.getPosition().y + 1);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				shape.setPosition(shape.getPosition().x - 1, shape.getPosition().y);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				shape.setPosition(shape.getPosition().x, shape.getPosition().y - 1);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				shape.setPosition(shape.getPosition().x + 1, shape.getPosition().y);
		}

		window.clear();
		window.draw(shape);
		window.display();
		//MODIF
	}

	return 0;
}