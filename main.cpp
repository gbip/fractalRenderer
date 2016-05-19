#include "Fractal.h"
#include <SFML/Graphics.hpp>
#include <gtk-3.0/gtk/gtk.h>
#include <iostream>

using namespace std;

void draw(GtkWidget* widget, cairo_t* cr, gpointer data) {
	std::cout << "Draw" << std::endl;
};

int main(int argc, char**argv) {
	std::cout << "111" << std::endl;
	const int width = 800;
	const int height = 600;
return 0;
	auto fractal = Fractal<800,600>(50);

	std::cout << "OK" << std::endl;

	Window window(width, height);

	//fractal.drawFractal(window);


	while(window.getWindow().isOpen()) {
		sf::Event event;
		while(window.getWindow().pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.getWindow().close();
			}
		}

		window.getWindow().clear(sf::Color::Black);
		window.getWindow().display();
	}
}