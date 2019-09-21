//
// Created by user on 2019/9/21.
//

#ifndef CPP_AVLTREENODE_H
#define CPP_AVLTREENODE_H

#include <string>
#include <algorithm>

using namespace std;
template <typename T>
class AVLTreeNode {
public:
    AVLTreeNode *left;
    AVLTreeNode *right;
    const T value;

    int count;//节点子树包含多少节点
    int height;
public:
    AVLTreeNode(const T value);

    virtual ~AVLTreeNode();

    void updateValues();

    int balanceFactor();

    AVLTreeNode<T> *left_rotate();

    AVLTreeNode<T> *right_rotate();

};


#endif //CPP_AVLTREENODE_H
