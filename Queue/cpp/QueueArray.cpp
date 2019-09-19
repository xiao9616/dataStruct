//
// Created by user on 2019/9/18.
//

#include "QueueArray.h"

QueueArray::QueueArray(int size) : size(size) {
    queue = new int[size];
    first = last = -1;
}

QueueArray::~QueueArray() {
    delete queue;
}

void QueueArray::clear() {
    delete queue;
    queue = new int[size];
}

bool QueueArray::isEmpty() {
    return first == -1;
}

void QueueArray::enqueue(int val) {
    if (!isFull()) {
        if (last == size - 1 || last == -1) {
            queue[0] = val;
            last = 0;
            if (first == -1) {
                first = 0;
            }
        } else {
            queue[++last] = val;
        }
    } else {
        cout << "queue is full" << endl;
    }
}

int QueueArray::dequeue() {
    if (first != -1) {
        int val = queue[first];
        if (first == last) {
            first = last = -1;
        } else if (first = size - 1) {
            first = 0;
        } else {
            first++;
        }
        return val;
    } else {
        cout << "queue is empty" << endl;
    }
    return 0;

}

bool QueueArray::isFull() {
    return (first == 0 && last == size - 1) || first == last + 1;
}
