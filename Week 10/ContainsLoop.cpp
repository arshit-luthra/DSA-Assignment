
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool detectLoop(Node* head) {
    unordered_set<Node*> s;

    Node* temp = head;

    while (temp != NULL) {
        if (s.find(temp) != s.end()) {
            return true;
        }

        s.insert(temp);
        temp = temp->next;
    }

    return false;
}

int main() {
    Node* head = new Node{1, NULL};
    Node* second = new Node{2, NULL};
    Node* third = new Node{3, NULL};
    Node* fourth = new Node{4, NULL};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;

    if (detectLoop(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}
