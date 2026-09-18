#include "World.h"
#include "ConsoleUI.h"
#include <iostream>

int main() {
    World myWorld(10, 10);
    ConsoleUI ui;

    std::cout << "Mundo inicializado correctamente.\n";
    ui.renderWorld(myWorld);

    return 0;
}