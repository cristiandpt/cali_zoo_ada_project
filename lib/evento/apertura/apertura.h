#pragma once
#include <set>

#include "../../animales/enumAnimal.h"
#include "../../animales/animal.h"
#include <vector>


class Apertura {
    private:
    std::vector<std::set<Animal>> escenas; 
    public:
        Apertura(std::initializer_list<std::set<Animal>> escenas);
        std::vector<std::set<Animal>>  getEscenas();
        std::set<Animal>  getAnimales();

};