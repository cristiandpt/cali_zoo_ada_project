#pragma once
#include <set>
#include <string>
#include "iostream"

#include "../animales/animal.h"

class Escena {
    
    private:
        std::set<Animal> animales;

    public:
        Escena(std::set<Animal> animales);
        std::set<Animal> getAnimals();
        int getAnimalGreatness() const;
        std::string getAnimalsNames() const;
        bool operator==(const Escena& other) const;
        bool operator<(const Escena& other) const;
        bool operator<=(const Escena& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Escena& escene);
};