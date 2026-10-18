#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "World.h"

class ConsoleUI {
public:
    void renderWorld(const World& world) const;
    void renderStats(const World& world) const;
    void runMenu(World& world);
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> d1372cca01c2d05d125becc2273fb0fc53873b83

private:
    void menuConfigureDimensions(World& world);
    void menuConfigureRules(World& world);
    void menuSeed(World& world);
    void menuSimulate(World& world);
<<<<<<< HEAD
=======
>>>>>>> abb79ffdc7db4d5e05a0649ed0a83f9c514b9f5a
>>>>>>> d1372cca01c2d05d125becc2273fb0fc53873b83
=======
>>>>>>> f4a6bef5ec9601c048b24085aa0cc3bcdd1a77c8
};

#endif