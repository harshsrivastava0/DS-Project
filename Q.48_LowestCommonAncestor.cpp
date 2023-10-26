#include <iostream>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
TreeNode* findLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root == p || root == q) {
        return root;
    }
    TreeNode* leftLCA = findLowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = findLowestCommonAncestor(root->right, p, q);
    if (leftLCA && rightLCA) {
        return root;
    }
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    TreeNode* lca = findLowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor: " << lca->data << endl;
    return 0;
}
