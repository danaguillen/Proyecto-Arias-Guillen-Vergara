#include "ConsoleUI.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

void ConsoleUI::renderWorld(const World& world) const {
    std::cout << "\n========================================\n";
    std::cout << "         MAPA DEL MUNDO (Gen: " << world.getGeneration() << ")\n";
    std::cout << "========================================\n  ";

    for (int j = 0; j < world.getCols(); ++j) {
        std::cout << (j % 10) << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < world.getRows(); ++i) {
        std::cout << std::setw(2) << i << " ";
        for (int j = 0; j < world.getCols(); ++j) {
            int species = world.getCell(i, j);
            std::cout << world.getConfig().getSymbol(species) << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nLeyenda:\n";
    std::cout << "  . : Vacia\n";
    std::cout << "  A : " << world.getConfig().getName(1) << "\n";
    std::cout << "  B : " << world.getConfig().getName(2) << "\n";
    std::cout << "  C : " << world.getConfig().getName(3) << "\n";
    std::cout << "========================================\n";
}

void ConsoleUI::renderStats(const World& world) const {
    int pop1 = 0, pop2 = 0, pop3 = 0, totalAlive = 0;
    world.getStats(pop1, pop2, pop3, totalAlive);

    int totalCells = world.getRows() * world.getCols();
    double density = (static_cast<double>(totalAlive) / totalCells) * 100.0;

    std::cout << "\n========================================\n";
    std::cout << "        ESTADISTICAS DE POBLACION\n";
    std::cout << "========================================\n";
    std::cout << " Generacion Actual : " << world.getGeneration() << "\n";
    std::cout << " Dimensiones       : " << world.getRows() << " x " << world.getCols() << "\n";
    std::cout << " Total Celdas Vivas: " << totalAlive << " / " << totalCells
        << " (" << std::fixed << std::setprecision(1) << density << "%)\n";
    std::cout << " --------------------------------------\n";
    std::cout << " " << world.getConfig().getSymbol(1) << " - " << world.getConfig().getName(1) << ": " << pop1 << "\n";
    std::cout << " " << world.getConfig().getSymbol(2) << " - " << world.getConfig().getName(2) << ": " << pop2 << "\n";
    std::cout << " " << world.getConfig().getSymbol(3) << " - " << world.getConfig().getName(3) << ": " << pop3 << "\n";
    std::cout << "========================================\n";
}

void ConsoleUI::runMenu(World& world) {
    int option = 0;
    while (option != 6) {
        std::cout << "\n=== SIMULADOR DE MUNDOS - MENU PRINCIPAL ===\n";
        std::cout << "1. Ver mapa y estadisticas\n";
        std::cout << "2. Configurar dimensiones del mapa\n";
        std::cout << "3. Configurar reglas (Nacimiento N / Supervivencia S)\n";
        std::cout << "4. Sembrar celdas (Manual, Aleatoria, Patron)\n";
        std::cout << "5. Avanzar simulacion\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opción (1-6): ";
        std::cin >> option;

        switch (option) {
        case 1:
            renderWorld(world);
            renderStats(world);
            break;
        case 2:
            menuConfigureDimensions(world);
            break;
        case 3:
            menuConfigureRules(world);
            break;
        case 4:
            menuSeed(world);
            break;
        case 5:
            menuSimulate(world);
            break;
        case 6:
            std::cout << "\n¡Gracias por usar el Simulador de Mundos!\n";
            break;
        default:
            std::cout << "\nOpción invalida. Intente de nuevo.\n";
            break;
        }
    }
}

void ConsoleUI::menuConfigureDimensions(World& world) {
    int r, c;
    std::cout << "\n--- CONFIGURAR DIMENSIONES (Min 5, Max 50) ---\n";
    std::cout << "Ingrese filas: ";
    std::cin >> r;
    std::cout << "Ingrese columnas: ";
    std::cin >> c;

    world.resize(r, c);
    std::cout << "Mapa redimensionado a " << world.getRows() << " x " << world.getCols() << ".\n";
}

void ConsoleUI::menuConfigureRules(World& world) {
    std::cout << "\n--- CONFIGURAR REGLAS (Toroide / Personalizado) ---\n";
    std::cout << "1. Cargar configuracion Toroide por defecto\n";
    std::cout << "2. Personalizar valores de Nacimiento (N) y Supervivencia (S)\n";
    std::cout << "Seleccione una opción: ";
    int opt;
    std::cin >> opt;

    if (opt == 1) {
        world.getConfig().setBirthRules({ 3 });
        world.getConfig().setSurvivalRules(1, { 2, 3 });
        world.getConfig().setSurvivalRules(2, { 3, 4 });
        world.getConfig().setSurvivalRules(3, { 1, 2 });
        std::cout << "Configuracion Toroide cargada con éxito.\n";
    }
    else if (opt == 2) {
        std::cin.ignore();
        std::cout << "Ingrese numeros de nacimiento N separados por espacio (ej. 3): ";
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::vector<int> birth;
        int val;
        while (ss >> val) birth.push_back(val);
        world.getConfig().setBirthRules(birth);

        for (int i = 1; i <= 3; ++i) {
            std::cout << "Ingrese numeros de supervivencia S para Especie " << i << " (" << world.getConfig().getName(i) << ") (ej. 2 3): ";
            std::getline(std::cin, line);
            std::stringstream ss2(line);
            std::vector<int> surv;
            while (ss2 >> val) surv.push_back(val);
            world.getConfig().setSurvivalRules(i, surv);
        }
        std::cout << "Reglas personalizadas aplicadas.\n";
    }
}

void ConsoleUI::menuSeed(World& world) {
    std::cout << "\n--- MENU DE SIEMBRA ---\n";
    std::cout << "1. Siembra Manual (Fila, Columna, Especie)\n";
    std::cout << "2. Siembra Aleatoria (Densidad 0.0 a 1.0)\n";
    std::cout << "3. Siembra de Patron / Figura (Glider o Trio Mixto)\n";
    std::cout << "Seleccione opcion: ";
    int opt;
    std::cin >> opt;

    if (opt == 1) {
        int r, c, species;
        std::cout << "Ingrese Fila (0 a " << world.getRows() - 1 << "): ";
        std::cin >> r;
        std::cout << "Ingrese Columna (0 a " << world.getCols() - 1 << "): ";
        std::cin >> c;
        std::cout << "Ingrese Especie (1: " << world.getConfig().getName(1)
            << ", 2: " << world.getConfig().getName(2)
            << ", 3: " << world.getConfig().getName(3) << "): ";
        std::cin >> species;
        world.seedManual(r, c, species);
        std::cout << "Celda colocada exitosamente.\n";
    }
    else if (opt == 2) {
        double d;
        std::cout << "Ingrese densidad entre 0.0 (vacio) y 1.0 (lleno): ";
        std::cin >> d;
        world.seedRandom(d);
        std::cout << "Siembra aleatoria generada.\n";
    }
    else if (opt == 3) {
        int pat, r, c;
        std::cout << "Seleccione Patron (1: Glider Planeador, 2: Trio Mixto): ";
        std::cin >> pat;
        std::cout << "Ingrese Fila inicial: ";
        std::cin >> r;
        std::cout << "Ingrese Columna inicial: ";
        std::cin >> c;
        world.seedPattern(r, c, pat);
        std::cout << "Patron colocado exitosamente.\n";
    }
}

void ConsoleUI::menuSimulate(World& world) {
    int steps;
    std::cout << "\n¿Cuantas generaciones desea avanzar? (ej. 1, 5, 10): ";
    std::cin >> steps;

    for (int i = 0; i < steps; ++i) {
        world.nextGeneration();
    }

    std::cout << "\nSimulacion avanzada " << steps << " generacion(es).\n";
    renderWorld(world);
    renderStats(world);
}