#include <iostream>
#include <SFML/Graphics.hpp>

int main(){
	sf::RenderWindow window(sf::VideoMode(800, 600), "game");

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
		// draw
		window.display(); // copies the data from the back buffer to the screen
	}
}