#include "parte.h"

Parte::Parte(BaseContainer<Escena>& escenas) : escenas(escenas) {
    // constructor implementation
}


Parte::~Parte() {
    // destructor implementation
}

BaseContainer<Escena>& Parte::getEscenas() {
    return escenas;
}

int Parte::getAnimalGreatness() {
    int grandeza = 0;
    for (std::size_t i = 0; i < escenas.sizeC(); i++) {
        grandeza += escenas[i].getAnimalGreatness();
    }
    return grandeza;
}

std::string Parte::getParteAnimalsNames() {
    std::string nombres;
    for (std::size_t i = 0; i < escenas.sizeC(); i++) {
        nombres = nombres + escenas[i].getAnimalsNames();
        nombres = nombres + "/";
    }
    return nombres;
}