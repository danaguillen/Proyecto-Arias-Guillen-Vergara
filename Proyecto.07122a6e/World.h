#ifndef WORLD_H
#define WORLD_H

#include "SpeciesConfig.h"

class World {
private:
    int rows;
    int cols;
    int generation;
    int** grid;
    SpeciesConfig config;

    void allocateMemory();
    void freeMemory();

public:
    World(int r, int c);
    ~World();

    int getCell(int r, int c) const;
    int getRows() const;
    int getCols() const;
    int getGeneration() const;
    const SpeciesConfig& getConfig() const;
    void setVersion(int version);
};

#endif