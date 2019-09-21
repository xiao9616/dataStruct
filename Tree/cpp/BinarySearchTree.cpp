//
// Created by user on 2019/9/19.
//

#include <iostream>
#include "BinarySearchTree.h"
#include <stack>

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {

}

void BinarySearchTree::insert(int val) {
    BinaryTreeNode *prev = root, *p = root;
    while (p != nullptr) {
        prev = p;
        if (val < p->val) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    if (root == nullptr) {
        root = new BinaryTreeNode(val);
    } else if (val < prev->val) {
        prev->left = new BinaryTreeNode(val);
    } else {
        prev->right = new BinaryTreeNode(val);
    }
}

void BinarySearchTree::breadSearch() {
    cout << "breadSearch:" << endl;
    queue<BinaryTreeNode *> queueNode;
    BinaryTreeNode *p = root;
    if (p != nullptr) {
        queueNode.push(p);
        while (!queueNode.empty()) {
            p = queueNode.front();
            queueNode.pop();
            showNode(p);
            if (p->left != nullptr) {
                queueNode.push(p->left);
            }
            if (p->right != nullptr) {
                queueNode.push(p->right);
            }
        }
    }
    cout << endl;
}

void BinarySearchTree::showNode(BinaryTreeNode *p) {
    cout << p->val << "  ";
}

void BinarySearchTree::preOrderSearch(BinaryTreeNode *root) {
    if (root != nullptr) {
        showNode(root);
        preOrderSearch(root->left);
        preOrderSearch(root->right);
    }
}

void BinarySearchTree::midOrderSearch(BinaryTreeNode *root) {
    if (root != nullptr) {
        midOrderSearch(root->left);
        showNode(root);
        midOrderSearch(root->right);
    }
}

void BinarySearchTree::lastOrderSearch(BinaryTreeNode *root) {
    if (root != nullptr) {
        lastOrderSearch(root->left);
        lastOrderSearch(root->right);
        showNode(root);
    }
}

void BinarySearchTree::preOrder() {
    cout << "preOrder:" << endl;
    preOrderSearch(root);
    cout << endl;
}

void BinarySearchTree::midOrder() {
    cout << "midOrder:" << endl;
    midOrderSearch(root);
    cout << endl;
}

void BinarySearchTree::lastOrder() {
    cout << "lastOrder:" << endl;
    lastOrderSearch(root);
    cout << endl;
}

void BinarySearchTree::preOrderByStack() {
    cout << "preOrderByStack:" << endl;
    stack<BinaryTreeNode *> stackNode;
    BinaryTreeNode *p = root;
    if (p != nullptr) {
        stackNode.push(p);
        while (!stackNode.empty()) {
            p = stackNode.top();
            stackNode.pop();
            showNode(p);
            if (p->right != nullptr) {
                stackNode.push(p->right);
            }
            if (p->left != nullptr) {
                stackNode.push(p->left);
            }
        }
    }
    cout << endl;
}

void BinarySearchTree::midOrderByStack() {
    cout << "midOrderByStack:" << endl;
    stack<BinaryTreeNode *> stackNode;
    BinaryTreeNode *p = root;
    while (p != nullptr || !stackNode.empty()) {
        while (p != nullptr) {
            stackNode.push(p);
            p = p->left;
        }
        p = stackNode.top();
        stackNode.pop();
        showNode(p);
        p = p->right;
    }
    cout << endl;
}

void BinarySearchTree::lastOrderByStack() { //todo 不理解
    cout << "lastOrderByStack:" << endl;
    stack<BinaryTreeNode *> stackNode;
    BinaryTreeNode *p = root, *q = root;
    while (p != nullptr) {
        for (; p->left != nullptr; p = p->left) {
            stackNode.push(p);
        }
        while (p->right == nullptr || p->right == q) {
            showNode(p);
            q = p;
            if (stackNode.empty()) {
                cout << endl;
                return;
            }
            p = stackNode.top();
            stackNode.pop();
        }
        stackNode.push(p);
        p = p->right;
    }
    cout << endl;
}

BinaryTreeNode *BinarySearchTree::search(int val) {
    BinaryTreeNode *p = root;
    while (p != nullptr) {
        if (p->val == val) {
            return p;
        } else if (val < p->val) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return nullptr;
}

void BinarySearchTree::deleteByMerge(int val) { //找到要删除节点的左子数的最大节点,使之成为右子树的父节点
    //或者要删除节点的右子数的最小节点,使之成为左子数的父节点
    BinaryTreeNode *p = search(val),temp;
    temp = p;
    if (p != nullptr) {

    }
}

void BinarySearchTree::deleteByCopy(int val) {

}
