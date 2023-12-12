#include "./escena.h"


Escena::Escena(std::set<Animal> animales)
    :animales(animales) {}


 std::set<Animal> Escena::getAnimals() 
    {
        return animales;
    }

int Escena::getAnimalGreatness() {
    int grandeza = 0;
    for (Animal animal : animales) {
        grandeza += animal.getGrandeza();
    }
    return grandeza;
}

std::string Escena::getAnimalsNames() {
    std::string nombres;
    for (Animal animal : animales) {
        nombres = nombres + animal.getNombreAnimal();
        nombres = nombres + "_";
    }
    return nombres;
}
    