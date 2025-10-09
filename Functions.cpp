#include "Functions.h"

//O(n)
void CargarDocumento(MyLinkedlist* &Lista){
    ifstream archivo("bitacora.txt"); 
    string linea; 
    while(getline(archivo, linea)){
        Lista->Insert(linea);
    }

}
void CreadorVariablesBusq(string linea, int &Num1, int & Num2, int &Num3, int &Num4, int &Puerto){
    stringstream ss(linea);
    char punto; 
    ss>>Num1>>punto>>Num2>>punto>>Num3>>punto>>Num4>>Puerto; 
}
//O(1)
int SacarPrimerNumero(string linea){
    stringstream ss(linea);
    int numero; 
    ss>> numero; 
    return numero; 
}

bool CompararNumeros(ListaEnlazada* Lista, int Num1, int Num2, int Num3, int Num4, int Puerto ){
    if(Lista->Num1 < Num1){
    return true; 
    }else if(Lista->Num1 > Num1){
        return false; 
    }

    if(Lista->Num2 < Num2){
        return true; 
    }else if(Lista->Num2 > Num2){
        return false; 
    }

    if(Lista->Num3 < Num3){
        return true; 
    }else if(Lista->Num3 > Num3){
        return false; 
    }

    if(Lista->Num4 < Num4){
        return true; 
    }else if(Lista->Num4 > Num4){
        return false;
    }

    if(Lista->Puerto < Puerto){
        return true; 
    }
    return false; 
}
int HacerBusq(MyLinkedlist* Lista, int Num1, int Num2, int Num3, int Num4, int Puerto){
    int contador {0}; 
    ListaEnlazada* current = Lista->Head; 
    while(current != nullptr && !CompararNumeros(current,Num1, Num2, Num3, Num4, Puerto)){
        contador++; 
        current = current->Next; 
    }
    return contador; 
}
//Agregar en las verificaciones los demas numeros
void EntregarDocumentoBusq(MyLinkedlist* Lista, string BusquedaInicial, string BusquedaFinal, string Nombre){
    ofstream archivo(Nombre); 
    ListaEnlazada* current = Lista->Head; 
    int In1, In2, In3, In4, Iport, Fn1, Fn2, Fn3, Fn4, Fport; 
    CreadorVariablesBusq(BusquedaInicial,In1,In2, In3, In4, Iport); 
    CreadorVariablesBusq(BusquedaFinal, Fn1, Fn2, Fn3, Fn4, Fport);
    int inicio {0}; 
    int final {0};
    inicio = HacerBusq(Lista, In1, In2, In3, In4, Iport); 
    final = HacerBusq(Lista, Fn1, Fn2, Fn3, Fn4, Fport);
    final = final - inicio; 
    for(int i {0}; i<inicio&& current != nullptr; i++){
        current = current->Next; 
    } 
    for(int i {inicio}; i<final && current != nullptr; i++){
        archivo<<current->RegresarTodo()<<endl;
        current = current->Next; 
    }

}
//O(1)
string CrearNombre(int contador){
    string Contador {to_string(contador)};
    return "Salida"+Contador+"-Eq5";
}
//O(n)
void EntregarDocumento(MyLinkedlist* Lista){
    ofstream archivo("bitacoraOrdenadaIp-Eq5"); 
    string linea; 
    ListaEnlazada* Current = Lista->Head; 
    while(Current != nullptr){
        archivo<<Current->RegresarTodo()<<endl;        
        Current = Current->Next; 
    }
}
//O(n)
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
        Nombre = CrearNombre(contador+1); 
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
        return true;
    }
}