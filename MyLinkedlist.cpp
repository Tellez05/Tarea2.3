#include "MyLinkedlist.h"
//N(1)
MyLinkedlist::MyLinkedlist(){
    this->Head=this->Tail = nullptr; 
}
//N(1)
void MyLinkedlist::DeleteFirst(){
    ListaEnlazada* temp = Head;
    this->Head = this->Head->Next;  
    delete temp; 
}

string MyLinkedlist::RegresarTodo(){
    return Head->RegresarTodo(); 
}
//N(1)
void MyLinkedlist::Insert(string linea){
    ListaEnlazada* Nuevo = new ListaEnlazada(linea, this->Head);
    Head = Nuevo; 
    Size++; 
    if(Size==1){
        Tail= Nuevo; 
    }
}

void MyLinkedlist::Mezcla(int inicio, int final, int central){
    /*
    Lo que haremos en esta es lo mismo que merge pero no crearemos una lista dinamica, si no que
    solo separaremos a la mitad del de la lista enlazada para hacer 2 listas y de ahi hacerlo 
    como un merge normal
    */
}   

void MyLinkedlist::Mergesort(){
    Mergesort(0, this->Size-1); 
}

void MyLinkedlist::Mergesort(int inicio, int final){
    if(inicio<final){
        int central {(inicio+final)/2}; 
        Mergesort(inicio, central);
        Mergesort(central+1, final);
        Mezcla(inicio,final,central); 
    }
}
