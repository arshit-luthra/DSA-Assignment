#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {

    cout << "Enter number of elements: ";
    int n;
    cin >> n;

    int arr[n];

    cout << "Enter elements in sorted order:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    int key;
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result == -1) {
        cout << "Element not found." << endl;
    }
    else {
        cout << "Element found at index: " << result << endl;
    }

    cout << "Time Complexity: O(log n)" << endl;
    cout << "Space Complexity: O(1)" << endl;

    return 0;
}