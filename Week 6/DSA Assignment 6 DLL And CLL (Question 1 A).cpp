#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtEnd(Node*& head, int value) {
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

void insertAfter(Node*& head, int key, int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found." << endl;
        return;
    }

    Node* newNode = new Node(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    insertAtBeginning(head, 20);
    insertAtBeginning(head, 10);

    insertAtEnd(head, 30);

    insertAfter(head, 20, 25);

    cout << "Doubly Linked List: ";
    display(head);

    return 0;
}