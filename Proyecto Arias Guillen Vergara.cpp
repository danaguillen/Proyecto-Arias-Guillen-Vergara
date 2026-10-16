#include "World.h"
#include "ConsoleUI.h"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    World myWorld(10, 10);
    ConsoleUI ui;

    ui.runMenu(myWorld);

    return 0;
}