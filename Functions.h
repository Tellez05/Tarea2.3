#pragma once
#include "MyLinkedlist.h"


void CargarDocumento(MyLinkedlist* &Lista);
void EntregarDocumento(MyLinkedlist* Lista);
void EntregarDocumentoBusq(MyLinkedlist* Lista,string BusquedaInicial, string BusquedaFinal, string nombre);
bool Menu(MyLinkedlist* &Lista, int &contador); 

string CrearNombre(int contador);  
void CreadorVariablesBusqInicial(string linea, int &Num1, int & Num2, int &Num3, int &Num4, int &Puerto);
void CreadorVariablesBusqFinal(string linea, int &Num1, int & Num2, int &Num3, int &Num4, int &Puerto);
