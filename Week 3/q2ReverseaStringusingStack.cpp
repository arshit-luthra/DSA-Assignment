#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    stack<char> s;

    cout << "Enter string: ";
    getline(cin, str);

    for (char ch : str) {
        s.push(ch);
    }

    cout << "Reversed string: ";

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}