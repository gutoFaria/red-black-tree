#ifndef _NO_HPP
#define _NO_HPP

#include <iostream>
#include "Words.hpp"

enum {BLACK,RED};

class No
{
public:
    Words key;
    No *left;
    No *right;
    int color;
    No();
    No(Words key);
};
#endif