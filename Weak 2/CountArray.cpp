#include <iostream>
using namespace std;

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inversions = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversions;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;

    long long inversions = 0;

    inversions += mergeSort(arr, temp, left, mid);
    inversions += mergeSort(arr, temp, mid + 1, right);
    inversions += merge(arr, temp, left, mid, right);

    return inversions;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    int temp[n];

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long result = mergeSort(arr, temp, 0, n - 1);

    cout << "Number of inversions: " << result << endl;

    return 0;
}