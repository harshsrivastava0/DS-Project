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
void topView(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    map<int, int> topViewMap;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0}); 
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int hd = q.front().second;
        q.pop();
        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = node->data;
        }
        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }
    for (const auto& pair : topViewMap) {
        cout << pair.second << " ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);
    cout << "Top View of Binary Tree: ";
    topView(root);
    return 0;
}
