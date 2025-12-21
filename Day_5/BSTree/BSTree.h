#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include<iostream>
#include "BSNode.h"

template <typename T>
class BSTree {
private:
    BSNode<T>* root;
    int nelementos;

    static long long max3(long long a, long long b, long long c) {
        return std::max(a, std::max(b, c));
    }


    BSNode<T>* insert(BSNode<T>* n, const T& e) {
        if (!n) {
            nelementos++;
            return new BSNode<T>(e);
        }
        if (e < n->elemento)
            n->left = insert(n->left, e);
        else if (e > n->elemento)
            n->right = insert(n->right, e);

        long long leftMax  = n->left  ? n->left->maxSubtree  : LLONG_MIN;
        long long rightMax = n->right ? n->right->maxSubtree : LLONG_MIN;
        n->maxSubtree = max3(n->elemento.max, leftMax, rightMax);

        return n;
    }

    void delete_cascade(BSNode<T>* n) {
        if (!n) return;
        delete_cascade(n->left);
        delete_cascade(n->right);
        delete n;
    }

    bool searchRangeRecursive(BSNode<T>* n, long long num) const {

        while (n) {
            
            const auto& I = n->elemento;
            if (num >= I.min && num <= I.max) return true;

            long long leftMax = n->left ? n->left->maxSubtree : LLONG_MIN;

            if (n->left && num <= leftMax) {
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