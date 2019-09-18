//
// Created by user on 2019/9/18.
//

#include "StackVector.h"

void StackVector::clear() {
    stack.clear();
}

bool StackVector::isEmpty() {
    return stack.empty();
}

void StackVector::push(int val) {
    stack.push_back(val);
}

int StackVector::pop() {
    int val = stack.back();
    stack.pop_back();
    return val;
}

StackVector::~StackVector() {

}

int StackVector::top() {
    return stack.back();
}

StackVector::StackVector() {}
