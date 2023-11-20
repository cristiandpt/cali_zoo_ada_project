#pragma once
#include "enumAnimal.h"
class Animal {
    private:
        AnimalNombre nombre_animal;
        int grandeza;
    public:
        Animal(AnimalNombre nombre_animal, int grandeza);
        AnimalNombre getNombreAnimal();
        int getGrandeza();

};