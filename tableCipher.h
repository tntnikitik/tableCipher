#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
class tableCipher
{
private:
    int key1;
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ";
    std::wstring lnumAlpha = L"абвгдеёжзийклмнопрстуфхцчшщьыъэюя";
    bool is_rus(wchar_t wc);
    int is_low_rus(wchar_t wch);
public:
    tableCipher()=delete;
    tableCipher(const int& key) {
        if (key<=0) {
            throw cipher_error("Key is not valid\n");
        } else {
            key1=key;
        }
    }
    std::wstring encrypt(std::wstring& open_text);
    std::wstring decrypt(std::wstring& cipher_text);
    std::wstring toValid(std::wstring& s);
};

