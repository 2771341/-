#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
bool isFullBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        return false;
    }

    return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
}
bool isCompleteBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        TreeNode* current = queue[front++];
        if (current == NULL) {
            while (front < rear) {
                if (queue[front++] != NULL) {
                    return false;
                }
            }
        } else {
            queue[rear++] = current->left;
            queue[rear++] = current->right;
        }
    }
    return true;
}
int main() {
    TreeNode* completeTree = createNode(1);
    completeTree->left = createNode(2);
    completeTree->right = createNode(3);
    completeTree->left->left = createNode(4);
    completeTree->left->right = createNode(5);
    completeTree->right->left = createNode(6);
    if (isFullBinaryTree(completeTree)) {
        printf("是满二叉树，");
    } else {
        printf("不是满二叉树，");
    }
    if (isCompleteBinaryTree(completeTree)) {
        printf("是完全二叉树。\n");
    } else {
        printf("不是完全二叉树。\n");
    }
    TreeNode* fullTree = createNode(1);
    fullTree->left = createNode(2);
    fullTree->right = createNode(3);
    fullTree->left->left = createNode(4);
    fullTree->left->right = createNode(5);
    fullTree->right->left = createNode(6);
    fullTree->right->right = createNode(7);
    if (isFullBinaryTree(fullTree)) {
        printf("是满二叉树，");
    } else {
        printf("不是满二叉树，");
    }
    if (isCompleteBinaryTree(fullTree)) {
        printf("是完全二叉树。\n");
    } else {
        printf("不是完全二叉树。\n");
    }
    return 0;
}

