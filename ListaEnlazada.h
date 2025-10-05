#pragma once 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std; 

class ListaEnlazada{
    int Num1, Num2, Num3, Num4, Num5; 
    ListaEnlazada* Next; 
    ListaEnlazada(string Lista, ListaEnlazada* next);
    ListaEnlazada(string Lista):ListaEnlazada(Lista, nullptr){}
};

