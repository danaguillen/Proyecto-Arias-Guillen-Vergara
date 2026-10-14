#ifndef SFML_VIEW_H
#define SFML_VIEW_H

#include <SFML/Graphics.hpp>
#include "View.h"

class SFMLView : public View {
private:
    sf::RenderWindow& window;
    sf::Font font;
    float cellSize;

public:
    SFMLView(sf::RenderWindow& win);
    void render(const World& world, int activeSpecies) override;
};

#endif