#ifndef LABORATORY_H
#define LABORATORY_H

#include "LinkedList.h"
#include "World.h"

class Laboratory {
private:
    LinkedList<World*> worlds;
    int activeWorldIndex;

public:
    Laboratory();
    ~Laboratory();

    void addWorld(std::string name, int r, int c);
    void duplicateActiveWorld();
    void removeActiveWorld();

    World* getActiveWorld() const;
    void selectNextWorld();
    int getWorldCount() const { return worlds.getSize(); }
};

#endif