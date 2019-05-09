#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        vector<Node<T>*> nodes;
        int index;

    public:
        Iterator() {
            this->current=nullptr;
            this->index=-1;
        }

        Iterator(Node<T> *node) {
            complete_vector(node);
        }

        Iterator<T> operator=(Iterator<T> other) {          
            return (this->current=other->current);
        }

        bool operator!=(Iterator<T> other) {
            return (this->current!=other->current);
        }

        Iterator<T> operator++() {
            this->index++;
            this->current=this->nodes[this->index];
        }

        Iterator<T> operator--() {
            this->index--;
            this->current=this->nodes[this->index];
        }

        T operator*() {
            return (this->current->data);
        }
        void complete_vector(Node<T>* node){
            if(node->left!=nullptr){
                node=node->left;
                        complete_vector(node);
            }

            (this->nodes).push_back(node);

            if(t_node->right!=nullptr){
                node=t_node->right;
                complete_vector(node);
            }     
            this->curret=(this->nodes)[0];
            this->index++;        
        }

};

#endif
