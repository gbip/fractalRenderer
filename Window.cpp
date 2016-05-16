//
// Created by paul on 16/05/16.
//

#include "Window.h"

Window::Window(int width, int height): _width(width),
_height(height),
_window(sf::VideoMode(width, height), "Fractal Renderer") { }