#include "Arquivo.hpp"
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <iostream>

Arquivo::Arquivo(){}

void Arquivo::carregaArquivo(string nome,No **root)
{    
    int x;
    RBtree rb;
    string linha;
    string wEng,wPron,wPor;
    ifstream arquivo;
    arquivo.open(nome);
    if(arquivo.is_open())
    {
        while(getline(arquivo,linha))
        {
        stringstream ss(linha);
        getline(ss,wEng,';');  
        getline(ss,wPron,';');
        getline(ss,wPor,';');
        Words w(wEng,wPron,wPor);
        x = rb.insert(root,w);
        }
    }
    else
    {
        cout<<"Não foi possível abrir o arquivo"<<endl;
        
    }
    if(x == 1)
        cout<<"Arquivo carregado."<<endl;
    arquivo.close();
}

void Arquivo::writeFile(string nome,Words w)
{
    ofstream arquivo;
    arquivo.open(nome,ios::app);
    arquivo<< "\n";
    arquivo<<w.getEnglishWord()<<";";
    arquivo<<w.getPronunciationWord()<<";";
    arquivo<<w.getPortugueseWord();
    arquivo.close();
}