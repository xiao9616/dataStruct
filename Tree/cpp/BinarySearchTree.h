//
// Created by user on 2019/9/19.
//

#ifndef CPP_BINARYSEARCHTREE_H
#define CPP_BINARYSEARCHTREE_H

#include "BinaryTreeNode.h"
#include <queue>
#include <stack>

using namespace std;

class BinarySearchTree {
private:
    BinaryTreeNode *root;

    void preOrderSearch(BinaryTreeNode *root);

    void midOrderSearch(BinaryTreeNode *root);

    void lastOrderSearch(BinaryTreeNode *root);

public:
    BinarySearchTree();

    virtual ~BinarySearchTree();

    void showNode(BinaryTreeNode *p);

    void insert(int val);

    void breadSearch();

    void preOrder();

    void midOrder();

    void lastOrder();

    void preOrderByStack();

    void midOrderByStack();

    void lastOrderByStack();

    BinaryTreeNode *search(int val);

    void deleteByMerge(int val);

    void deleteByCopy(int val);
};


#endif //CPP_BINARYSEARCHTREE_H
