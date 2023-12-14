#include "animal.h"
#include <random>


const std::vector<std::string> nombresAnimales = {"Leon","Tigre","Elefante","Jirafa","Cebra","Oso","Canguro","Panda","Gorila","Chimpance","Hipopotamo","Rinoceronte","Cocodrilo","Caiman","Flamenco","Pinguino","Avestruz","PavoReal","Koala","Perezoso","Lobo","Zorro","Bisonte","Bufalo","Camello","Dromedario","Foca","Leopardo","Jaguar","Mono","Murcielago","Nutria","Puercoespin","Armadillo","Suricata","Okapi","Iguana","Tortuga","Serpiente","Cacatua","Tucan","Lince","Puma","Guacamayo","Orix","Antilope","Gacela","Mandril","Lemur","Carpincho"};

int tamNombres = nombresAnimales.size();

/*int generarGrandeza(int n){
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> distribGrandeza(1, n);
    int j = distribGrandeza(engine);
    return j;
}*/

//Genera un nombre aleatorio para el animal en el rango del nombresAnimales
std::string generarNombre(){
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> distribNombre(0, tamNombres -1);
    int i = distribNombre(engine);
    return nombresAnimales[i];
}

Animal::Animal(int grandeza){
    
    nombre_animal = generarNombre();
    this->grandeza = grandeza;
}

std::string Animal::getNombreAnimal(){
    return nombre_animal;
}

int Animal::getGrandeza(){
    return grandeza;
}

