//
// Created by paul on 16/05/16.
//

#ifndef FRACTALRENDERER_WINDO_H
#define FRACTALRENDERER_WINDO_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>


class Window {
public:
	Window(int width, int height);

	sf::RenderWindow& getWindow() {
		return _window;
	}

	//A function that will map all the normalized input data (between 0 and 1) to a gradient
	sf::Color gradientFunction(const double &data) {
		return sf::Color::Red;
	}
	const int getWidth() { return _width;};
	const int getHeight() { return _height;};

private:
	int _width;
	int _height;
	sf::RenderWindow _window;
};

#endif // FRACTALRENDERER_WINDO_H
