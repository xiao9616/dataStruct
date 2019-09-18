//
// Created by user on 2019/9/18.
//

#ifndef CPP_QUEUEARRAY_H
#define CPP_QUEUEARRAY_H

using namespace std;
class QueueArray {
private:
    int first, last;
    int size;
    int *queue;
public:
    QueueArray(int size);

    void clear();

    bool isEmpty();

    bool isFull();

    void enqueue(int val);

    int dequeue();

    int firstVal();

    virtual ~QueueArray();

};


#endif //CPP_QUEUEARRAY_H
