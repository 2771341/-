#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* l;
    struct Node* r;
};
struct Node* create(int k) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = k;
    n->l = n->r = NULL;
    return n;
}
struct Node* ins(struct Node* root, int k) {
    if (root == NULL) return create(k);

    if (k < root->data)
        root->l = ins(root->l, k);
    else if (k > root->data)
        root->r = ins(root->r, k);
    return root;
}
void path(struct Node* root, int k) {
    if (root == NULL) {
        printf("�ùؼ��ֲ�����\n");
        return;
    }
    printf("����·��: %d ", root->data);
    while (root != NULL && root->data != k) {
        if (k < root->data) {
            printf("-> ������ ");
            root = root->l;
        } else {
            printf("-> ������ ");
            root = root->r;
        }
        if (root != NULL)
            printf("%d ", root->data);
    }
    if (root == NULL)
        printf("-> �ؼ��ֲ�����\n");
    else
        printf("-> ���ҵ��ؼ���\n");
}
int main() {
    struct Node* root = NULL;
    root = ins(root, 50);
    ins(root, 30);
    ins(root, 70);
    ins(root, 20);
    ins(root, 40);
    ins(root, 60);
    ins(root, 80);
    int keyToFind = 60;
    printf("�ڶ����������в��ҹؼ��� %d ��·����\n", keyToFind);
    path(root, keyToFind);
    return 0;
}

