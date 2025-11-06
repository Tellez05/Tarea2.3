/*
Andres Tellez Bermudez Matricula: A01640907
Luis Eduardo Michel    Matricula: A01641578
Jared Rafael Garcia    Matricula: A01640914
Fecha: 13/10/2025
Tarea 2.3
*/
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