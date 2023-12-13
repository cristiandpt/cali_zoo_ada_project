#ifndef EVENTO_H
#define EVENTO_H
#include "../animales/animal.h"
#include "../escena/escena.h"
#include "./parte/parte.h"
#include "../estrucurasDeDatos/base_container/base_container.h"
#include "../estrucurasDeDatos/cpp-linkedList/linkedList.h"
#include <stack>

class Evento{

    public:
        Evento(int n, int m, int k, BaseContainer<Parte>& partes, BaseContainer<Escena>& escenas);
        ~Evento();
        int getN();
        int getM();
        int getK();
        int getNEscenasApertura();
        int getNPartes();
        int getAnimalesPorEscena();
        Animal animalMasConcurrente();
        Animal animalMenosConcurrente();
        Escena escenaMenorGrandeza();
        Escena escenaMayorGrandeza();
        double getPromedioGrandeza();
        std::stack<int> generarStackRandom();
        void crearApertura();
        void agregarPartes(BaseContainer<Escena>* escenasVacia);
        void llenarEscenas();
        void generarAnimales();
        
        std::vector<Animal> getAnimales();

        //cambiar a private
        BaseContainer<Escena>* escenas = nullptr;


    private:
        int n;
        int m;
        int k;
        int nEscenasApertura;
        int nPartes ;
        const int animalesPorEscena = 3;
        std::vector<Animal> animales;
        BaseContainer<Parte>* partes = nullptr;
        std::stack<int> stack;
        
        

};

#endif