//Paritosh Jha and Pranav Acharya
//Feb 10 2020
#include <string>
#include "file.h"
#include "string.h"
using namespace std;

File::File()
{
    count = 0;
}
File::File(string name)
{
    filename = name;
    count = 1;
}

void File::setFileName(string newname)
{
    filename = newname;
}

string File::getString()
{
    return filename;
}

int File::getCount()
{
    return count;
}

void File::incCount()
{
    count++;
}
