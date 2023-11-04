#pragma once
#include "SyllabelSplitter.h"
class EnglishSyllabelSplitter :
    public SyllabelSplitter
{
public:
    EnglishSyllabelSplitter() :
        SyllabelSplitter("aeiouAEIOU", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
    {}
};
