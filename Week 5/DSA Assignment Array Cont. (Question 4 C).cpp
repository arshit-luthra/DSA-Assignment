#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "String without vowels: ";

    for (char ch : str) {
        if (ch != 'a' && ch != 'e' && ch != 'i' &&
            ch != 'o' && ch != 'u' &&
            ch != 'A' && ch != 'E' && ch != 'I' &&
            ch != 'O' && ch != 'U') {
            cout << ch;
        }
    }

    return 0;
}