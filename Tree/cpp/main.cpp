#include <iostream>
#include "BinarySearchTree.h"
int main() {
    BinarySearchTree *binarySearchTree=new BinarySearchTree();
    binarySearchTree->insert(2);
    binarySearchTree->insert(1);
    binarySearchTree->insert(3);
    binarySearchTree->breadSearch();
    binarySearchTree->deepSearch();
    return 0;
}