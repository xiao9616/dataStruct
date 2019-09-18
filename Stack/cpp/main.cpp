#include <iostream>
#include "StackVector.h"
#include "StackList.h"
using namespace std;
int main() {
    StackVector *stackVector = new StackVector();
    stackVector->push(1);
    stackVector->push(2);
    cout<<stackVector->pop()<<endl;
    cout<<stackVector->top()<<endl;
    if(!stackVector->isEmpty()){
        stackVector->clear();
    }

    StackList *stackList = new StackList();
    stackList->push(3);
    stackList->push(4);
    cout << stackList->pop() << endl;
    cout << stackList->top() << endl;
    if (!stackList->isEmpty()) {
        stackList->clear();
    }
    return 0;
}