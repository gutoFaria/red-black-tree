#ifndef _WORDS_HPP
#define _WORDS_HPP
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Words
{
private:
    string englishWord;
    string pronunciationWord;
    string portugueseWord;
public:
    Words();
    Words(string englishWord,string portugueseWord,string pronunciationWord);

    void setEnglishWord(string englishWord);
    string getEnglishWord();

    void setPortugueseWord(string portugueseWord);
    string getPortugueseWord();

    void setPronunciationWord(string pronunciationWord);
    string getPronunciationWord();

    void printWords();
};
#endif