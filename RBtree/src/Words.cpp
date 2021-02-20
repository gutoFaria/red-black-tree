#include "Words.hpp"
#include <iostream>
#include <cstring>
using namespace std;

Words::Words(){}

Words::Words(string englishWord, string pronunciationWord,string portugueseWord)
{
    this->englishWord = englishWord;
    this->portugueseWord = portugueseWord;
    this->pronunciationWord = pronunciationWord;
}

void Words::setEnglishWord(string englishWord)
{
    this->englishWord = englishWord;
}
string Words::getEnglishWord()
{
    return englishWord;
}

void Words::setPortugueseWord(string portugueseWord)
{
    this->portugueseWord = portugueseWord;
}
string Words::getPortugueseWord()
{
    return portugueseWord;
}

void Words::setPronunciationWord(string pronunciationWord)
{
    this->pronunciationWord = pronunciationWord;
}
string Words::getPronunciationWord()
{
    return pronunciationWord;
}

void Words::printWords()
{
    cout<<"----inglês"<<"------pronuncia"<<"----tradução------"<<endl;
    cout<<"|    "<<this->getEnglishWord()<<"    |   "<<this->getPronunciationWord()<<"    |   "<<this->getPortugueseWord()<<endl;
    cout<<"-------------------------------------------\n";
}