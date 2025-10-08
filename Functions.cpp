#include "Functions.h"

void CargarDocumento(MyLinkedlist* &Lista){
    ifstream archivo("bitacora.txt"); 
    string linea; 

    while(getline(archivo, linea)){
        Lista->Insert(linea);
    }
}

void EntregarDocumento(MyLinkedlist* Lista){
    ofstream archivo("bitacoraOrdenadaIp-Eq5"); 
    string linea; 
    while(Lista->Size>0){
        archivo<<Lista->RegresarTodo()<<endl;        
        Lista->DeleteFirst();
    }
}