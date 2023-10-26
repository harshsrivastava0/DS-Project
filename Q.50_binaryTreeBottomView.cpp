#include <iostream>
#include <queue>
#include <map>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
void bottomView(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    map<int, int> bottomViewMap;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0}); 
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int hd = q.front().second;
        q.pop();
        bottomViewMap[hd] = node->data;
        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }
    for (const auto& pair : bottomViewMap) {
        cout << pair.second << " ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << "Bottom View of Binary Tree: ";
    bottomView(root);
    return 0;
}
