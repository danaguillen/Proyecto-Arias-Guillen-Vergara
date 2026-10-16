#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Laboratory.h"
#include "SFMLView.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Simulador de Mundos - Laboratorio SFML");
    window.setFramerateLimit(60);

    Laboratory lab;
    SFMLView view(window);
    int activeSpecies = 1;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                int col = (event.mouseButton.x - 10) / 25;
                int row = (event.mouseButton.y - 10) / 25;

                if (event.mouseButton.button == sf::Mouse::Left) {
                    lab.getActiveWorld()->setCell(row, col, activeSpecies);
                }
                else if (event.mouseButton.button == sf::Mouse::Right) {
                    lab.getActiveWorld()->setCell(row, col, 0);
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    lab.getActiveWorld()->nextGeneration();
                }
                else if (event.key.code == sf::Keyboard::N) {
                    lab.selectNextWorld();
                }
                else if (event.key.code == sf::Keyboard::D) {
                    lab.duplicateActiveWorld();
                }
                else if (event.key.code == sf::Keyboard::Num1) {
                    activeSpecies = 1;
                }
                else if (event.key.code == sf::Keyboard::Num2) {
                    activeSpecies = 2;
                }
                else if (event.key.code == sf::Keyboard::Num3) {
                    activeSpecies = 3;
                }
            }
        }

        view.render(*lab.getActiveWorld(), activeSpecies);
    }

    return 0;
}