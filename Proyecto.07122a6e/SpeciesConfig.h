#ifndef SPECIES_CONFIG_H
#define SPECIES_CONFIG_H

#include "Header.h"

class SpeciesConfig {
private:
    WorldConfig currentConfig;

public:
    SpeciesConfig();

    void loadToroide();
    void loadCruz();

    const WorldConfig& getConfig() const;
    bool isBirthValue(int neighborCount) const;
    bool isSurvivalValue(int speciesId, int neighborCount) const;
    int resolveTie(int speciesCounts[]) const;
};

#endif