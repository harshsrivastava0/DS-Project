#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Define a structure for a binary expression tree node
struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to create a binary expression tree from a postfix expression
TreeNode* createExpressionTree(const string& postfix) {
    stack<TreeNode*> nodeStack;

    for (char c : postfix) {
        if (isOperator(c)) {
            TreeNode* rightOperand = nodeStack.top();
            nodeStack.pop();
            TreeNode* leftOperand = nodeStack.top();
            nodeStack.pop();

            string expression = string(1, c);

            TreeNode* operatorNode = new TreeNode(expression);
            operatorNode->left = leftOperand;
            operatorNode->right = rightOperand;

            nodeStack.push(operatorNode);
        } else {
            TreeNode* operandNode = new TreeNode(string(1, c));
            nodeStack.push(operandNode);
        }
    }

    return nodeStack.top();
}

// Function to evaluate a binary expression tree
int evaluateExpressionTree(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    if (!isOperator(root->data[0])) {
        // Leaf node (operand)
        return stoi(root->data);
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    switch (root->data[0]) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0;
    }
}

// Function to perform an in-order traversal of a binary expression tree
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    if (isOperator(root->data[0])) {
        cout << "(";
    }

    inOrderTraversal(root->left);
    cout << root->data;
    inOrderTraversal(root->right);

    if (isOperator(root->data[0])) {
        cout << ")";
    }
}

int main() {
    string postfixExpression = "34*2+";
    TreeNode* root = createExpressionTree(postfixExpression);

    cout << "In-order Traversal of the Binary Expression Tree: ";
    inOrderTraversal(root);
    cout << endl;

    int result = evaluateExpressionTree(root);
    cout << "Result of the Expression: " << result << endl;

    return 0;
}
