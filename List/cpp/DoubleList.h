//
// Created by user on 2019/9/18.
//

#ifndef CPP_DOUBLELIST_H
#define CPP_DOUBLELIST_H

#include <iostream>
#include <list>
using namespace std;

class DListNode {
public:
    DListNode *prev, *next;
    int val;

    DListNode(DListNode *prev = nullptr, DListNode *next = nullptr, int val = 0);

    virtual ~DListNode();
};

class DoubleList {
private:
    DListNode *head, *tail;
public:
    DoubleList(DListNode *head = nullptr, DListNode *tail = nullptr);

    virtual ~DoubleList();

    void add2head(int val);

    void add2tail(int val);

    int deleteFromHead();

    int deleteFromTail();

    void deleteNode(int val);

    bool isEmpty();

    bool isExist(int val);

    bool showList();

};


#endif //CPP_DOUBLELIST_H
