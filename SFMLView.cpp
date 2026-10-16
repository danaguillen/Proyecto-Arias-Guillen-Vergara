#include "SFMLView.h"

SFMLView::SFMLView(sf::RenderWindow& win) : window(win), cellSize(25.0f) {
    font.loadFromFile("arial.ttf");
}

void SFMLView::render(const World& world, int activeSpecies) {
    window.clear(sf::Color(30, 30, 30));

    for (int r = 0; r < world.getRows(); ++r) {
        for (int c = 0; c < world.getCols(); ++c) {
            sf::RectangleShape shape(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
            shape.setPosition(c * cellSize + 10.0f, r * cellSize + 10.0f);

            int species = world.getCell(r, c);
            if (species == 1) {
                shape.setFillColor(sf::Color::Green);
            }
            else if (species == 2) {
                shape.setFillColor(sf::Color::Cyan);
            }
            else if (species == 3) {
                shape.setFillColor(sf::Color::Magenta);
            }
            else {
                shape.setFillColor(sf::Color(50, 50, 50));
            }
            window.draw(shape);
        }
    }

    int p1 = 0, p2 = 0, p3 = 0, total = 0;
    world.getStats(p1, p2, p3, total);

    sf::Text hud;
    hud.setFont(font);
    hud.setCharacterSize(15);
    hud.setFillColor(sf::Color::White);
    hud.setPosition(540.0f, 10.0f);

    std::string info = "=== LABORATORIO ===\n";
    info += "Generacion: " + std::to_string(world.getGeneration()) + "\n";
    info += "Activa: " + world.getConfig().getName(activeSpecies) + "\n\n";
    info += "=== POBLACION ===\n";
    info += "Total Vivas: " + std::to_string(total) + "\n";
    info += "E1 Alfa (Verde): " + std::to_string(p1) + "\n";
    info += "E2 Beta (Cian): " + std::to_string(p2) + "\n";
    info += "E3 Gamma (Mag): " + std::to_string(p3) + "\n\n";
    info += "=== CONTROLES ===\n";
    info += "[Click Izq] : Sembrar\n";
    info += "[Click Der] : Borrar\n";
    info += "[Espacio]   : Avanzar Gen\n";
    info += "[1 - 3]     : Seleccionar Especie\n";
    info += "[N]         : Siguiente Mundo\n";
    info += "[D]         : Duplicar Mundo\n";

    hud.setString(info);
    window.draw(hud);

    window.display();
}