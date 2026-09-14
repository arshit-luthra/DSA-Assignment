#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();

        q.push(x);

        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty())
            cout << "Stack is Empty\n";
        else
            cout << "Top: " << q.front() << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.top();

    s.pop();

    s.top();

    return 0;
}