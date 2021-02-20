#ifndef _ARQUIVO_HPP
#define _ARQUIVO_HPP

#include <string>
#include <iostream>

#include "RBtree.hpp"
using namespace std;


class Arquivo 
{
    private:
        string nome;
    public:
        Arquivo();
        void carregaArquivo(string nome,No **root);  
        void writeFile(string nome,Words w);
};
#endif