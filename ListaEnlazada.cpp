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
    ss>>Num1>>Num2>>Num3>>Num4>>Puerto; 
}

string ListaEnlazada::RegresarTodo(){
    string espacio {" "};
    return Mes + espacio + Dia + Hora + IP + Resto;
}


