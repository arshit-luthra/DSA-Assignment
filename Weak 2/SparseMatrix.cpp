#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Term {
    int row;
    int col;
    int value;
};

class SparseMatrix {
public:
    int rows, cols;
    vector<Term> terms;

    SparseMatrix(int r, int c) {
        rows = r;
        cols = c;
    }

    void addTerm(int r, int c, int value) {
        if (value != 0)
            terms.push_back({r, c, value});
    }

    void sortTerms() {
        sort(terms.begin(), terms.end(), [](Term a, Term b) {
            if (a.row == b.row)
                return a.col < b.col;
            return a.row < b.row;
        });
    }

    SparseMatrix transpose() {
        SparseMatrix result(cols, rows);

        for (int c = 0; c < cols; c++) {
            for (auto t : terms) {
                if (t.col == c)
                    result.addTerm(t.col, t.row, t.value);
            }
        }

        return result;
    }

    SparseMatrix add(SparseMatrix b) {
        if (rows != b.rows || cols != b.cols) {
            cout << "Addition not possible." << endl;
            return SparseMatrix(0, 0);
        }

        SparseMatrix result(rows, cols);

        int i = 0, j = 0;

        while (i < terms.size() && j < b.terms.size()) {
            Term a = terms[i];
            Term c = b.terms[j];

            if (a.row < c.row ||
                (a.row == c.row && a.col < c.col)) {

                result.addTerm(a.row, a.col, a.value);
                i++;
            }
            else if (c.row < a.row ||
                     (a.row == c.row && c.col < a.col)) {

                result.addTerm(c.row, c.col, c.value);
                j++;
            }
            else {
                result.addTerm(a.row, a.col, a.value + c.value);
                i++;
                j++;
            }
        }

        while (i < terms.size()) {
            result.addTerm(terms[i].row, terms[i].col, terms[i].value);
            i++;
        }

        while (j < b.terms.size()) {
            result.addTerm(b.terms[j].row, b.terms[j].col, b.terms[j].value);
            j++;
        }

        return result;
    }

    SparseMatrix multiply(SparseMatrix b) {
        if (cols != b.rows) {
            cout << "Multiplication not possible." << endl;
            return SparseMatrix(0, 0);
        }

        SparseMatrix result(rows, b.cols);
        vector<vector<int>> temp(rows, vector<int>(b.cols, 0));

        for (auto a : terms) {
            for (auto c : b.terms) {
                if (a.col == c.row) {
                    temp[a.row][c.col] += a.value * c.value;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < b.cols; j++) {
                if (temp[i][j] != 0)
                    result.addTerm(i, j, temp[i][j]);
            }
        }

        return result;
    }

    void display() {
        cout << "Row\tColumn\tValue" << endl;

        for (auto t : terms) {
            cout << t.row << "\t"
                 << t.col << "\t"
                 << t.value << endl;
        }
    }
};

SparseMatrix inputMatrix(string name) {
    int rows, cols, nonZero;

    cout << "Enter rows and columns of " << name << ": ";
    cin >> rows >> cols;

    SparseMatrix matrix(rows, cols);

    cout << "Enter number of non-zero elements: ";
    cin >> nonZero;

    cout << "Enter row, column and value:" << endl;

    for (int i = 0; i < nonZero; i++) {
        int row, col, value;
        cin >> row >> col >> value;
        matrix.addTerm(row, col, value);
    }

    matrix.sortTerms();

    return matrix;
}

int main() {
    SparseMatrix A = inputMatrix("Matrix A");

    cout << "\nMatrix A:" << endl;
    A.display();

    SparseMatrix T = A.transpose();

    cout << "\nTranspose of Matrix A:" << endl;
    T.display();

    SparseMatrix B = inputMatrix("Matrix B");

    cout << "\nMatrix B:" << endl;
    B.display();

    SparseMatrix C = A.add(B);

    if (C.rows != 0) {
        cout << "\nAddition of A and B:" << endl;
        C.display();
    }

    SparseMatrix D = A.multiply(B);

    if (D.rows != 0) {
        cout << "\nMultiplication of A and B:" << endl;
        D.display();
    }

    return 0;
}