#pragma once
#include <string>
#include <vector>
#include <ostream>

class Animal {
    private:
        std::string nombre_animal;
        int grandeza;
        static const std::vector<std::string> nombresAnimales;
        
    public:
        Animal(int n);
        std::string getNombreAnimal() const;
        int getGrandeza() const;
        bool operator<(const Animal& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Animal& animal);
};