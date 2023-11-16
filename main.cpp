#include  "tableCipher.h"
using namespace std;

int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int key;
    wstring text;
    int op;
    wcout<<L"Cipher ready. Input key: ";
    wcin>>key;
    if (!wcin.good()) {
        wcerr<<L"key not valid\n";
        return 0;
    }

    tableCipher cipher(key);
    do {
        wcout<<L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        wcin>>op;
        if (op > 2) {
            wcout<<L"Illegal operation\n";
        } else if (op >0) {
            wcout<<L"Cipher ready. Input text: ";
            wcin>>text;
            if (op==1) {
                wcout<<L"Encrypted text: "<<cipher.encrypt(text)<<endl;
            } else {
                wcout<<L"Decrypted text: "<<cipher.decrypt(text)<<endl;
            }
        }
    } while (op!=0);
    return 0;
}