//
// Created by user on 2019/9/23.
//

#include <stack>
#include "AVLTree.h"

template<typename T>
AVLTree<T>::AVLTree() {
    root = nullptr;
    _size = 0;
}

template<typename T>
AVLTree<T>::~AVLTree() {
    clear();
}

template<typename T>
void AVLTree<T>::balance(vector<AVLTreeNode<T> **> path) {
    reverse(path.begin(), path.end());
    for (AVLTreeNode<T> *indirect:path) {
        (*indirect).updateValues();
        //LL
        if (((*indirect)->balanceFactor() >= 2) and (*indirect).left->balanceFactor() >= 0) {
            *indirect = (*indirect).right_rotate();
        }
        //LR
        else if ((*indirect).balanceFactor() >= 2) {
            (*indirect)->left = (*indirect).leftleft->left_rotate();
            *indirect = (*indirect).right_rotate();
        }
            //RR
        else if ((*indirect).balanceFactor() <= -2 and (*indirect).right->balanceFactor() <= 0) {
            *indirect = (*indirect).left_rotate();
        }
            //RL
        else if ((*indirect).balanceFactor() <= -2) {
            (*indirect).right = ((*indirect).right)->right_rotate();
            *indirect = (*indirect).left_rotate();
        }

    }
}

template<typename T>
void AVLTree<T>::display(AVLTreeNode<T> *cur, int depth, int state) {
    if (cur->left) {
        display(cur->left, depth + 1, 1);
    }
    for (int i = 0; i < depth; ++i) {
        cout << "      " << endl;
    }
    if (state == 1) {
        cout << "/";
    }
    if (state == 2) {
        cout << "\"";
    }
    cout << "[" << cur->value << "]-(" << cur->height << ")" << endl;
    if (cur->right) {
        display(cur->right, depth + 1, 2);
    }
}

template<typename T>
void AVLTree<T>::erase(T value) {

}

template<typename T>
void AVLTree<T>::insert(T value) {
    AVLTreeNode<T> **indirect = root;
    vector<AVLTreeNode<T> **> path;
    while (*indirect != nullptr) {
        path.push_back(indirect);
        if ((*indirect)->value > value) {
            indirect = &((*indirect)->left);
        } else {
            indirect = &((*indirect)->right);
        }
    }
    *indirect = new AVLTreeNode<T>(value);
    path.push_back(indirect);
    balance(path);
    ++_size;
}

template<typename T>
void AVLTree<T>::clear() {
    stack<AVLTreeNode<T> *> stack;
    if (root != nullptr) {
        stack.push(root);
    }
    while (!stack.empty()) {
        AVLTreeNode<T> *node = stack.top();
        stack.pop();
        if (node->left != nullptr) {
            stack.push(node->left);
        }
        if (node->right != nullptr) {
            stack.push(node->right);
        }
        _size--;
        delete node;
    }
    root = nullptr;
}

template<typename T>
bool AVLTree<T>::empty() const {
    return 0 == _size;
}

template<typename T>
int AVLTree<T>::size() const {
    return _size;
}

template<typename T>
int AVLTree<T>::find(T value) const {
    return 0;
}

template<typename T>
int AVLTree<T>::lower_bound(T value) const {
    return 0;
}

template<typename T>
int AVLTree<T>::upper_bound(T value) const {
    return 0;
}

template<typename T>
void AVLTree<T>::display() {
    cout << endl;
    if (root != nullptr) {
        display(root);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}

template<typename T>
const T &AVLTree<T>::operator[](size_t idx) const {
    AVLTreeNode<T> *cur = root;
    int left_num = cur->left != nullptr ? cur->left->count : 0;
    while (left_num != idx) {
        if (left_num < idx) {
            idx -= left_num + 1;
            cur = cur->right;
            left_num = cur->left != nullptr ? cur->left->count : 0;
        } else {
            cur = cur->left;
            left_num = cur->left != nullptr ? cur->left->count : 0;
        }
    }
    return cur->value;
}

template<typename T>
const T &AVLTree<T>::find_max() const {
    AVLTreeNode<T> *cur = root;
    while (cur->right != nullptr) {
        cur = cur->right;
    }
    return cur->value;
}

template<typename T>
const T &AVLTree<T>::find_min() const {
    AVLTreeNode<T> *cur = root;
    while (cur->left != nullptr) {
        cur = cur->left;
    }
    return cur->value;
}
