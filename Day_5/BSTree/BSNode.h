#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T>
class BSNode{
    public:

    T elemento;
    BSNode<T>* left;
    BSNode<T>* right;
    long long maxSubtree;


    BSNode(const T& e): elemento(e),left(nullptr),right(nullptr),maxSubtree(e.max) {} 

};

#endif