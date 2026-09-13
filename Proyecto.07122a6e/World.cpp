#include "World.h"

World::World(int r, int c) : rows(r), cols(c), generation(0) {
    allocateMemory();
}

World::~World() {
    freeMemory();
}

void World::allocateMemory() {
    grid = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        grid[i] = new int[cols]();
    }
}

void World::freeMemory() {
    for (int i = 0; i < rows; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

int World::getRows() const { return rows; }
int World::getCols() const { return cols; }
int World::getGeneration() const { return generation; }
const SpeciesConfig& World::getConfig() const { return config; }