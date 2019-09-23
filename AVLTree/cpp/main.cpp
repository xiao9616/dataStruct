#include <iostream>
#include "AVLTree.h"
#include "AVLTreeNode.h"
using namespace std;
int main() {
    AVLTree<long long> tree;
    tree.insert(2);
    tree.display();
    return 0;
}