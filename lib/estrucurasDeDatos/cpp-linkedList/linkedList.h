#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "./node.h"
#include <stdexcept>

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
    void insert(T& value) override {
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
    /*bool findBool(const T& value) override{
        Node<T>* current = head;
        while (current != nullptr)
        {
            // Si el valor del nodo actual es igual al valor buscado
            if(current ->getValue() == value){
                return true;
            }
            current = current->getNext();
        }
        // Si no se encontró el valor
        return false;
    }*/

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
        throw std::out_of_range("Índice fuera de rango");
    }

    /*
     * Divide la lista en dos
     */
    /*std::pair<BaseContainer<T>*,BaseContainer<T>*> divide() override{

        LinkedList<T>* firstHalf = new LinkedList<T>();
        LinkedList<T>* secondHalf = new LinkedList<T>();
        Node<T>* slow = head;
        Node<T>* fast = head;
        Node<T>* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) prev->next = nullptr;
        firstHalf->head = head;
        secondHalf->head = slow;

        return std::make_pair(firstHalf, secondHalf);
    }

    BaseContainer<T>* merge(BaseContainer<T>* other) {
        LinkedList<T>* merged = new LinkedList<T>();
        Node<T> *ptr1 = this->head, *ptr2 = other->head;

        while (ptr1 && ptr2) {
            if (ptr1->value < ptr2->value) {
                merged->insert(ptr1->value);
                ptr1 = ptr1->next;
            } else {
                merged->insert(ptr2->value);
                ptr2 = ptr2->next;
            }
        }

        while (ptr1) {
            merged->insert(ptr1->value);
            ptr1 = ptr1->next;
        }

        while (ptr2) {
            merged->insert(ptr2->value);
            ptr2 = ptr2->next;
        }

        return merged;
    }*/


private:
    Node<T>* head; // Puntero al primer elemento
};
#endif

