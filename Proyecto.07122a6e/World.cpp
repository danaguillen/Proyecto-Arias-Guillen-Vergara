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

void World::setCell(int r, int c, int speciesId) {
    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        grid[r][c] = speciesId;
    }
}

int World::getCell(int r, int c) const {
    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        return grid[r][c];
    }
    return 0;
}

void World::setVersion(int version) {
    if (version == 1) config.loadToroide();
    else if (version == 2) config.loadCruz();
}