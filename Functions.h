/*
Andres Tellez Bermudez Matricula: A01640907
Luis Eduardo Michel    Matricula: A01641578
Jared Rafael Garcia    Matricula: A01640914
Fecha: 13/10/2025
Tarea 2.3
*/
#pragma once
#include "MyLinkedlist.h"
#include "MyBST.h"
//O(n)
void cargarDocumento(MyLinkedlist* &Lista);
//O(n)
void entregarDocumento(MyLinkedlist* Lista, MyBST* BST);

//O(1)
string crearNombre(int contador);  
//O(1)

string extraerIP(string linea); 

string crearIP(string linea);