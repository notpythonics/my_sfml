#include <iostream>
#include <SFML/Graphics.hpp>

constexpr float WIDTH = 800;
constexpr float HEIGHT = 600;

int main(){
	sf::ContextSettings context; // a collection of varibales
	context.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "game", sf::Style::Default, context);
	sf::CircleShape shape(20.0f);
	shape.setFillColor(sf::Color::Magenta);
	shape.setPosition(100.0f, 100.0f);

	sf::RectangleShape rectangle (sf::Vector2f(100,40));
	rectangle.setFillColor(sf::Color::Magenta);
	rectangle.setOrigin(sf::Vector2f(50, 20)); // change the pivot    half of the the size
	rectangle.setPosition(sf::Vector2f(400, 400));
	rectangle.setRotation(90);
	

	sf::Texture player_texture;
	sf::Sprite player_sprite;
	player_sprite.setScale(sf::Vector2f(0.2, 0.2));

	if (!player_texture.loadFromFile("assests\\player.png")) {
		std::cout << 'n';
		return 1;
	}
	player_sprite.setTexture(player_texture);

	//game loop
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) { // iterate over the window's queue   [closed  mouse_pressed  ]
										 // on each iterating assign the event to sf::event object
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::D)
					player_sprite.setPosition(player_sprite.getPosition() + sf::Vector2f(50,0));
			}
		}
		// clearing without displaying throws an exception
		window.clear(sf::Color::Black); // clear bellon al asoad     it's on the back buffer
		
		window.draw(shape);
		window.draw(player_sprite);
		window.draw(rectangle);

		window.display(); // copies the data from the back buffer to the screen
	}
}