//
// Created by user on 2019/9/18.
//

#ifndef CPP_LIST_H
#define CPP_LIST_H

#include <iostream>

using namespace std;
class ListNode{
public:
    ListNode(int val, ListNode *next);
    int val;
    ListNode *next;
};

class List {
private:
    ListNode *head, *tail;
public:
    List();

    virtual ~List();

    void add2head(int val);

    void add2tail(int val);

    int deleteFromHead();

    int deleteFromTail();

    void deleteNode(int val);

    bool isEmpty();

    bool isExist(int val);

    bool showList();
};


#endif //CPP_LIST_H
