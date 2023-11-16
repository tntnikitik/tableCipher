#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>
class tableCipher
{
private:
    int key1; 
public:
    tableCipher()=delete;
    tableCipher(const int& key) :key1(key) {};
    std::wstring encrypt(const std::wstring& open_text); 
    std::wstring decrypt(const std::wstring& cipher_text); 
};