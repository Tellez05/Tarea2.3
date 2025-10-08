#include "ListaEnlazada.h"
#include "MyLinkedlist.h"
#include "Functions.h"



int main(){
    int contador {0}; 
    MyLinkedlist* Lista;
    Lista->Mergesort();  
    EntregarDocumento(Lista); 
    do{
        Menu(Lista, contador); 
    }while(Menu != false); 
    return 0; 
}