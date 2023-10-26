#include <iostream>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
int findDiameter(TreeNode* root, int& diameter) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = findDiameter(root->left, diameter);
    int rightHeight = findDiameter(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    findDiameter(root, diameter);
    return diameter;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    int diameter = diameterOfBinaryTree(root);
    cout << "Diameter of the Binary Tree: " << diameter << endl;
    return 0;
}
