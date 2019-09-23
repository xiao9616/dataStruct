//
// Created by user on 2019/9/21.
//

#include "AVLTreeNode.h"

template<typename T>
AVLTreeNode<T>::AVLTreeNode(const T value) {
    count = 1;
    height = 1;
    left = nullptr;
    right = nullptr;
}

template<typename T>
AVLTreeNode<T>::~AVLTreeNode() {

}

template<typename T>
void AVLTreeNode<T>::updateValues() {
    count = (left != nullptr ? left->count : 0) + (right != nullptr ? right->count : 0);
    height = max(left != nullptr ? left->height : 0, right != nullptr ? right->height : 0);
}

template<typename T>
int AVLTreeNode<T>::balanceFactor() {
    return (left != nullptr ? left->height : 0) - (right != nullptr ? right->height : 0);
}

template<typename T>
AVLTreeNode<T> *AVLTreeNode<T>::left_rotate() {
    AVLTreeNode *R = right;
    right = right->left;
    R->left = this;
    this->updateValues();
    R->updateValues();
    return R;
}

template<typename T>
AVLTreeNode<T> *AVLTreeNode<T>::right_rotate() {
    AVLTreeNode *L = left;
    left = left->right;
    L->right = this;
    this->updateValues();
    L->updateValues();
    return L;
}
