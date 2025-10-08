#include "ListaEnlazada.h"

class MyLinkedlist{
    private: 
    ListaEnlazada* Head; 
    ListaEnlazada* Tail; 
    public: 
    int Size {0}; 
    MyLinkedlist(); 
    void Mergesort(); //El primero que manda a llamar
    void Mergesort(int inicio, int final); //La recursiva
    void Mezcla(int inicio, int final, int central); 
    void Insert(string linea);
    string RegresarTodo(); 
    void DeleteFirst(); 
};
