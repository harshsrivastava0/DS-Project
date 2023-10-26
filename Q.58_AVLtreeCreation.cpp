#include <iostream>
using namespace std;

// Define a structure for an AVL tree node
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

// Function to calculate the height of an AVL node
int getHeight(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Function to update the height of an AVL node
void updateHeight(AVLNode* node) {
    if (node == nullptr) {
        return;
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Function to perform right rotation
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform left rotation
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to balance an AVL tree
AVLNode* balance(AVLNode* node) {
    if (node == nullptr) {
        return node;
    }

    int balanceFactor = getHeight(node->left) - getHeight(node->right);

    if (balanceFactor > 1) {
        if (node->left && node->data > node->left->data) {
            return rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balanceFactor < -1) {
        if (node->right && node->data < node->right->data) {
            return leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

// Function to insert a value into an AVL tree
AVLNode* insert(AVLNode* root, int value) {
    if (root == nullptr) {
        return new AVLNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        // Duplicate values are not allowed
        return root;
    }

    updateHeight(root);
    return balance(root);
}

// Function to perform an in-order traversal of an AVL tree
void inOrderTraversal(AVLNode* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    AVLNode* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25); // Unbalanced insertion

    cout << "In-order Traversal of the AVL Tree: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
