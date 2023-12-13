#include "evento.h"
#include <random>
#include <iostream>

using namespace std;

int generarIntRandom(int min, int max){
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> distribNombre(min, max);
    int i = distribNombre(engine);
    return i;
}

std::stack<int> Evento::generarStackRandom(){
    int min = 0;
    int max = nEscenasApertura-1;
    std::stack<int> stack;
    std::set<int> numeros;
    size_t tam = static_cast<size_t>(max-min+1);
    while (numeros.size()<tam){
        int numeroAleatorio = generarIntRandom(min, max);

        if(numeros.insert(numeroAleatorio).second){
            
            stack.push(numeroAleatorio);
        }
    }
    return stack;
}

Evento::Evento(int n, int m, int k, BaseContainer<Parte>& partes, BaseContainer<Escena>& escenas): n(n), m(m), k(k){
    
    this->escenas = &escenas;
    this->partes = &partes;
    nEscenasApertura = (m-1)*k;
    nPartes = m-1;
    stack = generarStackRandom();

}

Evento::~Evento(){}

int Evento::getN(){
    return n;
}

int Evento::getM(){
    return m;
}

int Evento::getK(){
    return k;
}

int Evento::getNEscenasApertura(){
    return nEscenasApertura;
}

int Evento::getNPartes(){
    return nPartes;
}

int Evento::getAnimalesPorEscena(){
    return animalesPorEscena;
}

//corregir
void Evento::generarAnimales(){
    for (int i = 1; i <= n; i++) {
        Animal nuevoAnimal(i);
        animales.push_back(nuevoAnimal);
    }
}

std::vector<Animal> Evento::getAnimales(){
    return animales;
}


void Evento::llenarEscenas(){
    
    do{
        std::set<Animal> animalesAAgregar;
        std::set<std::set<Animal>> animalesAgregados;

        while(animalesAAgregar.size() < 3){
            animalesAAgregar.insert(animales[generarIntRandom(0, n-1)]);
        }
        
        if(animalesAgregados.find(animalesAAgregar) != animalesAgregados.end()){
            break;
        }
        animalesAgregados.insert(animalesAAgregar);
        Escena nuevaEscena(animalesAAgregar);
        escenas->insert(nuevaEscena);   

    }while (escenas->sizeC() < static_cast<std::size_t>(nEscenasApertura));   

}

void Evento::crearApertura(){
    Parte apertura(*escenas);
    partes->insert(apertura);
    
}

void Evento::agregarPartes(BaseContainer<Escena>* escenasVacia){
    cout << "llegue aqui" << endl;
    Parte nuevaParte(*escenasVacia);
    
        for(int i = 0; i < k; i++){
            int indice = stack.top();
            cout << indice << endl;
            stack.pop();
            Escena escena = (*escenas)[indice];
            
            nuevaParte.getEscenas().insert(escena);
        }
    partes->insert(nuevaParte);
}

