#include "MyLinkedlist.h"

MyLinkedlist::MyLinkedlist(){
    this->Head=this->Tail = nullptr; 
}

void MyLinkedlist::Mezcla(int inicio, int final, int central){

}
void MyLinkedlist::Mergesort(){
    Mergesort(0, this->Size-1); 
}
void MyLinkedlist::Insert(string linea){
    ListaEnlazada* Nuevo = new ListaEnlazada(linea, this->Head);
    Head = Nuevo; 
    Size++; 
    if(Size==1){
        Tail= Nuevo; 
    }
}
void MyLinkedlist::Mergesort(int inicio, int final){
    if(inicio<final){
        int central {(inicio+final)/2}; 
        Mergesort(inicio, central);
        Mergesort(central+1, final);
        Mezcla(inicio,final,central); 
    }
}