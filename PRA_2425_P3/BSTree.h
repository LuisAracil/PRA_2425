#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
private:
    BSNode<T>* root;
    int nelem;

    BSNode<T>* search(BSNode<T>* node, const T& e) const {
        if (!node) throw std::runtime_error("Element not found");
        if (e < node->elem) return search(node->left, e);
        if (e > node->elem) return search(node->right, e);
        return node;
    }

    BSNode<T>* insert(BSNode<T>* node, const T& e) {
        if (!node) return new BSNode<T>(e);
        if (e < node->elem) node->left = insert(node->left, e);
        else if (e > node->elem) node->right = insert(node->right, e);
        else throw std::runtime_error("Duplicate element");
        return node;
    }

    BSNode<T>* remove(BSNode<T>* node, const T& e) {
        if (!node) throw std::runtime_error("Element not found");
        if (e < node->elem) node->left = remove(node->left, e);
        else if (e > node->elem) node->right = remove(node->right, e);
        else {
            if (!node->left) return node->right;
            if (!node->right) return node->left;
            T maxVal = max(node->left);
            node->elem = maxVal;
            node->left = remove(node->left, maxVal);
        }
        return node;
    }

    T max(BSNode<T>* node) const {
        while (node->right) node = node->right;
        return node->elem;
    }

    void delete_cascade(BSNode<T>* node) {
        if (node) {
            delete_cascade(node->left);
            delete_cascade(node->right);
            delete node;
        }
    }

    void print_inorder(std::ostream& out, BSNode<T>* node) const {
        if (node) {
            print_inorder(out, node->left);
            out << node->elem << " ";
            print_inorder(out, node->right);
        }
    }

public:
    BSTree() : root(nullptr), nelem(0) {}

    ~BSTree() { delete_cascade(root); }

    void insert(const T& e) {
        root = insert(root, e);
        nelem++;
    }

    void remove(const T& e) {
        root = remove(root, e);
        nelem--;
    }

    T search(const T& e) const {
        return search(root, e)->elem;
    }

    int size() const { return nelem; }

    friend std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree) {
        tree.print_inorder(out, tree.root);
        return out;
    } 
    
};

#endif
