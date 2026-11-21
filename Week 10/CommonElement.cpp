
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    int A[n];
    unordered_set<int> s;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        s.insert(A[i]);
    }

    cin >> m;

    int B[m];

    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < m; i++) {
        if (s.find(B[i]) != s.end()) {
            cout << B[i] << " ";
            s.erase(B[i]);
        }
    }

    return 0;
}
