#ifndef _RBTREE_HPP
#define _RBTREE_HPP
#include "No.hpp"
#include <iostream>
#include <cstring>

using namespace std;

class RBtree
{
public:
    RBtree();   

    int colorNo(No *node);
    void swapColor(No *node);
    No* rotationLeft(No *A);
    No* rotationRight(No *A);
    No* moveLeft(No *node);
    No* moveRight(No *node);
    No* balance(No *node);

    int insert(No **root,Words key);
    No* insertNo(No* node, Words key,int *resp);
    int remove(No **root,Words key);
    No* removeNo(No *node,Words key);
    No* removeMinimum(No *node);
    No* searchMinimum(No *node);
    No* queryTree(No **root,Words key);
    void inOrder(No *root);
    void searchWord(No **root,string word);
};
#endif