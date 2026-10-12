#include "Laboratory.h"

Laboratory::Laboratory() : activeWorldIndex(0) {
    addWorld("Mundo Principal", 20, 20);
}

Laboratory::~Laboratory() {
    for (int i = 0; i < worlds.getSize(); ++i) {
        delete worlds.get(i);
    }
}

void Laboratory::addWorld(std::string name, int r, int c) {
    worlds.push_back(new World(r, c));
    activeWorldIndex = worlds.getSize() - 1;
}

void Laboratory::duplicateActiveWorld() {
    World* current = getActiveWorld();
    if (current) {
        World* cloned = new World(*current);
        worlds.push_back(cloned);
        activeWorldIndex = worlds.getSize() - 1;
    }
}

void Laboratory::removeActiveWorld() {
    if (worlds.getSize() > 1) {
        delete getActiveWorld();
        worlds.removeAt(activeWorldIndex);
        if (activeWorldIndex >= worlds.getSize()) {
            activeWorldIndex = worlds.getSize() - 1;
        }
    }
}

World* Laboratory::getActiveWorld() const {
    return worlds.get(activeWorldIndex);
}

void Laboratory::selectNextWorld() {
    if (worlds.getSize() > 0) {
        activeWorldIndex = (activeWorldIndex + 1) % worlds.getSize();
    }
}