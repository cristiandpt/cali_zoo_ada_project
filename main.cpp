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

#include <typeinfo>

//using namespace std;

int main(int argc, char* argv[]) {

    std::cout << "Cali Zoo Awesome Event!" << std::endl << std::endl;
    std::cout << "Ingresa la estructura de datos a utilizar" << " (Seguido de Enter)" <<std::endl;
    std::cout << "   1). LinkedList" << std::endl;
    std::cout << "   2). Tabla Hash" << std::endl;
    std::cout << "   3). Árbol Rojinegro" << std::endl;
    std::cout << "   4). Generar sets de pruebas" << std::endl;

    std::string userInput;
    // Read user input from the console
    std::cin >> userInput;

    if (argc != 4) {
        // Throw an exception if the value is negative
        throw std::invalid_argument("Must provide 3 arguments");
    }

    const int n = std::stoi(argv[1]);
    const int k = std::stoi(argv[2]);
    const int m = std::stoi(argv[3]);

    std::cout << "Su entrada fue: " << userInput << std::endl;

    int intValue = std::stoi(userInput) - 1;

    // BaseContainer<Parte>* partes = nullptr;
    // BaseContainer<Escena>* escenas = nullptr;
    // BaseContainer<Escena>* escenasVacia = nullptr;


    //LinkedList<Parte> partes;
    //LinkedList<Escena> escenas;
    //LinkedList<Escena> escenasVacia;


    std::shared_ptr<BaseContainer<Parte>> parts_ptr = nullptr;
    std::shared_ptr<BaseContainer<Escena>> escenes_ptr = nullptr;
   
    if (intValue >= static_cast<int>(DataStructureType::LinkedList) &&
        intValue <= static_cast<int>(DataStructureType::RedBlackTree)) {
        
        // Cast the integer to DataStructureType Enum for BaseContainer subtype selection.
        DataStructureType type = static_cast<DataStructureType>(intValue);
        // Create the factory for means the factory pattern.
        escenes_ptr = DataStructureFactory<Escena>::createDataStructure(type);
        parts_ptr = DataStructureFactory<Parte>::createDataStructure(type);

        Evento evento = Evento(n, m, k, parts_ptr, escenes_ptr);
        evento.generarAnimales();
        std::cout << "Hola 1?" << std::endl;

        evento.llenarEscenas();
        std::cout << "Hola 2?" << std::endl;

        evento.crearApertura();
        std::cout << "Hola? 3" << std::endl;

   
        for(int i = 1; i < m; i++){
            std::shared_ptr<BaseContainer<Escena>> empty_escenes_ptr = DataStructureFactory<Escena>::createDataStructure(type);
            evento.agregarPartes(empty_escenes_ptr);
        }
    } else {
        std::cout << "Invalid integer value for BaseContainer selection" << std::endl;
    }

    if (escenes_ptr != nullptr) {
        
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