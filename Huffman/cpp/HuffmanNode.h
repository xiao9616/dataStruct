//
// Created by user on 2019/9/23.
//

#ifndef CPP_HUFFMANNODE_H
#define CPP_HUFFMANNODE_H


class HuffmanNode {
public:
    HuffmanNode *left, *right;

    HuffmanNode();

    char symbol;
    unsigned long codeword, freq;
    unsigned int runLen, codewordLen;

    HuffmanNode(char symbol, unsigned long freq, unsigned int runLen, HuffmanNode *left, HuffmanNode *right);
};


#endif //CPP_HUFFMANNODE_H
