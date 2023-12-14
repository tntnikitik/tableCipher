#include  "tableCipher.h"
#include <string>

using namespace std;
std::wstring tableCipher::toValid(std::wstring& s)
{
    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;

    if (s.empty())
        throw cipher_error("Empty text");

    std::wstring tmp(s);
    std::string st = converter.to_bytes(s);
    for (auto & c:tmp) {
        if (!is_rus(c))
            throw cipher_error(("Text has invalid symbols: ") +st);
        if (is_low_rus(c)!=-1)
            c = numAlpha[is_low_rus(c)];
    }
    return tmp;
}
bool tableCipher::is_rus(wchar_t wch)
{
    std::wstring alf=lnumAlpha+numAlpha;
    for (uint i=0; i<alf.length(); i++) {
        if (wch == alf[i])
            return true;
    }
    return false;
}
int tableCipher::is_low_rus(wchar_t wch)
{
    for (uint i=0; i<lnumAlpha.length(); i++) {
        if (wch == lnumAlpha[i])
            return i;
    }
    return -1;
}
std::wstring tableCipher::encrypt(std::wstring& open_text)
{

    wstring tabl = open_text;
    int dl, nstrok, index, x;
    while (tabl.size() % key1 != 0) {
        tabl+=L"_";
    }
    open_text = tabl;
    dl = tabl.size();
    nstrok = (dl - 1) / key1 + 1;
    x = 0;
    wstring encrypted;
    for (int i = key1; i > 0; i--) {
        for (int j = 0; j < nstrok; j++) {
            index = i+key1*j;
            //wcout<<index<<endl;
            if (index-1 < dl) {
                tabl[x] = open_text[index-1];
                x++;
            }
        }
    }
    return tabl;
}

std::wstring tableCipher::decrypt(std::wstring& cipher_text)
{
    wstring tabl = cipher_text;
    int dl, nstrok, index, x;
    dl = cipher_text.length();
    nstrok = (dl - 1) / key1 + 1;
    x = 0;
    for (int i = key1; i > 0; i--) {
        for (int j = 0; j < nstrok; j++) {
            index = i+key1*j;
            if (index-1 < dl) {
                tabl[index-1] = cipher_text[x];
                x++;
            }
        }
    }
    return tabl;
}
