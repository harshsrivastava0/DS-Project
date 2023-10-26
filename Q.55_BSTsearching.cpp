#include <iostream>
using namespace std;

// Define a structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to search for a value in a binary search tree
bool search(TreeNode* root, int value) {
    if (root == nullptr) {
        return false; // Value not found
    }

    if (root->data == value) {
        return true; // Value found
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

int main() {
    TreeNode* root = nullptr;

    // Insert elements into the binary search tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int valueToSearch = 40;

    if (search(root, valueToSearch)) {
        cout << valueToSearch << " found in the Binary Search Tree." << endl;
    } else {
        cout << valueToSearch << " not found in the Binary Search Tree." << endl;
    }

    return 0;
}
