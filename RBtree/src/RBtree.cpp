#include "RBtree.hpp"
#include <iostream>
using namespace std;

RBtree::RBtree(){}

int RBtree::colorNo(No *node)
{
    if(node == NULL)
        return BLACK;
    else
        return node->color;
}

void RBtree::swapColor(No *node)
{
    node->color = !node->color;
    if(node->left != NULL)
        node->left->color = ! node->left->color;
    if(node->right != NULL)
        node->right->color = !node->right->color;
}

No* RBtree::rotationLeft(No *A)
{
    No *B =A->right;
    A->right = B->left;
    B->left = A;
    B->color = A->color;
    A->color = RED;
    return B;
}

No* RBtree::rotationRight(No *A)
{
    No *B =A->left;
    A->left = B->right;
    B->right = A;
    B->color = A->color;
    A->color = RED;
    return B;
}

No* RBtree::moveLeft(No *node)
{
    swapColor(node);
    if(colorNo(node->right->left) == RED)
    {
        node->right = rotationRight(node->right);
        node = rotationLeft(node);
        swapColor(node);
    }
    return node;
}

No* RBtree::moveRight(No *node)
{
    swapColor(node);
    if(colorNo(node->left->left) == RED)
    {
        node = rotationRight(node);
        swapColor(node);
    }
    return node;
}

No* RBtree::balance(No *node)
{
    if(colorNo(node->right) == RED)
        node =rotationLeft(node);
    if(node->left != NULL && colorNo(node->left) == RED && colorNo(node->left->left) == RED)
        node = rotationRight(node);
    if(colorNo(node->left) == RED && colorNo(node->right) == RED)
        swapColor(node);
    
    return node;
}

int RBtree::insert(No **root,Words key)
{
    int resp;
    (*root) = insertNo((*root),key,&resp);
    if((*root) != NULL)
        (*root)->color = BLACK;
    
    return resp;
}

No* RBtree::insertNo(No* node, Words key,int *resp)
{

    if(node == NULL)
    {
        No *newNo = new No(key);
        if(newNo == NULL)
        {
            *resp = 0;
            return NULL;
        }
        *resp = 1;
        return newNo;
    }
    if(key.getEnglishWord() == node->key.getEnglishWord())
        *resp = 0;
    else
    {
        //pega o tamanho da a palavra relacinada ao objeto a ser inserido
        int n1 = key.getEnglishWord().length();    
        //pega o tamanho da palavra na árvore
        int n2 = node->key.getEnglishWord().length();
        //define o tamanho do vetor de caracteres
        char *w1 = new char[n1 +1];
        char *w2 = new char[n2 +1];
        //copia a string para o vetor de caracteres
        strcpy(w1, key.getEnglishWord().c_str());
        strcpy(w2, node->key.getEnglishWord().c_str());

        if(strcmp(w1,w2) < 0)
            node->left = insertNo(node->left,key,resp);
        else
            node->right = insertNo(node->right,key,resp);
    }

    if(colorNo(node->right) == RED && colorNo(node->left) ==BLACK)
        node = rotationLeft(node);
    if(colorNo(node->left) == RED && colorNo(node->left->left) == RED)
        node = rotationRight(node);
    if(colorNo(node->left) == RED && colorNo(node->right) == RED)
        swapColor(node);
    
    return node;
}

int RBtree::remove(No **root,Words key)
{
    if(queryTree(root,key) != NULL)
    {
        No *node = (*root);
        (*root) = removeNo(node,key);

        if((*root) != NULL)
        {
            (*root)->color = BLACK;
            return 1;
        }
        else 
            return 0;
    }
    return 0;
}

No* RBtree::removeNo(No *node,Words key)
{
    int n1 = key.getEnglishWord().length();    
    //pega o tamanho da palavra na árvore
    int n2 = node->key.getEnglishWord().length();
    //define o tamanho do vetor de caracteres
    char *w1 = new char[n1 +1];
    char *w2 = new char[n2 +1];
    //copia a string para o vetor de caracteres
    strcpy(w1, key.getEnglishWord().c_str());
    strcpy(w2, node->key.getEnglishWord().c_str());

    if(strcmp(w1,w2) < 0)
    {
        if(colorNo(node->left) == BLACK && colorNo(node->left->left) == BLACK)
            node = moveLeft(node);
        node->left = removeNo(node->left,key);
    }
    else
    {
        if(colorNo(node->left) == RED)
            node = rotationRight(node);
            
        if(key.getEnglishWord() == node->key.getEnglishWord() && (node->right == NULL))
        {
            delete (node);
            return NULL;
        }
        if(colorNo(node->right) == BLACK && colorNo(node->right->left) == BLACK)
            node = moveRight(node);

        if(key.getEnglishWord() == node->key.getEnglishWord())
        {
            No *x = searchMinimum(node->right);
            node->key = x->key;
            node->right = removeMinimum(node->right);
        }
        else
            node->right= removeNo(node->right,key);
    }
    return balance(node);
}

No* RBtree::removeMinimum(No *node)
{
    if(node->left == NULL)
    {
        delete (node);
        return NULL;
    }
    if(colorNo(node->left) == BLACK && colorNo(node->left->left) == BLACK)
        node = moveLeft(node);
    
    node->left = removeMinimum(node->left);

    return balance(node);
}

No* RBtree::searchMinimum(No *node)
{
    No* node1 = node;
    No* node2 = node->left;

    while(node2 != NULL)
    {
        node1 = node2;
        node2 = node2->left;
    }
    return node1;
}

No* RBtree::queryTree(No **root,Words key)
{
    if (root == NULL || (*root)->key.getEnglishWord() == key.getEnglishWord())
    {
        return (*root);
    }	
	else
    {
         //pega o tamanho da a palavra relacinada ao objeto a ser inserido
        int n1 = key.getEnglishWord().length();    
        //pega o tamanho da palavra na árvore
        int n2 = (*root)->key.getEnglishWord().length();
        //define o tamanho do vetor de caracteres
        char *w1 = new char[n1 +1];
        char *w2 = new char[n2 +1];
        //copia a string para o vetor de caracteres
        strcpy(w1, key.getEnglishWord().c_str());
        strcpy(w2, (*root)->key.getEnglishWord().c_str());

        if (strcmp(w1,w2) > 0)
			return queryTree(&(*root)->right, key);
		else
			return queryTree(&(*root)->left, key);
    }
		
}

void RBtree::inOrder(No *root)
{
    if (root == NULL)
		return;

	inOrder(root->left);
	root->key.printWords() ;
	inOrder(root->right);
}

void RBtree::searchWord(No **root,string word)
{
    if((*root) == NULL)
    {
        cout<<"Palavra não encontrada"<<endl;
        return;
    }    
    if ((*root)->key.getEnglishWord() == word)
    {
        (*root)->key.printWords();
    }	
	else
    {
         //pega o tamanho da a palavra relacinada ao objeto a ser inserido
        int n1 = word.length();    
        //pega o tamanho da palavra na árvore
        int n2 = (*root)->key.getEnglishWord().length();
        //define o tamanho do vetor de caracteres
        char *w1 = new char[n1 +1];
        char *w2 = new char[n2 +1];
        //copia a string para o vetor de caracteres
        strcpy(w1, word.c_str());
        strcpy(w2, (*root)->key.getEnglishWord().c_str());

        if (strcmp(w1,w2) > 0)
			return searchWord(&(*root)->right, word);
		else
			return searchWord(&(*root)->left, word);
    }
}