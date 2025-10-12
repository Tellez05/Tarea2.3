#pragma once 
#include "ListaEnlazada.h"

class MyLinkedlist{
    private: 
    public: 
    ListaEnlazada* head; 
    ListaEnlazada* tail; 
    int Size {0}; 
    MyLinkedlist(); 
    ~MyLinkedlist();
    void mergeSort(); //El primero que manda a llamar
    void mergeSort(int inicio, int final); //La recursiva
    void mezcla(int inicio, int final, int central); 
    void insert(string linea);
    string regresarTodo(); 
    void deleteFirst(); 
    bool isEmpty(); 
    bool esMenoroIgual(ListaEnlazada* a, ListaEnlazada* b); 
};
