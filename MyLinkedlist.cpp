#include "MyLinkedlist.h"
//N(1)
MyLinkedlist::MyLinkedlist(){
    this->Head=this->Tail = nullptr; 
}
//N(1)
void MyLinkedlist::DeleteFirst(){
    ListaEnlazada* temp = Head;
    this->Head = this->Head->Next;  
    delete temp; 
}

string MyLinkedlist::RegresarTodo(){
    return Head->RegresarTodo(); 
}
//N(1)
void MyLinkedlist::Insert(string linea){
    ListaEnlazada* Nuevo = new ListaEnlazada(linea, this->Head);
    if(isEmpty()){
        Head = Tail = Nuevo; 
    }else{
        Tail->Next = Nuevo; 
        Tail = Nuevo; 
    }
}
bool MyLinkedlist::isEmpty(){
    if(Size == 0){
        return true; 
    }else{
        return false; 
    }
}

void MyLinkedlist::Mezcla(int inicio, int final, int central){
    MyLinkedlist* NuevaListaizquierda = new MyLinkedlist;
    MyLinkedlist* NuevaListaderecha = new MyLinkedlist;
    MyLinkedlist* NuevaListaFinal = new MyLinkedlist;

    int contador {0};
    ListaEnlazada* current = this->Head; 
    while(contador < inicio){
        current = current->Next; 
        contador++;
    }
    ListaEnlazada* current2 = current; 
    
    while(contador < central){
        NuevaListaizquierda->Insert(current->RegresarTodo());
        current = current->Next; 
        contador++; 
    }

    while(contador < final){
        NuevaListaderecha->Insert(current->RegresarTodo());
        current = current->Next; 
        contador++;
    }

    while(!NuevaListaderecha->isEmpty() && !NuevaListaizquierda->isEmpty()){
        //Verificacion de los numeros de la IP
        if((NuevaListaderecha->Head->Num1 <= NuevaListaizquierda->Head->Num1 )||  
            (NuevaListaderecha->Head->Num1 == NuevaListaizquierda->Head->Num1) && (NuevaListaderecha->Head->Num2 <= NuevaListaizquierda->Head->Num2) ||
                (NuevaListaderecha->Head->Num1 == NuevaListaizquierda->Head->Num1) && (NuevaListaderecha->Head->Num2 == NuevaListaizquierda->Head->Num2) && (NuevaListaderecha->Head->Num3 <= NuevaListaizquierda->Head->Num3)  ||
                    (NuevaListaderecha->Head->Num1 == NuevaListaizquierda->Head->Num1) && (NuevaListaderecha->Head->Num2 == NuevaListaizquierda->Head->Num2) && (NuevaListaderecha->Head->Num3 == NuevaListaizquierda->Head->Num3) && (NuevaListaderecha->Head->Num4 <= NuevaListaizquierda->Head->Num4) ||
                        (NuevaListaderecha->Head->Num1 == NuevaListaizquierda->Head->Num1) && (NuevaListaderecha->Head->Num2 == NuevaListaizquierda->Head->Num2) && (NuevaListaderecha->Head->Num3 == NuevaListaizquierda->Head->Num3) && (NuevaListaderecha->Head->Num4 == NuevaListaizquierda->Head->Num4) && (NuevaListaderecha->Head->Puerto <= NuevaListaizquierda->Head->Puerto)){
                            
                            NuevaListaFinal->Insert(NuevaListaderecha->Head->RegresarTodo()); 
                            NuevaListaderecha->DeleteFirst(); 

                        }else{
                            NuevaListaFinal->Insert(NuevaListaizquierda->Head->RegresarTodo()); 
                            NuevaListaizquierda->DeleteFirst(); 
                        }
    }

    while(!NuevaListaderecha->isEmpty()){
        NuevaListaFinal->Insert(NuevaListaderecha->Head->RegresarTodo());
        NuevaListaderecha->DeleteFirst();  
    }

    while(!NuevaListaizquierda->isEmpty()){
        NuevaListaFinal->Insert(NuevaListaizquierda->Head->RegresarTodo());
        NuevaListaizquierda->DeleteFirst();  
    }
    
    ListaEnlazada* current3 = NuevaListaFinal->Head; 
    //Pasar todos los datos
    for(int i {inicio}; i < final; i++){
        current2->Num1 = current3->Num1;
        current2->Num2 = current3->Num2;
        current2->Num3 = current3->Num3;
        current2->Num4 = current3->Num4;
        current2->Puerto = current3->Puerto;
        current2->Mes = current3->Mes;
        current2->Dia = current3->Dia;
        current2->Hora = current3->Hora;
        current2->IP = current3->IP;
        current2->Resto = current3->Resto;

        current2 = current2->Next; 
        current3 = current3->Next; 
    }

}



void MyLinkedlist::Mergesort(){
    Mergesort(0, this->Size-1); 
}

void MyLinkedlist::Mergesort(int inicio, int final){
    if(inicio<final){
        int central {(inicio+final)/2}; 
        Mergesort(inicio, central);
        Mergesort(central+1, final);
        Mezcla(inicio,final,central); 
    }
}
