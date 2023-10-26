#include <iostream>
using namespace std;

// Define a structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to create a binary tree
TreeNode* createBinaryTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    return root;
}

// Function to print the binary tree using inorder traversal
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = createBinaryTree();

    cout << "Inorder Traversal of Binary Tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
