//
// Created by user on 2019/9/21.
//

#ifndef CPP_BTREE_H
#define CPP_BTREE_H

#include "BTreeNode.h"
#include <map>
#include <iostream>

using namespace std;

class BTree {
protected:
    BTreeNode *root;
    int k;
    int minKey, maxKey;
    int nSize;

    void maintainAfterInsert(BTreeNode *);

    void maintainAfterErase(BTreeNode *);

    void mergeNode(BTreeNode *left, BTreeNode *right, int data, bool flag);

    void deleteNode(BTreeNode *p);

    void print(BTreeNode *);

    BTreeNode *splitLeftNode(BTreeNode *, int);

    BTreeNode *splitRightNode(BTreeNode *, int);

    BTreeNode *findBrotherNode(BTreeNode *, int &, bool flag);

    BTreeNode *findNode(int);

    int getLen(int);

    void getDFS(BTreeNode *p, int d, int *dep, int *tab, map<int, int> &map, int &cnt);

public:

    BTree();

    BTree(int k);

    virtual ~BTree();

    bool insert(int data);

    bool erase(int key);

    void printRoot();

    void printArray();

    void printTree();

    void printWholeTree();

    BTreeNode *findNextNode(BTreeNode *p, int, int &);

    BTreeNode *findPreNode(BTreeNode *p, int, int &);

    int size();

    int height();

    BTreeNode *getRoot();


};



#endif //CPP_BTREE_H
