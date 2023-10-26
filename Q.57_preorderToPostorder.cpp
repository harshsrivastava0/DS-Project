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

// Function to convert pre-order traversal to post-order traversal
TreeNode* preToPostOrder(vector<int>& preOrder, int& index, int minValue, int maxValue) {
    if (index >= preOrder.size()) {
        return nullptr;
    }

    int current = preOrder[index];
    if (current < minValue || current > maxValue) {
        return nullptr;
    }

    index++;

    TreeNode* root = new TreeNode(current);

    root->left = preToPostOrder(preOrder, index, minValue, current);
    root->right = preToPostOrder(preOrder, index, current, maxValue);

    return root;
}

// Function to perform post-order traversal of a binary tree
void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> preOrder = {1, 2, 4, 5, 3, 6, 7};
    int index = 0;

    TreeNode* root = preToPostOrder(preOrder, index, INT_MIN, INT_MAX);

    cout << "Post-order Traversal of the Binary Tree (converted from pre-order): ";
    postOrderTraversal(root);

    return 0;
}
