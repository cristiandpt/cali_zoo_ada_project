#include "../escena/escena.h"
#include "apertura.h"


Apertura::Apertura(std::initializer_list<std::set<Animal>> escenas): escenas(escenas) {}

/*
 std::vector<std::set<Animal>> Apertura::getEscenas() 
    {
        return escenas;
    }

 std::set<Animal>  Apertura::getAnimales() {
    std::set<Animal> animales;
    for (std::set<Animal> escena : escenas) {
        for (Animal animal : escena) {
            animales.insert(animal);
        }
    }
    return animales;
 }
*/
    