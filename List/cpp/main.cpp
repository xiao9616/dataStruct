#include <iostream>
#include "List.h"
#include "DoubleList.h"

using namespace std;

int main() {
    List *l1 = new List();
    l1->add2tail(1);
    l1->add2tail(2);
    l1->add2head(3);
    l1->showList();
    cout << l1->deleteFromTail() << endl;
    l1->showList();
    cout << l1->deleteFromHead() << endl;
    l1->showList();
    cout << l1->isExist(1) << endl;
    l1->deleteNode(1);
    l1->showList();

    DoubleList *l2 = new DoubleList();
    l2->add2tail(7);
    l2->add2tail(8);
    l2->add2tail(9);
    l2->add2head(6);
    l2->showList();
    l2->deleteFromHead();
    l2->showList();
    l2->deleteFromTail();
    l2->showList();
    cout << l2->isExist(8) << endl;
    cout << l2->isEmpty() << endl;
    l2->deleteNode(8);
    l2->showList();

    l2->deleteNode(7);
    l2->showList();
    return 0;
}