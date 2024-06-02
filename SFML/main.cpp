#include <iostream>
#include <SFML/Graphics.hpp>

constexpr float WIDTH = 800;
constexpr float HEIGHT = 600;

int main(){
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "game");
	sf::CircleShape shape(20.0f);
	shape.setFillColor(sf::Color::Magenta);
	shape.setPosition(100.0f, 100.0f);

	sf::RectangleShape rectangle (sf::Vector2f(100,40));
	rectangle.setFillColor(sf::Color::Magenta);
	rectangle.setOrigin(sf::Vector2f(50, 20)); // change the pivot    half of the the size
	rectangle.setPosition(sf::Vector2f(400, 400));
	rectangle.setRotation(90);
	
	//game loop
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) { // iterate over the window's queue   [closed  mouse_pressed  ]
										 // on each iterating assign the event to sf::event object
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		// clearing without displaying throws an exception
		window.clear(sf::Color::Black); // clear bellon al asoad     it's on the back buffer
		
		window.draw(shape);
		window.draw(rectangle);

		window.display(); // copies the data from the back buffer to the screen
	}
}