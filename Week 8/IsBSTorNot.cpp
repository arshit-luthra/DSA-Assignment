#include <iostream>
#include <climits>
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
bool isBSTUtil(Node* root, long long minValue, long long maxValue) {
    if (root == NULL)
        return true;
    if (root->data <= minValue || root->data >= maxValue)
        return false;
    return isBSTUtil(root->left, minValue, root->data) &&
           isBSTUtil(root->right, root->data, maxValue);
}
bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}
int main() {
    Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);
    if (isBST(root))
        cout << "The given binary tree is a BST.";
    else
        cout << "The given binary tree is not a BST.";
    return 0;
}