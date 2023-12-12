#pragma once
#include <set>
#include <string>

#include "../animales/animal.h"

class Escena {
    private:
        std::set<Animal> animales;

    public:
        Escena(std::set<Animal> animales);
        std::set<Animal> getAnimals();
        int getAnimalGreatness();
        std::string getAnimalsNames();

};