#pragma once
#include "MyLinkedlist.h"


void CargarDocumento(MyLinkedlist* &Lista);
void EntregarDocumento(MyLinkedlist* Lista);
void EntregarDocumentoBusq(MyLinkedlist* Lista,string BusquedaInicial, string BusquedaFinal, string nombre);
bool Menu(MyLinkedlist* &Lista, int &contador); 
int SacarPrimerNumero(string linea);   
string CrearNombre(int contador);  
void CreadorVariablesBusq(string linea, int &Num1, int & Num2, int &Num3, int &Num4, int &Puerto);
