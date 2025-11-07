/*
Andres Tellez Bermudez Matricula: A01640907
Luis Eduardo Michel    Matricula: A01641578
Jared Rafael Garcia    Matricula: A01640914
Fecha: 13/10/2025
Tarea 2.3
*/

#include "Functions.h"

//O(n)
void cargarDocumento(MyLinkedlist* &Lista){
    ifstream archivo("bitacora.txt"); 
    string linea; 
    while(getline(archivo, linea)){
        Lista->insert(linea);
    }
    archivo.close(); 
}

//O(1)
string crearNombre(int contador){
    string Contador {to_string(contador)};
    return "Salida"+Contador+"-Eq5.txt";
}
//O(n)
void entregarDocumento(MyLinkedlist* Lista, MyBST* BST){
    ofstream archivo("bitacoraOrdenadaIp-Eq5.txt"); 
    string linea;
    int contador {1}; 
    ListaEnlazada* Current = Lista->head; 
    bool Ver {false};
    while (Current != nullptr) {
        if (Current->Next == nullptr) {
            BST->insert(extraerIP(Current->RegresarTodo()), contador);
            break;
        }
        else if (extraerIP(Current->RegresarTodo()) == extraerIP(Current->Next->RegresarTodo())) {
            contador++;
        }
        else {
            BST->insert(extraerIP(Current->RegresarTodo()), contador);
            contador = 1;
        }
        archivo << Current->RegresarTodo() << endl;
        Current = Current->Next;
    }
    archivo.close(); 

}

string extraerIP(string linea){
    stringstream ss(linea);
    string Mes, Dia, Hora, Ip1, rest; 
    ss>>Mes>>Dia>>Hora>>Ip1; 
    getline(ss, rest);
    string IPP = crearIP(Ip1);
    return IPP; 
}

string crearIP(string linea){
    stringstream ss(linea);
    char punto, puntos; 
    int Num1, Num2, Num3, Num4, Puerto; 
    ss>>Num1>>punto>>Num2>>punto>>Num3>>punto>>Num4>>puntos>>Puerto; 
    string IP = to_string(Num1)+punto+to_string(Num2)+punto+to_string(Num3)+punto+to_string(Num4);
    return IP; 
}