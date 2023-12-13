#include "animal.h"
#include <random>


const std::vector<std::string> nombresAnimales = {"Leon","Tigre","Elefante","Jirafa","Cebra","Oso","Canguro","Panda","Gorila","Chimpance","Hipopotamo","Rinoceronte","Cocodrilo","Caiman","Flamenco","Pinguino","Avestruz","PavoReal","Koala","Perezoso","Lobo","Zorro","Bisonte","Bufalo","Camello","Dromedario","Foca","Leopardo","Jaguar","Mono","Murcielago","Nutria","Puercoespin","Armadillo","Suricata","Okapi","Iguana","Tortuga","Serpiente","Cacatua","Tucan","Lince","Puma","Guacamayo","Orix","Antilope","Gacela","Mandril","Lemur","Carpincho"};

int tamNombres = nombresAnimales.size();

int generarGrandeza(int n){
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> distribGrandeza(1, n);
    int j = distribGrandeza(engine);
    return j;
}

std::string generarNombre(){
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> distribNombre(0, tamNombres -1);
    int i = distribNombre(engine);
    return nombresAnimales[i];
}

Animal::Animal(int n){
    
    nombre_animal = generarNombre();
    int value = generarGrandeza(n);
    grandeza = value;
}

std::string Animal::getNombreAnimal() const{
    return nombre_animal;
}

int Animal::getGrandeza() const {
    return grandeza;
}

bool Animal::operator<(const Animal& other) const{
    return this->grandeza < other.grandeza;
}

std::ostream& operator<<(std::ostream& os, const Animal& animal) {
    os << "{Animal: " << animal.getNombreAnimal() << "; Grandeza: " << animal.getGrandeza() << "}" << std::endl;
    return os;
}
