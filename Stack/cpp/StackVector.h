//
// Created by user on 2019/9/18.
//

#ifndef CPP_STACKVECTOR_H
#define CPP_STACKVECTOR_H

#include <vector>

using namespace std;
class StackVector {
private:
    vector<int> stack;
public:
    void clear();

    bool isEmpty();

    void push(int val);

    int pop();

    StackVector();

    int top();

    virtual ~StackVector();
};


#endif //CPP_STACKVECTOR_H
