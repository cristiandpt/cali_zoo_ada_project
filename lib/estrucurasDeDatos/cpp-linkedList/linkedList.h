#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "./node.h"

template <typename T>
class LinkedList: public BaseContainer<T> {
public:
    // Constructor
    LinkedList(): head(nullptr){}

    // Destructor 
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->getNext();
            delete current;
            current = next;
        }
    } 

    //Agrega un elemento al final de la lista
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
    }

    // Elimina un elemento de la lista
    bool remove(T value) {
        Node<T>* current = head;
        Node<T>* previous = nullptr;
        while (current != nullptr)
        {
            // Si el valor del nodo actual es igual al valor buscado
            if(current ->getValue() == value){
                // Si el nodo actual es el primero
                if(previous == nullptr){
                    // Se cambia el head de la lista
                    head = current->getNext();
                }
                // Si el nodo actual no es el primero
                else{
                    // Se cambia el puntero del nodo anterior
                    previous->setNext(current->getNext());
                }
                delete current;
                return true;
            }
            // Si el valor del nodo actual no es igual al valor buscado
            previous = current;
            current = current->getNext();
        }
        // Si no se encontró el valor
        return false;
        
    } 

    // Busca un elemento en la lista
    Node<T>* find(T value) {
        Node<T>* current = head;
        while (current != nullptr)
        {
            // Si el valor del nodo actual es igual al valor buscado
            if(current ->getValue() == value){
                return current;
            }
            current = current->getNext();
        }
        // Si no se encontró el valor
        return nullptr;
    }

    // Accesor para head
    Node<T>* getHead() const { return head; } 

    /*
     * Devuelve la grandeza maxima de los animales de la lista
     */
    std::size_t  max() override {
        Node<T>* current = head;
        int max = current->getValue().getAnimalGreatness();
        while (current != nullptr)
        {
            if(current->getValue().getAnimalGreatness() > max){
                max = current->getValue().getAnimalGreatness();
            }
            current = current->getNext();
        }
        return max;
    }

    /*
     * Devuelve la grandeza minima de los animales de la lista
     */
    std::size_t  min() override {
        Node<T>* current = head;
        int min = current->getValue().getAnimalGreatness();
        while (current != nullptr)
        {
            if(current->getValue().getAnimalGreatness() < min){
                min = current->getValue().getAnimalGreatness();
            }
            current = current->getNext();
        }
        return min;
    }

    /*
     * Devuelve el tamaño de la lista
     */
    std::size_t  sizeC() override {
        Node<T>* current = head;
        int size = 0;
        while (current != nullptr)
        {
            size++;
            current = current->getNext();
        }
        return size;
    }

    /*
     * Devuelve el animal en la posicion index
     */
    T& operator[](std::size_t  index) override{
        Node<T>* current = head;
        std::size_t i = 0; 
        while (current != nullptr)
        {
            if(i == index){
                return current->getValue();
            }
            i++;
            current = current->getNext();
        }
            // If the index is out of bounds, throw an exception
        throw std::out_of_range("Index out of bounds");
    }

     // Implement the Iterator for LinkedList
    class Iterator : public BaseContainer<T>::Iterator {

        public:
            Iterator(Node<T>* node): current(node) {}

            typename BaseContainer<T>::Iterator::reference operator*() const override {
                return current->getValue();
            }

            Iterator& operator++() override {
                if (current != nullptr) {
                    current = current->getNext();
                }
                return *this;
            }

            bool operator==(const typename BaseContainer<T>::Iterator& other) const override {
                return current == static_cast<const Iterator&>(other).current;
            }

            bool operator!=(const typename BaseContainer<T>::Iterator& other) const override {
                return !(*this == other);
            }

            ~Iterator() = default;

        private:
            Node<T>* current;
    };

     // Implement the iterator functions
    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    std::size_t  aggregate() override {
        return 0;
    };

    double  mean() override { return 0.0; };
    void insert(T& value) {
        append(value);
    };


private:
    Node<T>* head; // Puntero al primer elemento
};
#endif

