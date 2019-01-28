#include "SyllabelSplitter.h"

list<string> SyllabelSplitter::GetSyllabels(const string word)
{
    list<string> syllabels;
    list<size_t> vowelsOffsetList = GetVowelsOffsets(word);

    size_t offset = 0;
    auto currentVowelOffset = vowelsOffsetList.begin();
    while (currentVowelOffset != vowelsOffsetList.end())
    {
        auto previousVowelOffset = *currentVowelOffset;
        currentVowelOffset++;
        if (currentVowelOffset != vowelsOffsetList.end())
        {
            size_t distanceBetweenVowels = (*currentVowelOffset - previousVowelOffset - 1) / 2;
            size_t syllabelEndOffset = previousVowelOffset + distanceBetweenVowels;
            size_t syllabelLength = 1 + syllabelEndOffset - offset;
            syllabels.push_back(word.substr(offset, syllabelLength));
            offset += syllabelLength;
        }
    }

    size_t lastSyllablelLength = word.length() - offset;
    if (lastSyllablelLength > 0)
    {
        syllabels.push_back(word.substr(offset, lastSyllablelLength));
    }

    return syllabels;
}

bool SyllabelSplitter::IsVowel(char letter)
{
    return (vowels.find(letter, 0) == string::npos) ? false : true;
}

bool SyllabelSplitter::IsLetter(const char letter)
{
    return (alphabet.find(letter, 0) == string::npos) ? false : true;
}

list<size_t> SyllabelSplitter::GetVowelsOffsets(const string word)
{
    list<size_t> vowelsOffsetList;

    for (size_t charIndex = 0; charIndex < word.length(); charIndex++)
    {
        if (IsLetter(word[charIndex]))
        {
            if (IsVowel(word[charIndex]))
            {
                vowelsOffsetList.push_back(charIndex);
            }
        }
    }

    return vowelsOffsetList;
}
