//
// Created by user on 2019/9/18.
//

#ifndef CPP_STACKLIST_H
#define CPP_STACKLIST_H

#include <list>

using namespace std;

class StackList {
private:
    list<int> stack;
public:
    void clear();

    bool isEmpty();

    void push(int val);

    virtual ~StackList();

    StackList();

    int pop();

    int top();
};


#endif //CPP_STACKLIST_H
