#include "World.h"
#include <cstdlib>
#include <algorithm>

World::World(int r, int c) : rows(0), cols(0), generation(0), grid(nullptr) {
    allocateGrid(r, c);
}

World::~World() {
    deallocateGrid();
}

void World::allocateGrid(int r, int c) {
    if (r < 5) r = 5;
    if (r > 50) r = 50;
    if (c < 5) c = 5;
    if (c > 50) c = 50;

    rows = r;
    cols = c;
    grid = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        grid[i] = new int[cols]();
    }
}

void World::deallocateGrid() {
    if (grid != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] grid[i];
        }
        delete[] grid;
        grid = nullptr;
    }
}

World::World(const World& other) : rows(0), cols(0), generation(0), grid(nullptr) {
    allocateGrid(other.rows, other.cols);
    generation = other.generation;
    config = other.config;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = other.grid[i][j];
        }
    }
}

World& World::operator=(const World& other) {
    if (this != &other) {
        deallocateGrid();
        allocateGrid(other.rows, other.cols);
        generation = other.generation;
        config = other.config;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                grid[i][j] = other.grid[i][j];
            }
        }
    }
    return *this;
}

void World::resize(int r, int c) {
    deallocateGrid();
    allocateGrid(r, c);
    generation = 0;
}

int World::getCell(int r, int c) const {
    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        return grid[r][c];
    }
    return 0;
}

void World::setCell(int r, int c, int speciesId) {
    if (r >= 0 && r < rows && c >= 0 && c < cols && speciesId >= 0 && speciesId <= 3) {
        grid[r][c] = speciesId;
    }
}

void World::clearGrid() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = 0;
        }
    }
    generation = 0;
}

void World::seedManual(int r, int c, int speciesId) {
    setCell(r, c, speciesId);
}

void World::seedRandom(double density) {
    clearGrid();
    if (density < 0.0) density = 0.0;
    if (density > 1.0) density = 1.0;

    int totalCells = rows * cols;
    int targetCells = static_cast<int>(totalCells * density);

    int placed = 0;
    while (placed < targetCells) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (grid[r][c] == 0) {
            int speciesId = (rand() % 3) + 1;
            grid[r][c] = speciesId;
            placed++;
        }
    }
}

void World::seedPattern(int startR, int startC, int patternType) {
    if (patternType == 1) {
        int offsets[5][2] = { {0, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2} };
        for (int k = 0; k < 5; ++k) {
            int r = (startR + offsets[k][0]) % rows;
            int c = (startC + offsets[k][1]) % cols;
            grid[r][c] = 1;
        }
    }
    else if (patternType == 2) {
        grid[startR % rows][startC % cols] = 1;
        grid[startR % rows][(startC + 1) % cols] = 2;
        grid[startR % rows][(startC + 2) % cols] = 3;
    }
}

void World::countNeighbors(int r, int c, int& count1, int& count2, int& count3) const {
    count1 = count2 = count3 = 0;

    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;

            int nr = (r + dr + rows) % rows;
            int nc = (c + dc + cols) % cols;

            int speciesId = grid[nr][nc];
            if (speciesId == 1) count1++;
            else if (speciesId == 2) count2++;
            else if (speciesId == 3) count3++;
        }
    }
}

void World::nextGeneration() {
    int** nextGrid = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        nextGrid[i] = new int[cols]();
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int c1 = 0, c2 = 0, c3 = 0;
            countNeighbors(i, j, c1, c2, c3);
            int totalNeighbors = c1 + c2 + c3;
            int currentSpecies = grid[i][j];

            if (currentSpecies > 0) {
                if (config.isSurvivalNumber(currentSpecies, totalNeighbors)) {
                    nextGrid[i][j] = currentSpecies;
                }
                else {
                    nextGrid[i][j] = 0;
                }
            }
            else {
                if (config.isBirthNumber(totalNeighbors)) {
                    nextGrid[i][j] = config.resolveTie(c1, c2, c3);
                }
                else {
                    nextGrid[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = nextGrid[i][j];
        }
        delete[] nextGrid[i];
    }
    delete[] nextGrid;

    generation++;
}

void World::getStats(int& pop1, int& pop2, int& pop3, int& totalAlive) const {
    pop1 = pop2 = pop3 = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) pop1++;
            else if (grid[i][j] == 2) pop2++;
            else if (grid[i][j] == 3) pop3++;
        }
    }
    totalAlive = pop1 + pop2 + pop3;
}