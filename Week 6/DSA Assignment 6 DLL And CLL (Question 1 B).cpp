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

void deleteNode(Node*& head, int value) {
    if (head == NULL) {
        cout << "Doubly Linked List is empty." << endl;
        return;
    }

    Node* temp = head;

    // Search for the node
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node " << value << " not found." << endl;
        return;
    }

    // If the node is the head node
    if (temp == head) {
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }
    }
    else {
        temp->prev->next = temp->next;

        // If the node is not the last node
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }

    delete temp;

    cout << "Node " << value << " deleted successfully." << endl;
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
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;

    head->next->next = new Node(60);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    int value;

    cout << "Original Doubly Linked List: ";
    display(head);

    cout << "Enter the node value to delete: ";
    cin >> value;

    deleteNode(head, value);

    cout << "Updated Doubly Linked List: ";
    display(head);

    return 0;
}