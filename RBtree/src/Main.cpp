#include <iostream>
#include <cstring>
#include <string>
#include "Arquivo.hpp"
using namespace std;
 
// driver code
int main()
{
    char choice;
    RBtree rb;
    Arquivo a;
    string word;
    string word1,word2,word3;
    No *root = NULL;
    a.carregaArquivo("words.txt",&root);

    do
    {
        cout<<"\n######################################"<<endl;
        cout<<"#   MINI DIONÁRIO INGLÊS PORTUGUÊs   #"<<endl;
        cout<<"######################################"<<endl;
        cout<<"Digite [1] para pesquisar uma palavra:"<<endl;
        cout<<"Digite [2] adicionar uma nova palavra:"<<endl;
        cout<<"Digite [0] para sair:"<<endl;
        cout<<"Escolha:";
        cin>>choice;

        switch (choice)
        {
            case '1':
                {
                    getchar();
                    cout<<"Digite a palavra a ser encontrada:";
                    getline(cin, word);
                    cout<<endl;
                    rb.searchWord(&root,word);
                }
                break;
            case '2':
                {
                    getchar();
                    cout<<"Digite a palavra em inglês:";
                    getline(cin, word1);
                    cout<<"Digite a pronuncia da palavra:";
                    getline(cin, word2);
                    cout<<"Digite a tradução da palavra:";
                    getline(cin, word3);
                    Words w(word1,word2,word3);
                    rb.insert(&root,w);
                    a.writeFile("words.txt",w);
                }
                break;
            case '0':
               { cout<<"Encerrando..."<<endl;}
                break;
            default:
                {cout<<"Opção invália "<<endl;}
                break;
        }
    } while (choice != '0');
    
     
    return 0;
}