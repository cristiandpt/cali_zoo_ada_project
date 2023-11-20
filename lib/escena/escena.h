#pragma once
#include <set>

#include "enumAnimal.h"
#include "animal.h"

class Escena {
    private:
        std::set<Animal> animales;
        int grandeza;
    public:
        Escena(std::initializer_list<Animal> animales);
        std::set<Animal> getAnimals();
        int getAnimalGreatness();

};