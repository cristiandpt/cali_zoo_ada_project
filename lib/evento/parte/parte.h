#ifndef PARTE_H
#define PARTE_H

#include <set>
#include <string>

#include "../../escena/escena.h"
#include "../../estrucurasDeDatos/base_container/base_container.h"

class Parte{
    public:
        Parte(BaseContainer<Escena>& escenas);
        ~Parte();
        BaseContainer<Escena>& getEscenas();
        int getAnimalGreatness() const;
        std::string getParteAnimalsNames();
        bool operator<(const Parte& other) const;
        bool operator==(const Parte& other) const;
        bool operator<=(const Parte& other) const;   
        
    private:
        BaseContainer<Escena>& escenas;      
};

#endif