#include <iostream>
#include <chrono>

#include "lib/animales/animal.h"
#include "lib/escena/escena.h"
#include "lib/estrucurasDeDatos/cpp-rojinegroTrie/red_black_tree.h"
#include "lib/estrucurasDeDatos/cpp-linkedList/linkedList.h"
#include "lib/estrucurasDeDatos/base_container/base_container.h"
#include "lib/data_structure_factory/zoo_data_structure_factory.h"
#include "lib/data_structure_factory/zoo_data_structure_type_enum.h"
#include "lib/evento/evento.h"
#include "lib/estrucurasDeDatos/cpp-linkedList/linkedList.h"


//using namespace std;

int main() {

    std::cout << "Cali Zoo Awesome Event!" << std::endl << std::endl;
    std::cout << "Ingresa la estructura de datos a utilizar" << " (Seguido de Enter)" <<std::endl;
    std::cout << "   1). LinkedList" << std::endl;
    std::cout << "   2). Tabla Hash" << std::endl;
    std::cout << "   3). Árbol Rojinegro" << std::endl;
    std::cout << "   4). Generar sets de pruebas" << std::endl;

    std::string userInput;
    // Read user input from the console
    std::cin >> userInput;

    std::cout << "Su entrada fue: " << userInput << std::endl;

    std::cout << "Ingrese k: " << std::endl;
    std::string k;
    // Read user input from the console
    std::cin >> k;


    int intValue = (std::stoi(userInput)) - 1;


    LinkedList<Parte> partes;
    LinkedList<Escena> escenas;
    LinkedList<Escena> escenasVacia;
    Evento evento = Evento(6, 3, 2, partes, escenas);
    evento.generarAnimales();
    evento.llenarEscenas();
    evento.crearApertura();
    
    /**/
    for(int i = 0; i<2; i++){
        LinkedList<Escena>* misescenaVacia = new LinkedList<Escena>();
        evento.agregarPartes(misescenaVacia);
    }

    std::shared_ptr<BaseContainer<Escena>> escene_ptr = nullptr;

    if (intValue >= static_cast<int>(DataStructureType::LinkedList) &&
        intValue <= static_cast<int>(DataStructureType::RedBlackTree)) {
        // Cast the integer to DataStructureType Enum for BaseContainer subtype selection.
        DataStructureType type = static_cast<DataStructureType>(intValue);
        // Create the factory for means the factory pattern.
        escene_ptr = DataStructureFactory<Escena>::createDataStructure(type);
    } else {
        std::cout << "Invalid integer value for BaseContainer selection" << std::endl;
    }

    if (escene_ptr != nullptr) {
        
    }

    /* Animal animal = Animal(4);

    std::set<Animal> animals = {Animal(4), Animal(6), Animal(10)};
    Escena treeEscenes(animals);
    Escena listEscenes(animals);

    RedBlackTree<Escena>* esceneTree = new RedBlackTree<Escena>();
    esceneTree->insert(treeEscenes);

    LinkedList<Escena>* esceneList = new LinkedList<Escena>();
    esceneList->append(listEscenes);

    for (const auto& escena : *esceneTree) {
        cout << "La grandeza de la escenaTree es: " << escena.getAnimalGreatness() << endl;
    }

    for (const auto& escena : *esceneList) {
        cout << "La grandeza de la escenaList es: " << escena.getAnimalGreatness() << endl;
    }

    cout << animal.getNombreAnimal() << endl;
    cout << animal.getGrandeza() << endl; */
    
    /*/
    //evento.agregarParte(misescenasVacias);

    std::cout << "generando partes" << std::endl;
    for(int i = 0; i< partes.sizeC(); i++){
        std::cout << partes[i].getParteAnimalsNames() << std::endl;
        std::cout << partes[i].getAnimalGreatness() << std::endl;
    }
    std::cout << "generando animales" << std::endl;
    for(Animal animal : evento.getAnimales()){
        std::cout << animal.getNombreAnimal() << std::endl;
        std::cout << animal.getGrandeza() << std::endl;
    }

    std::cout << "generando escenas" << std::endl;
    for(int i = 0; i<  escenas.sizeC(); i++){
        std::cout << escenas[i].getAnimalsNames() << std::endl;
        std::cout << escenas[i].getAnimalGreatness() << std::endl;
    }*/
    
    return 0;
}