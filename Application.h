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

    Application(): _window(sizeX, sizeY), _fractal() {
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
                    incrementZoomFactor(event.mouseWheelScroll.delta > 0);
                    std::cout << "Zoom : " << _zoomFactor << std::endl;
                    auto mousePosition = sf::Mouse::getPosition(_window.getWindow());
                    _fractal.setNewRenderArea(mousePosition.x, mousePosition.y, _zoomFactor);
                    _fractal.interpolatePoints();
                }
            }
            draw(100);
        }
    }

private:

    void incrementZoomFactor(bool isAZoom) {
        if(isAZoom) {
            _zoomFactor = _zoomFactor + 1;
        }
        else {
            _zoomFactor = _zoomFactor - 1;
        }
    }

    Window _window;
    Fractal<sizeX, sizeY> _fractal;
    int _zoomFactor = 1;

};


#endif //FRACTALRENDERER_APPLICATION_H
