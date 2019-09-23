//
// Created by user on 2019/9/23.
//

#ifndef CPP_AVLTREE_H
#define CPP_AVLTREE_H

#include "AVLTreeNode.h"
#include <iostream>

using namespace std;

template<typename T>
class AVLTree {
private:
    int _size;
    AVLTreeNode<T> *root;

    void balance(vector<AVLTreeNode<T> **> path);

    void display(AVLTreeNode<T> *cur, int depth = 0, int state = 0);

public:
    AVLTree();

    virtual ~AVLTree();

    void erase(T value);

    void insert(T value);

    void clear();

    bool empty() const;

    int size() const;

    int find(T value) const;

    int lower_bound(T value) const;

    int upper_bound(T value) const;

    void display();

    const T &operator[](size_t idx) const;

    const T &find_max() const;

    const T &find_min() const;
};


#endif //CPP_AVLTREE_H
