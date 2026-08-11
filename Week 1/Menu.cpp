#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int n = 0;
    int choice;

    do {
        cout << "\n----- ARRAY MENU -----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                cout << "\nEnter number of elements: ";
                cin >> n;

                cout << "Enter " << n << " elements:\n";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }

                cout << "Array created successfully.\n";
                break;
            }

            case 2: {
                if (n == 0) {
                    cout << "Array is empty.\n";
                } else {
                    cout << "Array elements: ";
                    for (int i = 0; i < n; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                }
                break;
            }

            case 3: {
                int position, value;

                if (n >= 100) {
                    cout << "Array is full. Cannot insert.\n";
                    break;
                }

                cout << "Enter position for insertion (1 to " << n + 1 << "): ";
                cin >> position;

                if (position < 1 || position > n + 1) {
                    cout << "Invalid position.\n";
                    break;
                }

                cout << "Enter value to insert: ";
                cin >> value;

                for (int i = n; i >= position; i--) {
                    arr[i] = arr[i - 1];
                }

                arr[position - 1] = value;
                n++;

                cout << "Element inserted successfully.\n";
                break;
            }

            case 4: {
                int position;

                if (n == 0) {
                    cout << "Array is empty. Nothing to delete.\n";
                    break;
                }

                cout << "Enter position to delete (1 to " << n << "): ";
                cin >> position;

                if (position < 1 || position > n) {
                    cout << "Invalid position.\n";
                    break;
                }

                for (int i = position - 1; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }

                n--;

                cout << "Element deleted successfully.\n";
                break;
            }

            case 5: {
                int value;
                bool found = false;

                if (n == 0) {
                    cout << "Array is empty.\n";
                    break;
                }

                cout << "Enter element to search: ";
                cin >> value;

                for (int i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        cout << "Element found at position " << i + 1 << ".\n";
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Element not found.\n";
                }

                break;
            }

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}