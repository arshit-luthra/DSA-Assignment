#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node* random;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
        random = NULL;
    }
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Correct the random pointer
void correctRandomPointer(Node* head) {
    Node* temp = head;

    while (temp != NULL) {

        // If random pointer is incorrect
        if (temp->random != NULL) {

            // Expected random pointer is assumed
            // to point to the next node
            if (temp->next != NULL) {
                temp->random = temp->next;
            }
        }

        temp = temp->next;
    }
}

void display(Node* head) {
    Node* temp = head;

    cout << "Doubly Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void displayRandomPointers(Node* head) {
    Node* temp = head;

    cout << "\nRandom Pointers:\n";

    while (temp != NULL) {

        cout << "Node " << temp->data << " -> ";

        if (temp->random != NULL) {
            cout << temp->random->data;
        } else {
            cout << "NULL";
        }

        cout << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(head, value);
    }

    display(head);

    // Creating random pointers
    Node* temp = head;

    if (temp != NULL && temp->next != NULL) {
        temp->random = temp->next;
    }

    if (temp != NULL && temp->next != NULL &&
        temp->next->next != NULL) {

        temp->next->random = temp->next->next;
    }

    // Intentionally making one random pointer incorrect
    if (temp != NULL && temp->next != NULL) {
        temp->next->random = temp;
    }

    cout << "\nBefore correcting:\n";
    displayRandomPointers(head);

    correctRandomPointer(head);

    cout << "\nAfter correcting:\n";
    displayRandomPointers(head);

    return 0;
}