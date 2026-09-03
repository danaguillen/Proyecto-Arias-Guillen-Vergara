#ifndef HEADER_H
#define HEADER_H

#include <iostream>

const int MAX_SPECIES = 4;
const int MAX_RULE_VALUES = 9;

struct Species {
    char symbol;
    int id;
    int survivalRules[MAX_RULE_VALUES];
    int survivalCount;
};

struct WorldConfig {
    int birthRules[MAX_RULE_VALUES];
    int birthCount;
    int numSpecies;
    bool tieBreakerLowestIndex;
    Species speciesList[MAX_SPECIES];
};

#endif