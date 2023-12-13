#include <iostream>

#include "lib/animales/animal.h"
#include "lib/evento/evento.h"
#include "lib/estrucurasDeDatos/cpp-linkedList/linkedList.h"


using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    Animal animal = Animal(4);
    cout << animal.getNombreAnimal() << endl;
    cout << animal.getGrandeza() << endl;
    cout << "///////////////////////" << endl;
    LinkedList<Parte> partes;
    LinkedList<Escena> escenas;
    LinkedList<Escena> escenasVacia;
    Evento evento = Evento(6, 3, 2, partes, escenas);
    evento.generarAnimales();
    evento.llenarEscenas();
    evento.crearApertura();
    cout<<partes[0].getParteAnimalsNames()<<endl;
    //std::stack<int> randStack = evento.generarStackRandom();
    for(int i = 0; i<2; i++){
        
        LinkedList<Escena>* misescenaVacia = new LinkedList<Escena>();
        /*int indice = randStack.top();
        randStack.pop();*/
        evento.agregarPartes(misescenaVacia);
        cout << partes[1].getParteAnimalsNames() << endl;
    }
    //evento.agregarParte(misescenasVacias);
    
    cout << "generando partes" << endl;
    for(int i = 0; partes.sizeC(); i++){
        cout << partes[i].getParteAnimalsNames() << endl;
    }
    cout << "generando animales" << endl;
    for(Animal animal : evento.getAnimales()){
        cout << animal.getNombreAnimal() << endl;
    }

    cout << "generando escenas" << endl;
    for(int i = 0; escenas.sizeC(); i++){
        cout << escenas[i].getAnimalsNames() << endl;
    }
    
    return 0;
}