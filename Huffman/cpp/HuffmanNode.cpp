//
// Created by user on 2019/9/23.
//

#include "HuffmanNode.h"

HuffmanNode::HuffmanNode() {
    left = right = nullptr;
}

HuffmanNode::HuffmanNode(char symbol, unsigned long freq, unsigned int runLen, HuffmanNode *left = nullptr,
                         HuffmanNode *right = nullptr)
        : left(left), right(right), symbol(symbol), freq(freq), runLen(runLen) {}
