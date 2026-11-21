#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i, bool increasing) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (increasing) {
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
    }
    else {
        if (left < n && arr[left] < arr[largest])
            largest = left;

        if (right < n && arr[right] < arr[largest])
            largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, increasing);
    }
}
void heapSort(int arr[], int n, bool increasing) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int choice;
    cout << "\n1. Increasing Order";
    cout << "\n2. Decreasing Order";
    cout << "\nEnter your choice: ";
    cin >> choice;
    if (choice == 1) {
        heapSort(arr, n, true);
        cout << "Sorted in Increasing Order: ";
    }
    else if (choice == 2) {
        heapSort(arr, n, false);
        cout << "Sorted in Decreasing Order: ";
    }
    else {
        cout << "Invalid choice";
        return 0;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}