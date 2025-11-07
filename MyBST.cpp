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
                return; 
            }
            current = current->right; 
        }
    }
}

//O(1)
void MyBST::inorder(int &num){
    MyNodeBST *current {root}; 
    if(num < 1){
        return;
    }
    inorder(current, num);
    
}

//O(n)
void MyBST::inorder(MyNodeBST *current, int &num){
    if(num < 1){
        return;
    }
    if(current->left != nullptr){
        inorder(current->left, num);
    }
    if(num > 0){
        num--; 
        cout<<"Numero de IP: "<<current->IP<<" Total de accesos: "<<current->repeticiones<<endl; 
    }


    if(current->right != nullptr){
        inorder(current->right, num);
    }

}