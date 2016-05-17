//
// Created by paul on 16/05/16.
//

#ifndef FRACTALRENDERER_WINDO_H
#define FRACTALRENDERER_WINDO_H

#include <SFML/Graphics/RenderWindow.hpp>

class Window {
public:
  Window(int width, int height);

  sf::RenderWindow &getWindow() { return _window; }

private:
  int _width;
  int _height;
  sf::RenderWindow _window;
};

#endif // FRACTALRENDERER_WINDO_H
