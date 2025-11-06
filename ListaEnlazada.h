/*
Andres Tellez Bermudez Matricula: A01640907
Luis Eduardo Michel    Matricula: A01641578
Jared Rafael Garcia    Matricula: A01640914
Fecha: 13/10/2025
Tarea 2.3
*/
#pragma once 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std; 

class ListaEnlazada{
    private:
    public: 
    string Mes, Dia, Hora, IP, Resto;  
    int Num1, Num2, Num3, Num4, Puerto;
    ListaEnlazada* Next; 
    //O(1)
    ListaEnlazada(string Lista, ListaEnlazada* next);
    //O(1)
    ListaEnlazada(string Lista):ListaEnlazada(Lista, nullptr){}
    //O(1)
    void CrearVariables(string linea);
    //O(1)
    void CrearNumeros(string linea); 
    //O(1)
    string RegresarTodo(); 
};

