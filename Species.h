#ifndef SPECIES_H
#define SPECIES_H

#include <string>

class Species {
protected:
    int id;
    std::string name;
    char symbol;

public:
    Species(int id, std::string name, char symbol)
        : id(id), name(name), symbol(symbol) {
    }

    virtual ~Species() {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    char getSymbol() const { return symbol; }

    virtual bool shouldSurvive(int liveNeighbors) const = 0;
    virtual bool shouldBirth(int liveNeighbors) const = 0;
};

class SpeciesAlpha : public Species {
public:
    SpeciesAlpha() : Species(1, "Alpha", 'A') {}
    bool shouldSurvive(int n) const override { return (n == 2 || n == 3); }
    bool shouldBirth(int n) const override { return (n == 3); }
};

class SpeciesBeta : public Species {
public:
    SpeciesBeta() : Species(2, "Beta", 'B') {}
    bool shouldSurvive(int n) const override { return (n == 2 || n == 3); }
    bool shouldBirth(int n) const override { return (n == 3 || n == 6); }
};

class SpeciesGamma : public Species {
public:
    SpeciesGamma() : Species(3, "Gamma", 'G') {}
    bool shouldSurvive(int) const override { return false; }
    bool shouldBirth(int n) const override { return (n == 2); }
};

#endif