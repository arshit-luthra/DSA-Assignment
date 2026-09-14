#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string str;

    cout << "Enter string: ";
    cin >> str;

    queue<char> q;

    int frequency[256] = {0};

    for (char ch : str) {
        frequency[ch]++;

        q.push(ch);

        while (!q.empty() && frequency[q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }

    return 0;
}