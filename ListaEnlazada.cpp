/*
Andres Tellez Bermudez Matricula: A01640907
Luis Eduardo Michel    Matricula: A01641578
Jared Rafael Garcia    Matricula: A01640914
Fecha: 13/10/2025
Tarea 2.3
*/
#include "ListaEnlazada.h"

//O(1)
ListaEnlazada::ListaEnlazada(string Linea, ListaEnlazada *next){
    this->Next=next; 
    CrearVariables(Linea);
}

//O(1)
void ListaEnlazada::CrearVariables(string linea){
    stringstream ss(linea);
    ss>>Mes>>Dia>>Hora>>IP; 
    getline(ss, Resto);
    CrearNumeros(IP);
}

//O(1)
void ListaEnlazada::CrearNumeros(string IP){
    stringstream ss(IP);
    char punto; 
    ss>>Num1>>punto>>Num2>>punto>>Num3>>punto>>Num4>>Puerto; 
}
//O(1)
string ListaEnlazada::RegresarTodo(){
    string espacio {" "};
    return Mes + espacio + Dia + espacio + Hora + espacio +  IP + Resto;
}


