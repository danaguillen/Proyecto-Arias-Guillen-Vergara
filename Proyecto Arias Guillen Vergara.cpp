#include "World.h"
#include "ConsoleUI.h"
<<<<<<< HEAD
=======
<<<<<<< HEAD
#include <iostream>

int main() {
    World myWorld(10, 10);
    ConsoleUI ui;

    std::cout << "Mundo inicializado correctamente.\n";
    ui.renderWorld(myWorld);
=======
>>>>>>> d1372cca01c2d05d125becc2273fb0fc53873b83
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    World myWorld(10, 10);
    ConsoleUI ui;

    ui.runMenu(myWorld);
<<<<<<< HEAD
=======
>>>>>>> abb79ffdc7db4d5e05a0649ed0a83f9c514b9f5a
>>>>>>> d1372cca01c2d05d125becc2273fb0fc53873b83

    return 0;
}