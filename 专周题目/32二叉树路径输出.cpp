#include <stdio.h>
#include <stdlib.h>
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int printPath(struct Node* root, char target) {
    if (root == NULL)
        return 0;
    if (root->data == target || printPath(root->left, target) || printPath(root->right, target)) {
        printf("%c ", root->data);
        return 1;
    }
    return 0;
}
int main() {
    struct Node* r = createNode('A');
    r->left = createNode('B');
    r->right = createNode('C');
    r->left->left = createNode('D');
    r->left->right = createNode('E');
    r->right->left = createNode('F');
    char t = 'F';
    printf("从根节点到叶子节点 '%c' 的路径是: ", t);
    if (!printPath(r, t)) {
        printf("'%c' 不是叶子节点\n", t);
    }
    free(r->left->left);
    free(r->left->right);
    free(r->right->left);
    free(r->left);
    free(r->right);
    free(r);
    return 0;
}

