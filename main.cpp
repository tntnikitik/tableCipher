#include  "tableCipher.h"
using namespace std;

int main(int argc, char **argv)
{
    try {
        locale loc("ru_RU.UTF-8");
        locale::global(loc);
        int key;
        wstring text;
        int op;
        wcout<<L"Cipher ready. Input key: ";
        wcin>>key;
        tableCipher cipher(key);
        do {
            wcout<<L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
            wcin>>op;
            if (op > 2) {
                throw cipher_error("Illegal operation\n");
            } else if (op >0) {
                wcout<<L"Cipher ready. Input text: ";
                wcin>>text;
                std::wstring vtext=cipher.toValid(text);
                if (op==1) {
                    wcout<<L"Encrypted text: "<<cipher.encrypt(vtext)<<endl;
                } else {
                    wcout<<L"Decrypted text: "<<cipher.decrypt(vtext)<<endl;
                }
            }
        } while (op!=0);
    } catch (const cipher_error& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return 1;

    }
}
