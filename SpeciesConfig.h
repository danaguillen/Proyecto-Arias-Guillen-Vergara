#ifndef SPECIES_CONFIG_H
#define SPECIES_CONFIG_H

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

public:
    SpeciesConfig();

    void setBirthRules(const std::vector<int>& n);
    const std::vector<int>& getBirthRules() const;

    void setSurvivalRules(int speciesId, const std::vector<int>& s);
    const std::vector<int>& getSurvivalRules(int speciesId) const;

    bool isBirthNumber(int neighbors) const;
    bool isSurvivalNumber(int speciesId, int neighbors) const;

    std::string getName(int speciesId) const;
    char getSymbol(int speciesId) const;

    int resolveTie(int count1, int count2, int count3) const;
};

#endif