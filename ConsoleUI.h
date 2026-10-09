#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "World.h"

class ConsoleUI {
public:
    void renderWorld(const World& world) const;
    void renderStats(const World& world) const;
    void runMenu(World& world);

private:
    void menuConfigureDimensions(World& world);
    void menuConfigureRules(World& world);
    void menuSeed(World& world);
    void menuSimulate(World& world);
};

#endif