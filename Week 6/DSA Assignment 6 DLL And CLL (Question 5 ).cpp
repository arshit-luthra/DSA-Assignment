#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
        up = NULL;
        down = NULL;
    }
};

Node* convertToLinkedList(int matrix[][3], int rows, int cols) {
    Node* nodes[3][3];

    // Create nodes
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            nodes[i][j] = new Node(matrix[i][j]);
        }
    }

    // Connect nodes
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (j < cols - 1)
                nodes[i][j]->next = nodes[i][j + 1];

            if (j > 0)
                nodes[i][j]->prev = nodes[i][j - 1];

            if (i > 0)
                nodes[i][j]->up = nodes[i - 1][j];

            if (i < rows - 1)
                nodes[i][j]->down = nodes[i + 1][j];
        }
    }

    return nodes[0][0];
}

void display(Node* head, int rows) {
    Node* rowStart = head;

    for (int i = 0; i < rows && rowStart != NULL; i++) {

        Node* temp = rowStart;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
        rowStart = rowStart->down;
    }
}

int main() {
    const int ROWS = 3;
    const int COLS = 3;

    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = convertToLinkedList(matrix, ROWS, COLS);

    cout << "2D Doubly Linked List:\n";
    display(head, ROWS);

    return 0;
}