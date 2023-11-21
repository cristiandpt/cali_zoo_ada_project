#pragma once
#include <set>

#include "../animales/enumAnimal.h"
#include "../animales/animal.h"

class Escena {
    private:
        std::set<Animal> animales;
        int grandeza;
    public:
        Escena(std::initializer_list<Animal> animales);
        std::set<Animal> getAnimals();
        int getAnimalGreatness();

};