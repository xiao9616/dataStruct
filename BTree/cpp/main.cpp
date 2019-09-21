#include <iostream>
#include "BTree.h"

using namespace std;
int main() {
    BTree *bTree=new BTree();
    bTree->insert(12);
    bTree->insert(32);
    bTree->insert(23);
    bTree->insert(56);
    bTree->insert(89);
    bTree->printTree();
    cout << bTree->size();
}