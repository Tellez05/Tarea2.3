#pragma once
#include "MyLinkedlist.h"


void CargarDocumento(MyLinkedlist* &Lista);
void EntregarDocumento(MyLinkedlist* Lista);
void EntregarDocumentoBusq(MyLinkedlist* Lista,string BusquedaInicial, string BusquedaFinal, string nombre);
bool Menu(MyLinkedlist* &Lista, int &contador); 
int SacarPrimerNumero(string linea);   
string CrearNombre(int contador);  