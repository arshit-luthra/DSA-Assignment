
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool checkDuplicate(Node* root, unordered_set<int>& s) {
    if (root == NULL)
        return false;

    if (s.find(root->data) != s.end())
        return true;

    s.insert(root->data);

    return checkDuplicate(root->left, s) || checkDuplicate(root->right, s);
}

int main() {
    Node* root = new Node{1, NULL, NULL};
    root->left = new Node{2, NULL, NULL};
    root->right = new Node{3, NULL, NULL};
    root->left->left = new Node{2, NULL, NULL};
    root->left->right = new Node{4, NULL, NULL};

    unordered_set<int> s;

    if (checkDuplicate(root, s))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}
