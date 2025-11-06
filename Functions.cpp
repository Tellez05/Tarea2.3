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
void creadorVariablesBusqInicial(string linea, int &Num1, int & Num2, int &Num3, int &Num4, int &Puerto){
    stringstream ss(linea);
    char punto, dospuntos; 
    ss>>Num1>>punto>>Num2>>punto>>Num3>>punto>>Num4>>dospuntos>>Puerto; 


}
//O(1)
void creadorVariablesBusqFinal(string linea, int &Num1, int & Num2, int &Num3, int &Num4, int &Puerto){
    stringstream ss(linea);
    char punto, dospuntos; 
    ss>>Num1>>punto>>Num2>>punto>>Num3>>punto>>Num4>>dospuntos>>Puerto; 
}

//O(N)
void entregarDocumentoBusq(MyLinkedlist* Lista, string BusquedaInicial, string BusquedaFinal, string Nombre){
    ofstream archivo(Nombre);
    int inicio {0}; 
    int final {0};
    int Inum1, Inum2, Inum3, Inum4, IPort, Fnum1, Fnum2, Fnum3, Fnum4, Fport; 
    creadorVariablesBusqInicial(BusquedaInicial, Inum1, Inum2, Inum3, Inum4, IPort);
    creadorVariablesBusqFinal(BusquedaFinal, Fnum1, Fnum2, Fnum3, Fnum4, Fport);  
    ListaEnlazada* Current = Lista->head;
    //Sacar Inicio y moverlo current hacia ese para poder 
    while(Current != nullptr && (
        (Current->Num1 < Inum1) ||
            (Current->Num1 == Inum1 && Current->Num2 < Inum2) ||
                (Current->Num1 == Inum1 && Current->Num2 == Inum2 && Current->Num3 < Inum3)||
                    (Current->Num1 == Inum1 && Current->Num2 == Inum2 && Current->Num3 == Inum3 && Current->Num4 < Inum4)||
                        (Current->Num1 == Inum1 && Current->Num2 == Inum2 && Current->Num3 == Inum3 && Current->Num4 == Inum4 && Current->Puerto < IPort))){
                            inicio++; 
                            Current = Current->Next; 
    } 
    //Sacar Final con el mismo metodo
    ListaEnlazada* Final = Current; 
    while(Current != nullptr && (
        (Current->Num1 < Fnum1) ||
            (Current->Num1 == Fnum1 && Current->Num2 < Fnum2) ||
                (Current->Num1 == Fnum1 && Current->Num2 == Fnum2 && Current->Num3 < Fnum3)||
                    (Current->Num1 == Fnum1 && Current->Num2 == Fnum2 && Current->Num3 == Fnum3 && Current->Num4 < Fnum4)||
                        (Current->Num1 == Fnum1 && Current->Num2 == Fnum2 && Current->Num3 == Fnum3 && Current->Num4 == Fnum4 && Current->Puerto < Fport))){
                            final++; 
                            Current = Current->Next; 
    } 
    int contador {inicio+final}; 
    for(int i {0}; i < final; i++){
        archivo<<Final->RegresarTodo()<<endl;
        Final = Final->Next; 
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

//O(n)
bool menu(MyLinkedlist* &Lista, int &contador){
    cout<<"Menu: "<<endl; 
    cout<<"1.- Busqueda"<<endl; 
    cout<<"2.- Salir"<<endl; 
    cout<<"Opcion: "; 
    int opcion; 
    cin >> opcion;
    if(opcion == 1){
        string BusquedaInicial, BusquedaFinal; 
        cout<<"Dame el IP que intentas buscar (Eje: 43:3:340:44:6166 ): ";
        cin.ignore(); 
        getline(cin,BusquedaInicial);
        cout<<"Dame el IP final: "; 
        getline(cin,BusquedaFinal);
        string Nombre;
        Nombre = crearNombre(contador+1); 
        entregarDocumentoBusq(Lista, BusquedaInicial, BusquedaFinal, Nombre); 
        contador++; 
        return true; 
    }  
    else if(opcion == 2){
        cout<<"Bye bye"<<endl; 
        return false;
    }
    else{
        cout<<"Opcion invalida"<<endl;
        return true;
    }
}


string extraerIP(string linea){
    stringstream ss(linea);
    char punto, dospuntos;
    string Num1, Num2, Num3, Num4; 
    ss>>Num1>>punto>>Num2>>punto>>Num3>>punto>>Num4>>dospuntos;
    string IP {Num1 + punto + Num2 + punto + Num3 + punto + Num4}; 
    return IP; 
}