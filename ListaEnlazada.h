#pragma once 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std; 

class ListaEnlazada{
    private:
    int Num1, Num2, Num3, Num4, Num5;
    string Mes, Dia, Hora, IP, Resto;  
    public: 
    ListaEnlazada* Next; 
    //N(1)
    ListaEnlazada(string Lista, ListaEnlazada* next);
    //N(1)
    ListaEnlazada(string Lista):ListaEnlazada(Lista, nullptr){}
    //N(1)
    void CrearVariables(string linea);
    //N(1)
    void CrearNumeros(string linea); 
    //N(1)
    string RegresarTodo(); 
};

