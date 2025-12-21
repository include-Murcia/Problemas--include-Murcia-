#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T>
class BSNode{
    public:

    T elemento;
    BSNode<T>* left;
    BSNode<T>* right;

    long long maxSubtree; //Elemento máximo del subarbor generado por el nodo, solo es útil en un árbol de intervalos


    BSNode(const T& e): elemento(e),left(nullptr),right(nullptr),maxSubtree(e.max) {} 

};


#endif
