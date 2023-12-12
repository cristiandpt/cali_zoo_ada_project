#ifndef EVENTO_H
#define EVENTO_H

#include "../animales/animal.h"
#include "../escena/escena.h"

class Evento{

    public:
        Evento(int n, int m, int k);
        ~Evento();
        int getN();
        int getM();
        int getK();
        Animal animalMasConcurrente();
        Animal animalMenosConcurrente();
        Escena escenaMenorGrandeza();
        Escena escenaMayorGrandeza();
        double getPromedioGrandeza();

};

#endif