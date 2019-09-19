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
    clear(root);
}

void BinarySearchTree::clear(BinaryTreeNode *root) {
    if (root != nullptr) {
        if (root->left != nullptr) {
            clear(root->left);
        }
        if (root->right != nullptr) {
            clear(root->right);
        }
        delete root;
    }
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

void BinarySearchTree::deepSearch() {
    stack<BinaryTreeNode *> stackNode;
    BinaryTreeNode *p = root;
    if (p != nullptr) {
        stackNode.push(p);
        while (!stackNode.empty()) {
            p = stackNode.top();
            stackNode.pop();
            showNode(p);
            if (p->left != nullptr) {
                stackNode.push(p->left);
            }
            if (p->right != nullptr) {
                stackNode.push(p->right);
            }
        }
    }
    cout << endl;
}

void BinarySearchTree::showNode(BinaryTreeNode *p) {
    cout << p->val << "  ";
}
