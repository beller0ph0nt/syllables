#pragma once
#include "ISyllabelSplitter.h"

class SyllabelSplitter : public ISyllabelSplitter
{
    const string vowels;
    const string alphabet;
public:
    explicit SyllabelSplitter(const string _vowels, const string _alphabet) :
        vowels(_vowels),
        alphabet(_alphabet)
    {}

    list<string> GetSyllabels(string word) override;
private:
    bool IsVowel(char letter);
    bool IsLetter(const char letter);
    list<size_t> GetVowelsOffsets(const string word);
};

