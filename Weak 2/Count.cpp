#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_set<int> distinct;

    for (int i = 0; i < n; i++) {
        distinct.insert(arr[i]);
    }

    cout << "Total number of distinct elements: "
         << distinct.size() << endl;

    return 0;
}