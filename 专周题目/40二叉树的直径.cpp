#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
int max(int a, int b) {
    return (a > b) ? a : b;
}
int height(TreeNode* root, int* diameter) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);
    *diameter = max(*diameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}
int treeDiameter(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int diameter = 0;
    height(root, &diameter);
    return diameter;
}
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int main() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->right->right->right = newNode(11);
    root->right->right->right->left = newNode(12);
    root->right->right->right->left->right = newNode(13);
    int result = treeDiameter(root);
    printf("二叉树的直径是：%d\n", result);
    return 0;
}

