//Paritosh Jha and Pranav Acharya
//Feb 10 2020
#include "word.h"
#include "file.h"
#include "bag.h"
#include <string>
#include "string.h"
using namespace std;

Bag::Bag()
{
    used = 0;
    head = nullptr;
    tail = nullptr;
}


bool Bag::insert(string word, string filename)
{  
    if (head == nullptr)
    {
        Word w(word);
        w.insert(filename);
        head = new dnode<Word>(w);
        tail = head;
        return true;
    }
    dnode<Word>* temp = head;
    while (temp != nullptr)
    {
        if (temp->getObj().getString() == word)
        {
            temp->getObj().insert(filename);
            return true;
        
        }
        temp = temp->getNext();
    }
    Word w(word);
    w.insert(filename);
    dnode<Word>* newTail = new dnode<Word>(w);
    newTail->setPrev(tail);
    tail->setNext(newTail);
    tail = newTail;

    while (newTail->getPrev() && (newTail->getObj().getString() < newTail->getPrev()->getObj().getString()))
    {
        swap(newTail->getPrev(), newTail);
        newTail = newTail->getPrev();
    }

    return true;


}



void Bag::printWords()
{
    dnode<Word>* temp = head;
    while (temp != nullptr)
    {
        cout<<"The word is: " <<temp->getObj().getString()<<endl;
        temp->getObj().printFiles();
        temp = temp->getNext();
    }        

}
void Bag::threshold(string s, int i)
{
    dnode<Word>* temp = head;
    while (temp != nullptr)
    {
        if (temp->getObj().getString() == s)
        {
            dnode<File>* temp2 = temp->getObj().getHead();
            while (temp2 != nullptr)
            {
                if (temp2->getObj().getCount() >= i)
                {
                    cout<<temp2->getObj().getString()<<endl;
                }
                temp2 = temp2->getNext();
            }
        }
        temp = temp->getNext();

    }
}
void Bag::Union(string word1, string word2)
{
    int index = 0;
    string un[100];
    dnode<Word>* temp = head;
    while (temp != nullptr)
    {
        if (temp->getObj().getString() == word1)
        {
            dnode<File>* temp2 = temp->getObj().getHead();
            while (temp2 != nullptr)
            {
                un[index] = temp2->getObj().getString();
                index++;
                temp2 = temp2->getNext();
            }

        }
        temp = temp ->getNext();
    }
    temp = head;
    while (temp != nullptr)
    {
        if (temp->getObj().getString() == word2)
        {
            dnode<File>* temp3 = temp->getObj().getHead();
            while (temp3 != nullptr)
            {
                bool in = true;
                for (int i = 0; i < index; i++)
                {
                    if (temp3->getObj().getString() == un[i])
                    {
                        in = false;
                        break;
                    }
                }
                if (in)
                {
                    un[index] = temp3->getObj().getString();
                    index++;
                    for (int x = index - 1; x >0; x--)
                    {
                         if (un[x] < un[x-1])
                        {
                            string temp = un[x-1];
                            un[x-1] = un[x];
                            un[x] = temp;
                        }
                    }

                }
                temp3 = temp3->getNext();

            }

        }
        temp = temp->getNext();
    }
    for (int y = 0; y < index; y++)
    {
        cout<<un[y]<<endl;
    }


}
/*
bool Bag::search(string input)
{
    for (int i = 0; i < used; i++)
    {
        if (input == container[i].getString())
        {
            container[i].printFiles();
            return true;
        }
    }
    cout<<"Word not found in database"<<endl;
    return true;    
}
*/


