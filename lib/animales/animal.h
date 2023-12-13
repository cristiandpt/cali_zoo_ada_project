#pragma once
#include <string>
#include <vector>

class Animal {
    private:
        std::string nombre_animal;
        int grandeza;
        static const std::vector<std::string> nombresAnimales;
        
    public:
        Animal(int grandeza);
        std::string getNombreAnimal();
        int getGrandeza();

        bool operator<(const Animal& other) const {
            return this->grandeza < other.grandeza;
        }
    
};