#include <iostream>

#include "lib/animales/animal.h"
#include "lib/escena/escena.h"
#include "lib/estrucurasDeDatos/cpp-rojinegroTrie/red_black_tree.h"
#include "lib/estrucurasDeDatos/base_container/base_container.h"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Animal animal = Animal(4);

    std::set<Animal> animals = {Animal(4), Animal(6), Animal(10)};
    Escena treeEscenes(animals);

    RedBlackTree<Escena>* esceneTree = new RedBlackTree<Escena>();
    esceneTree->insert(treeEscenes);
    esceneTree->inorderTraversal();

    cout << animal.getNombreAnimal() << endl;
    cout << animal.getGrandeza() << endl;
    return 0;
}