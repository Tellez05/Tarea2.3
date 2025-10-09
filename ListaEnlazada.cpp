#include "ListaEnlazada.h"

//N(1)
ListaEnlazada::ListaEnlazada(string Linea, ListaEnlazada *next){
    this->Next=next; 
    CrearVariables(Linea);
}

//N(1)
void ListaEnlazada::CrearVariables(string linea){
    stringstream ss(linea);
    ss>>Mes>>Dia>>Hora>>IP; 
    getline(ss, Resto);
    CrearNumeros(IP);
}

//N(1)
void ListaEnlazada::CrearNumeros(string IP){
    stringstream ss(IP);
    char punto; 
    ss>>Num1>>punto>>Num2>>punto>>Num3>>punto>>Num4>>Puerto; 
}

string ListaEnlazada::RegresarTodo(){
    string espacio {" "};
    return Mes + espacio + Dia + espacio + Hora + espacio +  IP + Resto;
}


