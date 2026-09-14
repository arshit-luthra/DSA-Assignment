#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    int arr[100];

    cout << "Enter " << n - 1 << " sorted elements: ";
    for (int i = 0; i < n - 1; i++)
        cin >> arr[i];

    // (a) Linear search method
    int missing1 = n;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            missing1 = i + 1;
            break;
        }
    }

    cout << "Missing number using linear method: " << missing1 << endl;

    // (b) Binary search method
    int low = 0, high = n - 2;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid + 1)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << "Missing number using binary search: " << low + 1;

    return 0;
}