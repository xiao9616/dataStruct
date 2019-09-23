//
// Created by user on 2019/9/23.
//

#ifndef CPP_HUFFMANCODING_H
#define CPP_HUFFMANCODING_H

#include <iostream>

using namespace std;

class HuffmanCoding {
public:
    void compress(char *c, ifstream &file);

    void decompress(char *c, ifstream &file);

private:
    const unsigned int bytes, bits, ASCII;

};


#endif //CPP_HUFFMANCODING_H
