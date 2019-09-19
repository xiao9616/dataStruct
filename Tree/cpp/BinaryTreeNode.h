//
// Created by user on 2019/9/19.
//

#ifndef CPP_BINARYTREENODE_H
#define CPP_BINARYTREENODE_H


class BinaryTreeNode {
public:
    BinaryTreeNode *left, *right;
    int val;

    BinaryTreeNode() {
        left = right = nullptr;
    }

    BinaryTreeNode(int val, BinaryTreeNode *left = nullptr, BinaryTreeNode *right = nullptr) : left(left), right(right),
                                                                                               val(val) {}

    virtual ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};


#endif //CPP_BINARYTREENODE_H
