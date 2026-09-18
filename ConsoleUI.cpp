#include "ConsoleUI.h"
#include <iostream>

void ConsoleUI::renderWorld(const World& world) const {
    const WorldConfig& sysConfig = world.getConfig().getConfig();
    std::cout << "\nMAPA DEL MUNDO (Gen " << world.getGeneration() << ")\n";
    for (int r = 0; r < world.getRows(); ++r) {
        for (int c = 0; c < world.getCols(); ++c) {
            int val = world.getCell(r, c);
            if (val == 0) {
                std::cout << ". ";
            }
            else {
                std::cout << sysConfig.speciesList[val - 1].symbol << " ";
            }
        }
        std::cout << "\n";
    }
}