//
// Created by user on 2019/9/21.
//

#include <queue>
#include <set>
#include "BTree.h"

BTree::BTree() {
    k = 3;
    nSize = 0;
    maxKey = k - 1;
    minKey = (k - 1) / 2;
    root = nullptr;
}

BTree::~BTree() {
    deleteNode(root);
}

void BTree::deleteNode(BTreeNode *p) {
    if (p == nullptr) {
        return;
    }
    for (auto &child : p->childs) {
        deleteNode(child);
    }
    delete p;
}

BTree::BTree(int k) : k(k) {
    nSize = 0;
    maxKey = k - 1;
    minKey = (k - 1) / 2;
    root = nullptr;
}

int BTree::size() {
    return nSize;
}

int BTree::height() {
    int i = 0;
    BTreeNode *p = root;
    while (nullptr != p) {
        p = *(p->childs.begin());
        ++i;
    }
    return i;
}

BTreeNode *BTree::getRoot() {
    return this->root;
}


bool BTree::insert(int data) {
    BTreeNode *p = root;
    if (root == nullptr) {
        root = new BTreeNode(data);
        ++nSize;
        return true;
    }
    while (!p->isLeaf()) {
        if (p->haskey(data)) {
            return false;
        }
        p = p->next(data);
    }
    if (p->haskey(data)) {
        return false;
    }
    p->insertKey(data, nullptr, nullptr);
    ++nSize;
    return true;
}

BTreeNode *BTree::findNode(int data) {
    BTreeNode *p = root;
    while (p != nullptr && !(p->haskey(data))) {
        p = p->next(data);
    }
    return p;
}

void BTree::print(BTreeNode *p) {
    if (p == nullptr) {
        return;
    }
    auto iter_key = p->keys.begin();
    auto iter_child = p->childs.begin();
    print(*iter_child);
    for (iter_child++; iter_child != p->childs.end(); ++iter_child, ++iter_key) {
        cout << *iter_key << ' ';
        print(*iter_child);
    }
}

void BTree::printRoot() {
    if (root == nullptr) {
        return;
    }
    root->print();
    cout << endl;
}

void BTree::printArray() {
    print(root);
    cout << endl;
}

void BTree::printTree() {
    if (root == nullptr) {
        cout << "空树-" << endl;
        return;
    }
    queue<BTreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        BTreeNode *p = q.front();
        q.pop();
        cout << "|";
        p->print();
        cout << "|";
        if (p->isLeaf()) continue;
        for (auto &child : p->childs) {
            q.push(child);
        }
    }
    cout << endl;
}
