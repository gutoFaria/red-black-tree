#include "No.hpp"
#include <iostream>
using namespace std;

No::No(){}

No::No(Words key)
{
    this->key = key;
    this->left = NULL;
    this->right = NULL;
    this->color = RED;
}