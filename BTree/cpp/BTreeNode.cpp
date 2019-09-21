//
// Created by user on 2019/9/21.
//

#include <iostream>
#include "BTreeNode.h"

BTreeNode::BTreeNode() {
    keys.clear();
    childs.clear();
    father = nullptr;
}

BTreeNode::BTreeNode(int data) {
    keys.push_back(data);
    childs.push_back(nullptr);
    childs.push_back(nullptr);
    father = nullptr;
}

BTreeNode::~BTreeNode() {
    keys.clear();
    childs.clear();
}

bool BTreeNode::isLeaf() {
    return childs.empty() || (*childs.begin() == nullptr);
}

bool BTreeNode::haskey(int key) {
    for (int &iter : keys) {
        if (iter == key) {
            return true;
        }
    }
    return false;
}

bool BTreeNode::replace(int oldKey, int newKey) {
    for (int &iter:keys) {
        if (iter == oldKey) {
            iter = newKey;
            return true;
        }
    }
    return false;
}

bool BTreeNode::eraseKey(int key) {
    if (!haskey(key)) {
        return false;
    }
    for (auto iter = keys.begin(); iter != keys.end(); ++iter) {
        if (*iter == key) {
            keys.erase(iter);
            break;
        }
    }
    return true;
}

bool BTreeNode::eraseChild(BTreeNode *child) {
    for (auto iter = childs.begin(); iter != childs.end(); ++iter) {
        if (*iter == child) {
            childs.erase(iter);
            return true;
        }
    }
    return false;
}

void BTreeNode::updateChild() {
    for (auto &child : childs) {
        if (child) {
            child->father = this;
        }
    }
}

void BTreeNode::insertKey(int data, BTreeNode *child1, BTreeNode *child2) {
    auto iter = keys.begin();
    auto iter_childs = childs.begin();
    while (iter != keys.end() && data > *iter) {
        ++iter;
        ++iter_childs;
    }
    keys.insert(iter, data);
    if (!childs.empty()) {
        iter_childs = childs.erase(iter_childs);
    }
    iter_childs = childs.insert(iter_childs, child2);
    iter_childs = childs.insert(iter_childs, child2);
}

void BTreeNode::print() {
    for (int &iter:keys) {
        cout << iter << " ";
    }
}

BTreeNode *BTreeNode::next(int key) {
    auto iter = keys.begin();
    auto iter_childs = childs.begin();
    while (iter != keys.end() && key > *iter) {
        ++iter;
        ++iter_childs;
    }
    return *iter_childs;
}

int BTreeNode::getKey(int pos) {
    auto iter = keys.begin();
    for (int i = 0; i < pos; ++i) {
        ++iter;
    }
    return *iter;
}

int BTreeNode::size() {
    return keys.size();
}
