#include "MyLinkedlist.h"
//N(1)
MyLinkedlist::~MyLinkedlist(){
    while(head != nullptr){
        deleteFirst(); 
    }
}

MyLinkedlist::MyLinkedlist(){
    this->head=this->tail = nullptr; 
}
//N(1)
void MyLinkedlist::deleteFirst(){
    ListaEnlazada* temp = head;
    this->head = this->head->Next;  
    delete temp; 
    Size--; 
}

string MyLinkedlist::regresarTodo(){
    return head->RegresarTodo(); 
}
//N(1)

void MyLinkedlist::insert(string linea){
    ListaEnlazada* nuevo = new ListaEnlazada(linea);
    if (head == nullptr) {
        head = tail = nuevo;
    } else {
        tail->Next = nuevo;
        tail = nuevo;
    }
    Size++;
}

bool MyLinkedlist::isEmpty(){
    if(Size == 0){
        return true; 
    }else{
        return false; 
    }
}
//N(1)
bool MyLinkedlist::esMenoroIgual(ListaEnlazada* A, ListaEnlazada* B){
    
    if(A->Num1 < B->Num1){
        return true;
    }else if(A->Num1 > B->Num1){
        return false;
    }

    else if(A->Num2 < B->Num2){
        return true;
    }else if(A->Num2 > B->Num2){
        return false;
    }

    else if(A->Num3 < B->Num3){
        return true;
    }else if(A->Num3 > B->Num3){
        return false;
    }

    else if(A->Num4 < B->Num4){
        return true;
    }else if(A->Num4 > B->Num4){
        return false;
    }

    else if(A->Puerto < B->Puerto){
        return true;
    }else if(A->Puerto >= B->Puerto){
        return false;
    }

    return false; 
}

void MyLinkedlist::mezcla(int inicio, int final, int central){
    MyLinkedlist* NuevaListaizquierda = new MyLinkedlist;
    MyLinkedlist* NuevaListaderecha = new MyLinkedlist;
    MyLinkedlist* NuevaListaFinal = new MyLinkedlist;

    int contador {0};
    ListaEnlazada* current = this->head; 

    while(contador < inicio){
        current = current->Next; 
        contador++;
    }
    ListaEnlazada* current2 = current; 
    
    while(contador <= central){
        NuevaListaizquierda->insert(current->RegresarTodo());
        current = current->Next; 
        contador++; 
    }

    while(contador <= final){
        NuevaListaderecha->insert(current->RegresarTodo());
        current = current->Next; 
        contador++;
    }

    //Hacer comparacion
    while(!NuevaListaderecha->isEmpty() && !NuevaListaizquierda->isEmpty()){
        if(esMenoroIgual(NuevaListaderecha->head, NuevaListaizquierda->head)){
            NuevaListaFinal->insert(NuevaListaderecha->head->RegresarTodo());
            NuevaListaderecha->deleteFirst();
        }else{
            NuevaListaFinal->insert(NuevaListaizquierda->head->RegresarTodo());
            NuevaListaizquierda->deleteFirst(); 
        }
    }

    while(!NuevaListaderecha->isEmpty()){
        NuevaListaFinal->insert(NuevaListaderecha->head->RegresarTodo());
        NuevaListaderecha->deleteFirst();  
    }

    while(!NuevaListaizquierda->isEmpty()){
        NuevaListaFinal->insert(NuevaListaizquierda->head->RegresarTodo());
        NuevaListaizquierda->deleteFirst();  
    }
    
    ListaEnlazada* current3 = NuevaListaFinal->head; 
    //Pasar todos los datos
    for(int i {inicio}; i <= final; i++){
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
    delete NuevaListaderecha; 
    delete NuevaListaFinal; 
    delete NuevaListaizquierda; 
}



void MyLinkedlist::mergeSort(){
    mergeSort(0, this->Size-1); 
}

void MyLinkedlist::mergeSort(int inicio, int final){
    if(inicio<final){
        int central {(inicio+final)/2}; 
        mergeSort(inicio, central);
        mergeSort(central+1, final);
        mezcla(inicio,final,central); 
    }
}
