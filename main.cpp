#include "ListaEnlazada.h"
#include "MyLinkedlist.h"
#include "Functions.h"

int main(){
    int contador {0}; 
    MyLinkedlist* Lista = new MyLinkedlist();
    cargarDocumento(Lista);
    Lista->mergeSort();  
    entregarDocumento(Lista); 
    bool V {true};
    while(V == true){
        V = menu(Lista, contador);
    }
    return 0; 
}