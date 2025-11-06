#include "MyBST.h"



MyBST::MyBST(){
    this->root = nullptr; 
}




void MyBST::insert(string linea, int contador){
    if(this->root == nullptr){
        root = new MyNodeBST(linea, contador);
        return;
    }
    MyNodeBST* current = root; 
    while(current != nullptr){
        if(current->repeticiones < contador){
            if(current->left == nullptr){
                current->left = new MyNodeBST(linea, contador);
                return;
            }
            current = current->left;     
        }else if(current->repeticiones > contador){
            if(current->right == nullptr){
                current->right = new MyNodeBST(linea,contador);
                return; 
            }
            current = current->right;
        }else if(current->repeticiones == contador){
            if(current->right == nullptr){
                current->right = new MyNodeBST(linea, contador);
            }
            current = current->right; 
        }
    }
}