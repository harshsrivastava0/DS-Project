#include <iostream>
using namespace std;

// Define a structure for an AVL tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

// Function to get the height of a node
int getHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Function to update the height of a node based on its children
void updateHeight(TreeNode* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Function to perform a right rotation
TreeNode* rotateRight(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation
TreeNode* rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to balance an AVL tree
TreeNode* balance(TreeNode* node) {
    int balanceFactor = getHeight(node->left) - getHeight(node->right);

    if (balanceFactor > 1) {
        if (node->data < node->left->data) {
            return rotateRight(node);
        } else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    if (balanceFactor < -1) {
        if (node->data > node->right->data) {
            return rotateLeft(node);
        } else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

    return node;
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

// Function to find the node with the minimum value in an AVL tree
TreeNode* findMin(TreeNode* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

// Function to delete a node with a given value from an AVL tree
TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with the value to be deleted found

        if (root->left == nullptr || root->right == nullptr) {
            TreeNode* temp = (root->left) ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }

            delete temp;
        } else {
            TreeNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr) {
        return root;
    }

    updateHeight(root);
    return balance(root);
}

// Function to perform an in-order traversal of an AVL tree
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;

    // Insert elements into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "In-order Traversal of the AVL Tree (before deletion): ";
    inOrderTraversal(root);
    cout << endl;

    int valueToDelete = 30;
    root = deleteNode(root, valueToDelete);

    cout << "In-order Traversal of the AVL Tree (after deletion of " << valueToDelete << "): ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
