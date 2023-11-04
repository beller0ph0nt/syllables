#pragma once
#include "SyllabelSplitter.h"
class RussianSyllabelSplitter :
    public SyllabelSplitter
{
public:
    RussianSyllabelSplitter() :
        SyllabelSplitter("���Ÿ���������������", "������������������������������������Ũ�������������������������")
    {}
};
