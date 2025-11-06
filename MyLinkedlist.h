/*
Andres Tellez Bermudez Matricula: A01640907
Luis Eduardo Michel    Matricula: A01641578
Jared Rafael Garcia    Matricula: A01640914
Fecha: 13/10/2025
Tarea 2.3
*/
#pragma once 
#include "ListaEnlazada.h"

class MyLinkedlist{
    private: 
    public: 
    ListaEnlazada* head; 
    ListaEnlazada* tail; 
    int Size {0}; 
    //O(1)
    MyLinkedlist(); 
    //O(n)
    ~MyLinkedlist();
    //O(1)
    void mergeSort(); //El primero que manda a llamar
    //O(n log n )
    void mergeSort(int inicio, int final); //La recursiva
    //O(n)
    void mezcla(int inicio, int final, int central); 
    //O(1)
    void insert(string linea);
    //O(1)
    string regresarTodo(); 
    //O(1)
    void deleteFirst(); 
    //O(1)
    bool isEmpty(); 
    //O(1)
    bool esMenoroIgual(ListaEnlazada* a, ListaEnlazada* b); 
};
