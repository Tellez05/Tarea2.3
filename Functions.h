#pragma once
#include "MyLinkedlist.h"


void cargarDocumento(MyLinkedlist* &Lista);
void entregarDocumento(MyLinkedlist* Lista);
void entregarDocumentoBusq(MyLinkedlist* Lista,string BusquedaInicial, string BusquedaFinal, string nombre);
bool menu(MyLinkedlist* &Lista, int &contador); 

string crearNombre(int contador);  
void creadorVariablesBusqInicial(string linea, int &Num1, int & Num2, int &Num3, int &Num4, int &Puerto);
void creadorVariablesBusqFinal(string linea, int &Num1, int & Num2, int &Num3, int &Num4, int &Puerto);
