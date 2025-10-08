#include "Functions.h"

void CargarDocumento(MyLinkedlist* &Lista){
    ifstream archivo("bitacora.txt"); 
    string linea; 

    while(getline(archivo, linea)){
        Lista->Insert(linea);
    }
}

int SacarPrimerNumero(string linea){
    stringstream ss(linea);
    int numero; 
    ss>> numero; 
    return numero; 

}
//Agregar en las verificaciones los demas numeros
void EntregarDocumentoBusq(MyLinkedlist* Lista, string BusquedaInicial, string BusquedaFinal, string Nombre){
    ListaEnlazada* current = Lista->Head; 
    int NumeroInicial, NumeroFinal; 
    NumeroInicial = SacarPrimerNumero(BusquedaInicial);
    NumeroFinal = SacarPrimerNumero(BusquedaFinal);

    while(current->Num1 != NumeroInicial){
        Lista->DeleteFirst(); 
        current = Lista->Head; 
    }

    int contadorF {0};
    while(current->Num1 < NumeroFinal){
        current = current->Next; 
        contadorF++; 
    }
    current = Lista->Head; 
    ofstream archivo(Nombre); 
    for(int i {0}; i< contadorF; i++){
        archivo<<current->RegresarTodo()<<endl; 
    }
}
string CrearNombre(int contador){
    string Contador {to_string(contador)};
    return "Salida"+Contador+"-Eq5";
}

void EntregarDocumento(MyLinkedlist* Lista){
    ofstream archivo("bitacoraOrdenadaIp-Eq5"); 
    string linea; 
    while(Lista->Size>0){
        archivo<<Lista->RegresarTodo()<<endl;        
        Lista->DeleteFirst();
    }
}

bool Menu(MyLinkedlist* &Lista, int &contador){
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
        cin.ignore(); 
        getline(cin,BusquedaFinal);
        string Nombre;
        Nombre = CrearNombre(contador); 
        EntregarDocumentoBusq(Lista, BusquedaInicial, BusquedaFinal, Nombre); 
        contador++; 
        return true; 
    }  
    else if(opcion == 2){
        cout<<"Bye bye"<<endl; 
        return false;
    }
    else{
        cout<<"Opcion invalida"<<endl;
    }
}