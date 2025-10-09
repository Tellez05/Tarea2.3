#include "ListaEnlazada.h"
#include "MyLinkedlist.h"
#include "Functions.h"



int main(){
    int contador {0}; 
    MyLinkedlist* Lista = new MyLinkedlist();
    CargarDocumento(Lista);
    Lista->Mergesort();  
    cout<<Lista->Size; 
    EntregarDocumento(Lista); 
    bool V {true};
    while(V == true){
        V = Menu(Lista, contador);
    }
    return 0; 
}