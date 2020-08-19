//Paritosh Jha and Pranav Acharya
//Feb 10 2020
#ifndef _BAG_H
#define _BAG_H
#include "string.h"
#include <cstring>
#include "file.h"
#include "word.h"

using namespace std;

class Bag{
    dnode<Word>* head;
    dnode<Word>* tail;
    int used;

    public:
        Bag();
        bool insert(string wordname, string filename);
        void printWords();
        void threshold(string s, int i);
        void Union(string word1, string word2);
        
};
#endif