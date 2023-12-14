#include <iostream>

#include "lib/animales/animal.h"
#include "lib/evento/evento.h"
#include "lib/estrucurasDeDatos/cpp-linkedList/linkedList.h"


//using namespace std;

int main() {
    
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