
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    unordered_set<int> s;

    bool duplicate = false;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (s.find(arr[i]) != s.end()) {
            duplicate = true;
        }

        s.insert(arr[i]);
    }

    if (duplicate)
        cout << "true";
    else
        cout << "false";

    return 0;
}
