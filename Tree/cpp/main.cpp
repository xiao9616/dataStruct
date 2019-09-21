#include <iostream>
#include "BinarySearchTree.h"
int main() {
    BinarySearchTree *binarySearchTree=new BinarySearchTree();
    binarySearchTree->insert(7);
    binarySearchTree->insert(5);
    binarySearchTree->insert(9);
    binarySearchTree->insert(4);
    binarySearchTree->insert(6);
    binarySearchTree->insert(8);
    binarySearchTree->insert(10);
    binarySearchTree->breadSearch();
    binarySearchTree->preOrder();
    binarySearchTree->preOrderByStack();
    binarySearchTree->midOrder();
    binarySearchTree->midOrderByStack();
    binarySearchTree->lastOrder();
    binarySearchTree->lastOrderByStack();
    cout << binarySearchTree->search(10) << endl;
    return 0;
}