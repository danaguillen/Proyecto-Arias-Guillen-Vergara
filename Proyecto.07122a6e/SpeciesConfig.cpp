#include "SpeciesConfig.h"

SpeciesConfig::SpeciesConfig() {
    loadToroide();
}

void SpeciesConfig::loadToroide() {
    currentConfig.birthRules[0] = 3;
    currentConfig.birthCount = 1;
    currentConfig.numSpecies = 3;
    currentConfig.tieBreakerLowestIndex = false;

    currentConfig.speciesList[0] = { 'A', 1, {2, 3}, 2 };
    currentConfig.speciesList[1] = { 'B', 2, {3, 4}, 2 };
    currentConfig.speciesList[2] = { 'C', 3, {1, 2}, 2 };
}

void SpeciesConfig::loadCruz() {
    currentConfig.birthRules[0] = 2;
    currentConfig.birthRules[1] = 3;
    currentConfig.birthCount = 2;
    currentConfig.numSpecies = 4;
    currentConfig.tieBreakerLowestIndex = true;

    currentConfig.speciesList[0] = { '1', 1, {1, 2}, 2 };
    currentConfig.speciesList[1] = { '2', 2, {2, 3}, 2 };
    currentConfig.speciesList[2] = { '3', 3, {2}, 1 };
    currentConfig.speciesList[3] = { '4', 4, {1, 2, 3}, 3 };
}

const WorldConfig& SpeciesConfig::getConfig() const {
    return currentConfig;
}

bool SpeciesConfig::isBirthValue(int neighborCount) const {
    for (int i = 0; i < currentConfig.birthCount; ++i) {
        if (currentConfig.birthRules[i] == neighborCount) return true;
    }
    return false;
}

bool SpeciesConfig::isSurvivalValue(int speciesId, int neighborCount) const {
    for (int i = 0; i < currentConfig.numSpecies; ++i) {
        if (currentConfig.speciesList[i].id == speciesId) {
            for (int j = 0; j < currentConfig.speciesList[i].survivalCount; ++j) {
                if (currentConfig.speciesList[i].survivalRules[j] == neighborCount) {
                    return true;
                }
            }
        }
    }
    return false;
}

int SpeciesConfig::resolveTie(int speciesCounts[]) const {
    int maxCount = -1;
    for (int i = 0; i < currentConfig.numSpecies; ++i) {
        if (speciesCounts[i] > maxCount) {
            maxCount = speciesCounts[i];
        }
    }

    if (currentConfig.tieBreakerLowestIndex) {
        for (int i = 0; i < currentConfig.numSpecies; ++i) {
            if (speciesCounts[i] == maxCount) return i + 1;
        }
    }
    else {
        for (int i = currentConfig.numSpecies - 1; i >= 0; --i) {
            if (speciesCounts[i] == maxCount) return i + 1;
        }
    }
    return 0;
}