#include "./escena.h"
#include <sstream>

Escena::Escena(std::set<Animal> animales): animales(animales) {}

std::set<Animal> Escena::getAnimals() {
        return animales;
}

int Escena::getAnimalGreatness() const {
    int grandeza = 0;
    for (Animal animal : animales) {
        grandeza += animal.getGrandeza();
    }
    return grandeza;
}

std::string Escena::getAnimalsNames() const {
    std::ostringstream oss;
    for (const auto& animal : animales) {
        oss << "|" <<animal.getNombreAnimal() << "|";
    }
    return oss.str();
}

bool Escena::operator<(const Escena& other) const {
        return this->getAnimalGreatness() < other.getAnimalGreatness();
}

std::ostream& operator<<(std::ostream& os, const Escena& escene) {
    os << "Escena: " << escene.getAnimalsNames() << std::endl;
    return os;
}    