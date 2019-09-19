//
// Created by user on 2019/9/19.
//

#ifndef CPP_BINARYSEARCHTREE_H
#define CPP_BINARYSEARCHTREE_H

#include "BinaryTreeNode.h"
#include <queue>

using namespace std;
class BinarySearchTree {
private:
    BinaryTreeNode *root;
public:
    BinarySearchTree();

    virtual ~BinarySearchTree();

    void clear(BinaryTreeNode *root);

    void insert(int val);

    void breadSearch();

    void deepSearch();

    void showNode(BinaryTreeNode *p);

};


#endif //CPP_BINARYSEARCHTREE_H
