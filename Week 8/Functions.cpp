#include <iostream>
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
    return root;
}
Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}
Node* searchNonRecursive(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}
Node* findMax(Node* root) {
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}
Node* inorderSuccessor(Node* root, int key) {
    Node* current = searchRecursive(root, key);
    if (current == NULL)
        return NULL;
    if (current->right != NULL)
        return findMin(current->right);
    Node* successor = NULL;
    while (root != NULL) {
        if (key < root->data) {
            successor = root;
            root = root->left;
        }
        else if (key > root->data) {
            root = root->right;
        }
        else
            break;
    }
    return successor;
}
Node* inorderPredecessor(Node* root, int key) {
    Node* current = searchRecursive(root, key);
    if (current == NULL)
        return NULL;
    if (current->left != NULL)
        return findMax(current->left);
    Node* predecessor = NULL;
    while (root != NULL) {
        if (key > root->data) {
            predecessor = root;
            root = root->right;
        }
        else if (key < root->data) {
            root = root->left;
        }
        else
            break;
    }
    return predecessor;
}
int main() {
    Node* root = NULL;
    int n, value, key;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }
    cout << "Enter element to search: ";
    cin >> key;
    if (searchRecursive(root, key))
        cout << "Element found using recursive search\n";
    else
        cout << "Element not found using recursive search\n";
    if (searchNonRecursive(root, key))
        cout << "Element found using non-recursive search\n";
    else
        cout << "Element not found using non-recursive search\n";
    Node* minimum = findMin(root);
    Node* maximum = findMax(root);
    if (minimum)
        cout << "Minimum element: " << minimum->data << endl;
    if (maximum)
        cout << "Maximum element: " << maximum->data << endl;
    Node* successor = inorderSuccessor(root, key);
    Node* predecessor = inorderPredecessor(root, key);
    if (successor)
        cout << "Inorder Successor: " << successor->data << endl;
    else
        cout << "Inorder Successor does not exist\n";
    if (predecessor)
        cout << "Inorder Predecessor: " << predecessor->data << endl;
    else
        cout << "Inorder Predecessor does not exist\n";
    return 0;
}