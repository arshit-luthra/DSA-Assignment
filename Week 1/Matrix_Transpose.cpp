#include <iostream>
using namespace std;

int main() {
    int matrix[10][10], transpose[10][10];
    int rows, columns;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}