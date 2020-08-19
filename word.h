//Paritosh Jha and Pranav Acharya
//Feb 10 2020
#ifndef _WORD_H
#define _WORD_H
#include <iostream>
using namespace std;
#include <string>
#include "file.h"
#include "string.h"
#include "dnode.h"

class Word{
    private:
        string word;
        dnode<File>* head;
        dnode<File>* tail;
        int used;
        int totalCount;
    public:
        Word();
        Word(string word);
        void setWord(string newword);

        dnode<File>*& getHead();

        void incUsed();
        int getUsed();

        string getString();

        void incTotalCount();
        int getTotalCount();

        bool insert(string filename);

        void printFiles();

        
};
#endif