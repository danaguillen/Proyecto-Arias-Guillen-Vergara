#ifndef SPECIES_CONFIG_H
#define SPECIES_CONFIG_H

<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> f4a6bef5ec9601c048b24085aa0cc3bcdd1a77c8
#include "Header.h"

class SpeciesConfig {
private:
    WorldConfig currentConfig;
<<<<<<< HEAD
=======
>>>>>>> d1372cca01c2d05d125becc2273fb0fc53873b83
#include <string>
#include <vector>

struct SpeciesInfo {
    int id;
    std::string name;
    char symbol;
    std::vector<int> survivalRules;
};

class SpeciesConfig {
private:
    std::vector<int> birthRules;
    SpeciesInfo species[3];
<<<<<<< HEAD
=======
>>>>>>> abb79ffdc7db4d5e05a0649ed0a83f9c514b9f5a
>>>>>>> d1372cca01c2d05d125becc2273fb0fc53873b83
=======
>>>>>>> f4a6bef5ec9601c048b24085aa0cc3bcdd1a77c8

public:
    SpeciesConfig();

<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> f4a6bef5ec9601c048b24085aa0cc3bcdd1a77c8
    void loadToroide();
    void loadCruz();

    const WorldConfig& getConfig() const;
    bool isBirthValue(int neighborCount) const;
    bool isSurvivalValue(int speciesId, int neighborCount) const;
    int resolveTie(int speciesCounts[]) const;
<<<<<<< HEAD
=======
>>>>>>> d1372cca01c2d05d125becc2273fb0fc53873b83
    void setBirthRules(const std::vector<int>& n);
    const std::vector<int>& getBirthRules() const;

    void setSurvivalRules(int speciesId, const std::vector<int>& s);
    const std::vector<int>& getSurvivalRules(int speciesId) const;

    bool isBirthNumber(int neighbors) const;
    bool isSurvivalNumber(int speciesId, int neighbors) const;

    std::string getName(int speciesId) const;
    char getSymbol(int speciesId) const;

    int resolveTie(int count1, int count2, int count3) const;
<<<<<<< HEAD
=======
>>>>>>> abb79ffdc7db4d5e05a0649ed0a83f9c514b9f5a
>>>>>>> d1372cca01c2d05d125becc2273fb0fc53873b83
=======
>>>>>>> f4a6bef5ec9601c048b24085aa0cc3bcdd1a77c8
};

#endif