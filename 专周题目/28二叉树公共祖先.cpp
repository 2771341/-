#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct Node* ancestor(struct Node* root, struct Node* p, struct Node* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }
    struct Node* left = ancestor(root->left, p, q);
    struct Node* right = ancestor(root->right, p, q);
    if (left != NULL && right != NULL) {
        return root;
    }
    return (left != NULL) ? left : right;
}
int main() {
    struct Node* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->right->left = createNode(0);
    root->right->right = createNode(8);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);
    struct Node* n1 = root->left;
    struct Node* n2 = root->right;
    struct Node* res = ancestor(root, n1, n2);
    if (res != NULL) {
        printf("祖先的值：%d\n", res->val);
    } else {
        printf("未找到祖先\n");
    }
    return 0;
}

