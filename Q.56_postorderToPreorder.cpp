#include <iostream>
#include <vector>
using namespace std;

// Define a structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to convert post-order traversal to pre-order traversal
TreeNode* postToPreOrder(vector<int>& postOrder, int& index) {
    if (postOrder.empty() || index < 0) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(postOrder[index--]);

    // Recursively build the right subtree first
    root->right = postToPreOrder(postOrder, index);

    // Recursively build the left subtree
    root->left = postToPreOrder(postOrder, index);

    return root;
}

// Function to perform pre-order traversal of a binary tree
void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    vector<int> postOrder = {4, 5, 2, 6, 7, 3, 1};
    int index = postOrder.size() - 1;

    TreeNode* root = postToPreOrder(postOrder, index);

    cout << "Pre-order Traversal of the Binary Tree (converted from post-order): ";
    preOrderTraversal(root);

    return 0;
}
