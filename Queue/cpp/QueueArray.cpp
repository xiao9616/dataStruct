//
// Created by user on 2019/9/18.
//

#include "QueueArray.h"

QueueArray::QueueArray(int size) : size(size) {
    queue = new int[size];
    first = last = -1;
}

QueueArray::~QueueArray() {

}

void QueueArray::clear() {

}

bool QueueArray::isEmpty() {
    return false;
}

void QueueArray::enqueue(int val) {

}

int QueueArray::dequeue() {
    return 0;
}

int QueueArray::firstVal() {
    if (first != -1) {
        return queue[first];
    } else {
        return 
    }

}

bool QueueArray::isFull() {
    return (first == 0 && last == size - 1) || first == last + 1;
}
