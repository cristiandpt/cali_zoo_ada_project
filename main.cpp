#include <iostream>

#include "lib/animales/animal.h"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Animal animal = Animal(4);
    cout << animal.getNombreAnimal() << endl;
    cout << animal.getGrandeza() << endl;
    return 0;
}