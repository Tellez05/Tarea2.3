/*
Andres Tellez Bermudez Matricula: A01640907
Luis Eduardo Michel    Matricula: A01641578
Jared Rafael Garcia    Matricula: A01640914
Fecha: 13/10/2025
Tarea 2.3*/

#pragma once 
#include "ListaEnlazada.h"

struct MyNodeBST{
    string IP;
    int repeticiones;
    MyNodeBST *left,
              *right;
    MyNodeBST(string linea, int cont){
        this->IP = linea;
        this->left=this->right=nullptr;
        this->repeticiones = cont; 
    }
    MyNodeBST(){}
};

class MyBST{
    private: 
    MyNodeBST* root; 
    public: 
    void insert(string linea, int contador); 
    MyBST(); 
    void inorder(int &num);
    void inorder(MyNodeBST* current, int &num); 
};