//Paritosh Jha and Pranav Acharya
//Feb 10 2020
#include <iostream>
using namespace std;
#include <string>
#include "file.h"
#include "string.h"
#include "word.h"

Word::Word()
{
    used = 0;
    totalCount = 0;
    head = nullptr;
    tail = nullptr;
}

Word::Word(string word)
{
    this->word = word;
    used = 0;
    totalCount = 0;
    head = nullptr;
    tail = nullptr;
}
dnode<File>*& Word::getHead()
{
    return head;
}

void Word::setWord(string newword)
{
    word = newword;
}
void Word::incUsed()
{
    used++;
}
int Word::getUsed()
{
    return used;
}
string Word::getString()
{
    return word;
}
void Word::incTotalCount()
{
    totalCount++;
}
int Word::getTotalCount()
{
    return totalCount;
}

bool Word::insert(string filename)
{
    totalCount++;

    dnode<File>* temp = head;
    if (head == nullptr)
    {
        File f(filename);
        head = new dnode<File>(f);
        tail = head;
        return true;
    }
    while (temp != nullptr)
    {
        if (filename == temp->getObj().getString())
        {
            temp->getObj().incCount();
            return true;
        }
        temp = temp->getNext();
    }
    File f(filename);
    dnode<File>* newTail = new dnode<File>(f);
    newTail->setPrev(tail);
    tail->setNext(newTail);
    tail = newTail;

    while(newTail->getPrev() && newTail->getObj().getString() < newTail->getPrev()->getObj().getString())
        {
            swap(newTail->getPrev(),newTail);
            newTail = newTail->getPrev();

        }
    
    
    return true;

    
 
}

void Word::printFiles()
{
    cout<<"Total Count: " << totalCount << endl;
    dnode<File>* temp = head;
    while (temp != nullptr)
    {

        cout<<temp->getObj().getString()<<" :: " <<temp->getObj().getCount()<<endl;
        temp = temp->getNext();
    }
}
