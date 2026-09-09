#include <iostream>
using namespace std;

class Diagonal {
    int n;
    int *A;

public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
    }

    void set(int i, int j, int x) {
        if (i == j)
            A[i] = x;
    }

    int get(int i, int j) {
        if (i == j)
            return A[i];
        return 0;
    }
};

class TriDiagonal {
    int n;
    int *A;

public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3 * n - 2];
    }

    void set(int i, int j, int x) {
        if (i == j)
            A[n - 1 + i] = x;
        else if (i == j + 1)
            A[j] = x;
        else if (j == i + 1)
            A[2 * n - 1 + i] = x;
    }

    int get(int i, int j) {
        if (i == j)
            return A[n - 1 + i];
        else if (i == j + 1)
            return A[j];
        else if (j == i + 1)
            return A[2 * n - 1 + i];

        return 0;
    }
};

class LowerTriangular {
    int n;
    int *A;

public:
    LowerTriangular(int n) {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }

    void set(int i, int j, int x) {
        if (i >= j)
            A[i * (i + 1) / 2 + j] = x;
    }

    int get(int i, int j) {
        if (i >= j)
            return A[i * (i + 1) / 2 + j];

        return 0;
    }
};

class UpperTriangular {
    int n;
    int *A;

public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }

    void set(int i, int j, int x) {
        if (i <= j)
            A[i * (2 * n - i + 1) / 2 + (j - i)] = x;
    }

    int get(int i, int j) {
        if (i <= j)
            return A[i * (2 * n - i + 1) / 2 + (j - i)];

        return 0;
    }
};

class Symmetric {
    int n;
    int *A;

public:
    Symmetric(int n) {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }

    void set(int i, int j, int x) {
        if (i >= j)
            A[i * (i + 1) / 2 + j] = x;
        else
            A[j * (j + 1) / 2 + i] = x;
    }

    int get(int i, int j) {
        if (i >= j)
            return A[i * (i + 1) / 2 + j];
        else
            return A[j * (j + 1) / 2 + i];
    }
};

int main() {
    int n = 4;

    Diagonal d(n);
    for (int i = 0; i < n; i++)
        d.set(i, i, (i + 1) * 10);

    cout << "Diagonal Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << d.get(i, j) << " ";
        cout << endl;
    }

    TriDiagonal t(n);
    t.set(0, 0, 1);
    t.set(0, 1, 2);
    t.set(1, 0, 3);
    t.set(1, 1, 4);
    t.set(1, 2, 5);
    t.set(2, 1, 6);
    t.set(2, 2, 7);
    t.set(2, 3, 8);
    t.set(3, 2, 9);
    t.set(3, 3, 10);

    cout << "\nTri-diagonal Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << t.get(i, j) << " ";
        cout << endl;
    }

    LowerTriangular l(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            l.set(i, j, i + j + 1);

    cout << "\nLower Triangular Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << l.get(i, j) << " ";
        cout << endl;
    }

    UpperTriangular u(n);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            u.set(i, j, i + j + 1);

    cout << "\nUpper Triangular Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << u.get(i, j) << " ";
        cout << endl;
    }

    Symmetric s(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            s.set(i, j, i + j + 1);

    cout << "\nSymmetric Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << s.get(i, j) << " ";
        cout << endl;
    }

    cout << "\nSpace Requirements:" << endl;
    cout << "Diagonal Matrix: n" << endl;
    cout << "Tri-diagonal Matrix: 3n - 2" << endl;
    cout << "Lower Triangular Matrix: n(n+1)/2" << endl;
    cout << "Upper Triangular Matrix: n(n+1)/2" << endl;
    cout << "Symmetric Matrix: n(n+1)/2" << endl;

    return 0;
}