//Paritosh Jha and Pranav Acharya
//Feb 10 2020
#ifndef _FILE_H
#define _FILE_H
#include "string.h"
#include <cstring>
#include <string>
using namespace std;

class File{
    string filename;
    int count;
    public:
        File();
        File(string name);
        void setFileName(string newname);
        string getString();
        int getCount();
        void incCount();
        
};
#endif