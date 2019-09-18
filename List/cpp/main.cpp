#include <iostream>
#include "List.h"

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
}