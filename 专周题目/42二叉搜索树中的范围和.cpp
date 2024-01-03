#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}
int rangeSumBST(struct TreeNode* root, int low, int high) {
    if (root == NULL) {
        return 0;
    }
    int sum = (root->val >= low && root->val <= high) ? root->val : 0;
    sum += (root->val > low) ? rangeSumBST(root->left, low, high) : 0;
    sum += (root->val < high) ? rangeSumBST(root->right, low, high) : 0;

    return sum;
}
int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 18);
    int low = 7, high = 15;
    int totalSum = rangeSumBST(root, low, high);
    printf("范围内节点的总和为: %d\n", totalSum);
    return 0;
}

