#include <iostream>
#include "QueueArray.h"

using namespace std;

int main() {
    QueueArray *queue = new QueueArray(100);
    queue->enqueue(10);
    queue->enqueue(20);
    cout << queue->dequeue() << endl
}