#include <iostream>
#include <cctype>

using namespace std;

const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

bool key_check(string key)
{
    string::size_type i = 0;
    i = key.length();
    if (i != 26) {
        cout << "Error! The encryption key must contain 26 characters." << endl;
        return false;
    }
    for (int k = 0; k <= 25; ++k) {
        if (islower(key[k]) == false){
            cout << "Error! The encryption key must contain only lower case characters." << endl;
            return false;
        }
    }
    for (int l = 97; l <= 122; ++l) {
        if (key.find(l) == string::npos) {
            cout << "Error! The encryption key must contain all alphabets a-z." << endl;
            return false;
        }
    }
    return true;
}

string encrypt(string input_text, string key)
{
    int input_length;
    input_length = input_text.length();
    int index;
    string encrypted_text = input_text;
    for (int k = 0; k <= input_length-1; ++k) {
        index = ALPHABET.find(input_text.at(k));
        encrypted_text.at(k) = key.at(index);
    }
    return encrypted_text;
}

int main()
{
    cout << "Enter the encryption key: " << endl;
    string key;
    cin >> key;
    if (key_check(key) == false)
        return EXIT_FAILURE;
    else {
        cout << "Enter the text to be encrypted: " << endl;
        string input_text;
        cin >> input_text;
        cout << "Encrypted text: " << encrypt(input_text, key) << endl;
    }

}
