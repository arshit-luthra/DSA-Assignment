#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        cout << "Duplicate element not allowed\n";
    return root;
}
Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
Node* deleteNode(Node* root, int value) {
    if (root == NULL)
        return NULL;
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
int minDepth(Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL)
        return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node* root = NULL;
    int choice, value;
    do {
        cout << "\n\n--- BST MENU ---";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Maximum Depth";
        cout << "\n4. Minimum Depth";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter element to delete: ";
                cin >> value;
                if (root == NULL)
                    cout << "Tree is empty\n";
                else
                    root = deleteNode(root, value);
                break;
            case 3:
                cout << "Maximum Depth: " << maxDepth(root);
                break;
            case 4:
                cout << "Minimum Depth: " << minDepth(root);
                break;
            case 5:
                cout << "Inorder Traversal: ";
                inorder(root);
                break;
            case 6:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice";
        }
    } while (choice != 6);
    return 0;
}