#include "animal.h"

// constructor de la clase Animal
Animal::Animal(AnimalNombre nombre_animal, int grandeza)
    :nombre_animal(nombre_animal), grandeza(grandeza) {}

// retorna el nombre del animal
AnimalNombre Animal::getNombreAnimal() 
    {
        return nombre_animal;
    }
    
// retorna la grandeza del animal
int Animal::getGrandeza() 
    {
        return grandeza;
    }