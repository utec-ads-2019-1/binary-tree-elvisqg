#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    private:
        Node<T> *root;
        unsigned int BSTree_size;

    public:
        BSTree() : root(nullptr) {};

        bool find(T data) { 
            
            Node <T>* t_node= this->root;
            
            if(root==nullptr)
                return false;

            while(1){

                if(t_node->data==data)
                    return true;
   
                if(n_node->data > data)
                    t_node=t_node->left;
                
                else
                    t_node=t_node->right;
                
            }
            return false;
        } 

        bool insert(T data) {
            
            if(find(data))
                return false;
            
            if(root==nullptr){
                this->root=new Node<T>;
                this->root->data=data;
                BSTree_size++;
             }   
            else{
                Node <T>* t_node= this->root;
                int flag=0;
                while(1){
                    
                    if(t_node->data > data){
                       
                        if(t_node->left!=nullptr)
                            t_node=t_node->left;
                        else{
                            flag=1;            
                            break;
                        }    
                    }
                    else{

                        if(t_node->right!=nullptr)
                            t_node=t_node->right;
                        else
                            break;    
                    }
                }
                    Node<T>* new_node=new Node<T>;
                    new_node->data=data;
                    new_node->left=nullptr;
                    new_node->right=nullptr;
                    BSTree_size++;

                    if(flag=1)
                        t_node->left=new_node;
                    else
                        t_node->right=new_node;
            }
            return true;
        }

        bool remove(T data) {
            if(find(data)==false)
                return false;
            
        }

        unsigned int size() {

            return BSTree_size;
        }

        void print_nodes(int case, Node<T>* t_node){
            switch(case){

                case 1:
                    cout<<t_node->data<<" ";  
                    if(t_node->left!=nullptr){
                        t_node=t_node->left;
                        print_nodes(1,t_node);
                    }
                    if(t_node->right!=nullptr){
                        t_node=t_node->right;
                        print_nodes(1,t_node);
                    }
                    break;

                case 2:
                    if(t_node->left!=nullptr){
                        t_node=t_node->left;
                        print_nodes(1,t_node);
                    }

                    cout<<t_node->data<<" ";

                    if(t_node->right!=nullptr){
                        t_node=t_node->right;
                        print_nodes(1,t_node);
                    }
                    break;

                case 3:
                    if(t_node->left!=nullptr){
                        t_node=t_node->left;
                        print_nodes(1,t_node);
                    }

                    if(t_node->right!=nullptr){
                        t_node=t_node->right;
                        print_nodes(1,t_node);
                    }
                    cout<<t_node->data<<" ";
                    break;

                default:
                    cout<<"invalid option";  
            }

        }

        void traversePreOrder() {
            if(root==nullptr)
                cout<<"No elements in this BSTree";
            else
                print_nodes(1,root);
        }

        void traverseInOrder() {
            if(root==nullptr)
                cout<<"No elements in this BSTree";
            else
                print_nodes(2,root);
        }

        void traversePostOrder() {
            if(root==nullptr)
                cout<<"No elements in this BSTree";
            else
                print_nodes(3,root);
        }

        Iterator<T> begin() {
            // TODO
        }

        Iterator<T> end() { 
            // TODO
        }

        void delete_Bstree(Node<T>* t_node){

                if(t_node->left!=nullptr)
                delete_Bstree(t_node->left);
                if(t_node->right!=nullptr)
                delete_Bstree(t_node->right);
                delete t_node;
        }

        ~BSTree() {
            delete_Bstree(root);
        }
            
};

#endif
