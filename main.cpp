#include "Fractal.h"
#include <SFML/Graphics.hpp>
#include <gtk-3.0/gtk/gtk.h>
#include <iostream>

using namespace std;

void draw(GtkWidget* widget, cairo_t* cr, gpointer data) {
	std::cout << "Draw" << std::endl;
};

int main(int argc, char**argv) {
	const int width = 800;
	const int height = 800;



	Window window(width, height);
	window.getWindow().clear(sf::Color::Green);
	window.getWindow().display();

	Fractal<width,height> fractal(60);


	fractal.rescale({-2,2}, {2,-2});
	sf::Sprite renderSprite;
	sf::Texture tex = fractal.drawFractal();
	renderSprite.setTexture(tex, true);
	window.getWindow().draw(renderSprite);
	window.getWindow().display();

/*
	while(window.getWindow().isOpen()) {
		sf::Event event;
		while(window.getWindow().pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.getWindow().close();
			}
		}
		sleep(1);
		//fractal.drawFractal(window);
		window.getWindow().draw(test);
		window.getWindow().display();
	}
*/
	while(true) {
		sleep(1);
	}

}