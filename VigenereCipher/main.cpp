
#include <iostream>
#include <string>
using namespace std;

class Vigenere
{
public:
    string key;

    Vigenere(string key)
    {
        for (int i = 0; i < key.size(); ++i)
        {
            if (key[i] >= 'A' && key[i] <= 'Z')
                this->key += key[i];
            else if (key[i] >= 'a' && key[i] <= 'z')
                this->key += key[i] + 'A' - 'a';
        }
    }

    string encrypt(string text)
    {
        string out;

        for (int i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];

            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;

            out += (c + key[j] - 2 * 'A') % 26 + 'A';
            j = (j + 1) % key.length();
        }

        return out;
    }

    string decrypt(string text)
    {
        string out;

        for (int i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];

            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;

            out += (c - key[j] + 26) % 26 + 'A';
            j = (j + 1) % key.length();
        }

        return out;
    }
};

int main()
{
    int choice;
    string user_key;
    string user_content;
    string encrypted;
    string decrypted;
    cout << "Enter cipher key you would like to use: " << endl;
    cin >> user_key;

    Vigenere cipher(user_key);
    cout << "Enter 1 if you would like to encrypt or 2 if you would like to decrypt content: " << endl;
    cin >> choice;

    switch (choice)
    {
    case 1: 
        cin.ignore();
        cout << "Enter content you want to encrypt: " << endl;
        getline(cin, user_content);
        cout << user_content << endl;
        encrypted = cipher.encrypt(user_content);
        break;
    case 2:
        cout << "Enter content you want to decrypt: " << endl;
        cin >> user_content;
        decrypted = cipher.decrypt(user_content);
        break;
    default:
        cout << "Enter either 1 or 2 to perform encryption or decryption " << endl;
    }
    cout << "User: " << user_content << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

}

