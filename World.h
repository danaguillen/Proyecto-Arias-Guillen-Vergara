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

<<<<<<< HEAD
=======
<<<<<<< HEAD
    void allocateMemory();
    void freeMemory();

public:
    World(int r, int c);
    ~World();

    int getCell(int r, int c) const;
    void setCell(int r, int c, int speciesId);
    int getRows() const;
    int getCols() const;
    int getGeneration() const;
    const SpeciesConfig& getConfig() const;
    void setVersion(int version);
=======
>>>>>>> d1372cca01c2d05d125becc2273fb0fc53873b83
    void allocateGrid(int r, int c);
    void deallocateGrid();

public:
    World(int r = 10, int c = 10);
    ~World();

    World(const World& other);
    World& operator=(const World& other);

    void resize(int r, int c);

    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getGeneration() const { return generation; }
    int getCell(int r, int c) const;

    void setCell(int r, int c, int speciesId);
    void clearGrid();

    void seedManual(int r, int c, int speciesId);
    void seedRandom(double density);
    void seedPattern(int startR, int startC, int patternType);

    void countNeighbors(int r, int c, int& count1, int& count2, int& count3) const;
    void nextGeneration();

    void getStats(int& pop1, int& pop2, int& pop3, int& totalAlive) const;

    SpeciesConfig& getConfig() { return config; }
    const SpeciesConfig& getConfig() const { return config; }
<<<<<<< HEAD
=======
>>>>>>> abb79ffdc7db4d5e05a0649ed0a83f9c514b9f5a
>>>>>>> d1372cca01c2d05d125becc2273fb0fc53873b83
};

#endif