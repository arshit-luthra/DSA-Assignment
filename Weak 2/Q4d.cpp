#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    string arr[n];

    cout << "Enter strings: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Strings in alphabetical order: " << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}