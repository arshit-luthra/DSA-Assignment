#include <iostream>
using namespace std;

int missingLinear(int arr[], int n) {
    int sum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }

    return sum - actualSum;
}

int missingBinary(int arr[], int n) {
    int low = 0;
    int high = n - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low + 1;
}

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    int arr[n - 1];

    cout << "Enter " << n - 1 << " elements in sorted order: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    cout << "Missing number using Linear Search: "
         << missingLinear(arr, n) << endl;

    cout << "Missing number using Binary Search: "
         << missingBinary(arr, n) << endl;

    return 0;
}