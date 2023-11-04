#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Syllables/RussianSyllabelSplitter.h"
#include "../Syllables/EnglishSyllabelSplitter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    BEGIN_TEST_MODULE_ATTRIBUTE()
        TEST_MODULE_ATTRIBUTE(L"Date", L"2018/31/10")
    END_TEST_MODULE_ATTRIBUTE()

    TEST_MODULE_INITIALIZE(ModuleInitialize)
    {
        Logger::WriteMessage("In Module Initialize");
    }

    TEST_MODULE_CLEANUP(ModuleCleanup)
    {
        Logger::WriteMessage("In Module Cleanup");
    }

	TEST_CLASS(UnitTest)
	{
	public:
        UnitTest()
        {
            Logger::WriteMessage("In UnitTest");
        }
        ~UnitTest()
        {
            Logger::WriteMessage("In ~UnitTest");
        }

        TEST_CLASS_INITIALIZE(ClassInitialize)
        {
            Logger::WriteMessage("In Class Initialize");
        }
        TEST_CLASS_CLEANUP(ClassCleanup)
        {
            Logger::WriteMessage("In Class Cleanup");
        }

        BEGIN_TEST_METHOD_ATTRIBUTE(TestRussianSyllabelSplitter)
            TEST_OWNER(L"OwnerName")
            TEST_PRIORITY(1)
        END_TEST_METHOD_ATTRIBUTE()

		/*TEST_METHOD(TestIsRussianVowel)
		{
            Logger::WriteMessage("In TestIsRussianVowel");
            const string goodLetters("���Ÿ���������������");
            const string badLetters("��������");

            for (auto c : goodLetters)
                Assert::IsTrue(isRussianVowel(c));

            for (auto c : badLetters)
                Assert::IsFalse(isRussianVowel(c));
		}*/

        /*TEST_METHOD(TestIsRussianLetter)
        {
            const string goodLetters("������������������������������������Ũ�������������������������");
            const string badLetters("aAbBcCdDeEfFgGhHiIjJ");
            
            for (auto c : goodLetters)
                Assert::IsTrue(isRussianLetter(c));

            for (auto c : badLetters)
                Assert::IsFalse(isRussianLetter(c));
        }*/

        /*TEST_METHOD(TestGetVowelsOffsets)
        {
            list<size_t> original = { 1, 3, 5 };
            list<size_t> vowels = getVowelsOffsets("������");

            Assert::IsTrue(original == vowels);
        }*/


        /*TEST_METHOD(TestGetSyllabels)
        {
            list<string> original = { "��", "��", "��" };
            list<string> syllabels = getSyllabels("������");

            Assert::IsTrue(original == syllabels);
        }*/

        TEST_METHOD(TestRussianSyllabelSplitter)
        {
            list<string> original = { "��", "��", "��" };

            RussianSyllabelSplitter splitter;
            list<string> syllabels = splitter.GetSyllabels("������");

            Assert::IsTrue(original == syllabels);
        }

        TEST_METHOD(TestEnglishSyllabelSplitter)
        {
            list<string> original = { "mo", "ther"};

            EnglishSyllabelSplitter splitter;
            list<string> syllabels = splitter.GetSyllabels("mother");

            Assert::IsTrue(original == syllabels);
        }
	};
}