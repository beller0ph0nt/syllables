#pragma once

#include <list>
#include <string>

using namespace std;

class ISyllabelSplitter
{
public:
    virtual list<string> GetSyllabels(string word) = 0;
};

