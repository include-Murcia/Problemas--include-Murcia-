#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include<iostream>
#include "BSNode.h"
#include "../Day_5/Interval.h"
template <typename T>
class BSTree {
private:
    BSNode<T>* root;
    int nelementos;

    static long long max3(long long a, long long b, long long c) { //Funcion que devuelve el másimo de tres valores, en esta clase la usaremos para saber cual es el maxSubarbol del nodo en el que estemos
        return std::max(a, std::max(b, c));
    }


    BSNode<T>* insert(BSNode<T>* n, const T& e) {
        if (!n) { //si n = nulo
            nelementos++;
            return new BSNode<T>(e);
        }
        if (e < n->elemento) //si es menor vas a la izquierda
            n->left = insert(n->left, e);
        else if (e > n->elemento) //si es mayor a la derecha
            n->right = insert(n->right, e);
        
        long long leftMax  = n->left  ? n->left->maxSubtree  : LLONG_MIN; //Si el nodo a la izquierda es no nulo, devuelve el máximo de la izquierda, sino devuelve la constante LLONG_MIN, que es el minimo del long long
        long long rightMax = n->right ? n->right->maxSubtree : LLONG_MIN; //Si el nodo a la derecha es no nulo, devuelve el máximo de la derecha, sino devuelve la constante LLONG_MIN, que es el minimo del long long
        n->maxSubtree = max3(n->elemento.max, leftMax, rightMax); //El maxSubtree del nodo actual será el mayor entre el máximo del rango, el máximo de la derecha y el de la izquierda

        return n;
    }

    void delete_cascade(BSNode<T>* n) {
        if (!n) return;
        delete_cascade(n->left);
        delete_cascade(n->right);
        delete n;
    }

    bool searchRangeRecursive(BSNode<T>* n, long long num) const {

        while (n) { //mientras el nodo sea no nulo
            Interval I = n->elemento;
            if (num >= I.min && num <= I.max) return true; //si el numero esta dentro del intervalo devuelve true

            long long leftMax = n->left ? n->left->maxSubtree : LLONG_MIN; //sino comprueba si está en el subarbol correcto

            if (n->left && num <= leftMax) { //se mueve acorde a lo anterior
                n = n->left;
            } else {
                n = n->right;
            }
        }
        return false;
    }
    void print_inorder(BSNode<T>* n){
        if (n != nullptr){
            print_inorder(n->left);
            std::cout<<n->elemento;
            print_inorder(n->right);
        }
    }
public:
    BSTree() : root(nullptr), nelementos(0) {}

    void insert(const T& e) {
        root = insert(root, e);
    }

    bool searchRange(long long num) const {
        return searchRangeRecursive(root, num);
    }
    void print(){
        print_inorder(root);
    }
    ~BSTree() {
        delete_cascade(root);
    }
};


#endif
