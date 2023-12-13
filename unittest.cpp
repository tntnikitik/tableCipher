#include <UnitTest++/UnitTest++.h>
#include <iostream>
#include "tableCipher.h"
#include <locale>
#include <codecvt>
using namespace std;

SUITE(KeyTest)
{
    TEST(ValidKey) {
        tableCipher test(5);
        CHECK(true);
    }
    TEST(LongKey) {
        tableCipher test(100);
        CHECK(true);
    }
    /*TEST(MinusInKey) {
        CHECK_THROW(tableCipher test(-245),cipher_error);
    }
    TEST(ZeroInKey) {
        CHECK_THROW(tableCipher test(0),cipher_error);
    }*/
}
struct KeyAB_fixture {
    tableCipher * pointer;
    KeyAB_fixture()
    {
        pointer = new tableCipher(4);
    }
    ~KeyAB_fixture()
    {
        delete pointer;
    }
};
SUITE(EncryptTest)
{
    TEST_FIXTURE(KeyAB_fixture, ValidText) {
        wstring open_text = L"ПРИВЕТ";
        wstring result_correct = L"В_И_РТПЕ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    /*TEST_FIXTURE(KeyAB_fixture, LowText) {
        wstring open_text = L"съешьжеещёэтихмягкихфранцузскихбулокдавыпейчаю";
        wstring result_correct = L"ШЕТЯХНСБКЫЧ_ЕЕЭМИАЗХОВЙ_ЪЖЁХКРУИЛАЕЮСЬЩИГФЦКУДПА";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, TextWithoutletters) {
        wstring open_text = L"!@#$%^&*()_+123";
        CHECK_THROW(pointer->encrypt(open_text), cipher_error);
    }
    TEST_FIXTURE(KeyAB_fixture, TextWithNumber) {
        wstring open_text = L"1337H4cK3r";
        CHECK_THROW(pointer->encrypt(open_text), cipher_error);
    }
    TEST_FIXTURE(KeyAB_fixture, TextWithPunct) {
        j _error);
    }*/
}
SUITE(DecryptText)
{
    TEST_FIXTURE(KeyAB_fixture, ValidTEXT) {
        wstring open_text = L"ВИРТПЕ";
        wstring result_correct = L"ПРИВЕТ";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(open_text));
    }
    /*TEST_FIXTURE(KeyAB_fixture, LowTEXT) {
        CHECK_EQUAL(wst1(4,L"PriaRARNomoIGMve"),"PROGRAMMIROVANIE");
    }
    TEST_FIXTURE(KeyAB_fixture, EmptyTEXT) {
        wstring open_text = L"";
        CHECK_THROW(pointer->decrypt(open_text), cipher_error);
    }
    TEST_FIXTURE(KeyAB_fixture, TextNumberText) {
        wstring open_text = L"ВИРТПЕ132";
        CHECK_THROW(pointer->decrypt(open_text), cipher_error);
    }
    TEST_FIXTURE(KeyAB_fixture, TextSymbolText) {
        wstring open_text = L"ВИРТПЕ!@#$";
        CHECK_THROW(pointer->decrypt(open_text), cipher_error);
    }

}*/

int main()
{
    return UnitTest::RunAllTests();
}
