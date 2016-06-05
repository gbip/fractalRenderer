//
// Created by paul on 22/05/16.
//

#ifndef FRACTALRENDERER_APPLICATION_H
#define FRACTALRENDERER_APPLICATION_H


#include "Fractal.h"
#include <zconf.h>
#include <SFML/Window/Event.hpp>

template <int sizeX, int sizeY>
class Application {

public:

    Application(): _window(sizeX, sizeY), _fractal(), _redraw(true) {
        _fractal.mapWindowTo({-2,2}, {2,-2});
        _fractal.interpolatePoints();
    };

    void draw(int step){    sf::Sprite renderSprite;
        sf::Texture tex = _fractal.drawFractal(step);
        renderSprite.setColor(sf::Color::Blue);
        renderSprite.setTexture(tex, true);
        _window.getWindow().draw(renderSprite);
        _window.getWindow().display();
    }

    void loop() {
        while(_window.getWindow().isOpen()) {
            sf::Event event;
            while(_window.getWindow().pollEvent(event)) {
                if(event.type == sf::Event::Closed) {
                    _window.getWindow().close();
                }
                if (event.type == sf::Event::MouseWheelScrolled) {
                    std::cout << "Mouse zoomed" << event.mouseWheelScroll.delta << std::endl;
                    std::cout << "Zoom : " << _zoomFactor << std::endl;
                    auto mousePosition = sf::Mouse::getPosition(_window.getWindow());

                    _fractal.setNewRenderArea(mousePosition.x, mousePosition.y, event.mouseWheel.delta>0);
                    _fractal.interpolatePoints();
                    _redraw = true;
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    auto mousePosition = sf::Mouse::getPosition(_window.getWindow());
                    std::cout << "Zoom : " << _zoomFactor << std::endl;
                    _fractal.setNewRenderArea(mousePosition.x, mousePosition.y, true);
                    _fractal.interpolatePoints();
                    _redraw = true;
                }
            }
            if (_redraw) {
                draw(100);
                _redraw = false;
            }
        }
    }

private:

    int getZoomFactor(bool isAZoom) {
        if(isAZoom) {
            return 2;
        }
        else {
            return 0.5;
        }
    }

    Window _window;
    Fractal<sizeX, sizeY> _fractal;
    int _zoomFactor = 0;
    bool _redraw;
};


#endif //FRACTALRENDERER_APPLICATION_H
