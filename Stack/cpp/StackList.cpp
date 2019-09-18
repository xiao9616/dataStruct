//
// Created by user on 2019/9/18.
//

#include "StackList.h"

StackList::StackList() {}

StackList::~StackList() {

}

void StackList::clear() {
    stack.clear();
}

bool StackList::isEmpty() {
    return stack.empty();
}

void StackList::push(int val) {
    stack.push_back(val);
}

int StackList::pop() {
    int val = stack.back();
    stack.pop_back();
    return val;
}

int StackList::top() {
    return stack.back();
}
