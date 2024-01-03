#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
bool isSameTree(TreeNode* s, TreeNode* t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    return (s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}
bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s) return false;
    if (isSameTree(s, t)) return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}
int main() {
    TreeNode* root1 = createNode(3);
    root1->left = createNode(4);
    root1->right = createNode(5);
    root1->left->left = createNode(1);
    root1->left->right = createNode(2);
    TreeNode* root2 = createNode(4);
    root2->left = createNode(1);
    root2->right = createNode(2);
    if (isSubtree(root1, root2)) {
        printf("包含相同结构子树\n");
    } else {
        printf("不包含相同结构子树\n");
    }
    return 0;
}

