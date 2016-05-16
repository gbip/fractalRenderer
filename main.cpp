#include <iostream>
#include <gtk-3.0/gtk/gtk.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Fractal.h"

using namespace std;


void draw(GtkWidget *widget, cairo_t *cr, gpointer data){
    std::cout << "Draw" << std::endl;
};

int main(int argc, char **argv) {
    const auto width = 800;
    const auto height = 600;

    auto fractal = Fractal<width, height>();

    fractal.computeFractal();

    std::cout << "OK" << std::endl;

    std::unique_ptr<Window> window = std::make_unique<Window>(width, height);

    while (window->getWindow().isOpen()) {
        sf::Event event;
        while (window->getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->getWindow().close();
            }
        }

        window->getWindow().clear(sf::Color::Black);
        window->getWindow().display();


    }

}