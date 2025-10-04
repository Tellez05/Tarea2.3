#pragma once 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std; 

struct ListaEnlazada{
    int Data; 
    ListaEnlazada* Next; 
    ListaEnlazada(int data, ListaEnlazada* next){
        Data = data; 
        this->Next = Next; 
    }
    ListaEnlazada(int data):ListaEnlazada(data, nullptr){}
};

class MuLinkedlist{
    private: 
    ListaEnlazada* Head; 
    ListaEnlazada* Tail; 
};
