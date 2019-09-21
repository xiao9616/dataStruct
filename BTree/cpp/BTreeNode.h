//
// Created by user on 2019/9/21.
//

#ifndef CPP_BTREENODE_H
#define CPP_BTREENODE_H

#include <list>

using namespace std;

class BTreeNode {
public:
    BTreeNode();

    BTreeNode(int data);

    virtual ~BTreeNode();

    bool isLeaf();

    bool haskey(int key);

    bool replace(int oldKey, int newKey);

    bool eraseKey(int key);

    bool eraseChild(BTreeNode *child);

    void updateChild();

    void insertKey(int data, BTreeNode *child1, BTreeNode *child2);

    void print();

    BTreeNode *next(int key);

    int getKey(int pos);

    int size();


public:
    list<int> keys;
    list<BTreeNode *> childs;
    BTreeNode *father;

};


#endif //CPP_BTREENODE_H
