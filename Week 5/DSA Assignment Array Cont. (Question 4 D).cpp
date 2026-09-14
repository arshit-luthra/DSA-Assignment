#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string str[20], temp;

    cout << "Enter number of strings: ";
    cin >> n;

    cout << "Enter the strings:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    cout << "Strings in alphabetical order:" << endl;

    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }

    return 0;
}