#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* crNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = n->prev = n;
    return n;
}
void insert(struct Node* hd, int data) {
    struct Node* newNode = crNode(data);
    newNode->next = hd->next;
    newNode->prev = hd;
    hd->next->prev = newNode;
    hd->next = newNode;
}
void printSet(struct Node* hd, const char* nm) {
    printf("集合 %s = {", nm);
    struct Node* cur = hd->next;
    while (cur != hd) {
        printf("%d", cur->data);
        if (cur->next != hd) {
            printf(", ");
        }
        cur = cur->next;
    }
    printf("}\n");
}
void intersection(struct Node* s1, struct Node* s2) {
    struct Node* cur1 = s1->next;
    while (cur1 != s1) {
        struct Node* cur2 = s2->next;
        while (cur2 != s2) {
            if (cur1->data == cur2->data) {
                printf("%d ", cur1->data);
                break;
            }
            cur2 = cur2->next;
        }
        cur1 = cur1->next;
    }
}
void unionSet(struct Node* s1, struct Node* s2) {
    struct Node* cur1 = s1->next;
    while (cur1 != s1) {
        printf("%d ", cur1->data);
        cur1 = cur1->next;
    }
    struct Node* cur2 = s2->next;
    while (cur2 != s2) {
        if (cur2->data != s1->next->data) {
            printf("%d ", cur2->data);
        }
        cur2 = cur2->next;
    }
}
int main() {
    struct Node* set1 = crNode(-1); // 集合 1 的头结点
    struct Node* set2 = crNode(-1); // 集合 2 的头结点
    int arr1[] = {8, 9, 10, 11, 12};
    int arr2[] = {10, 11, 12, 13, 14};
    for (int i = 0; i < 5; ++i) {
        insert(set1, arr1[i]);
        insert(set2, arr2[i]);
    }
    printf("集合操作结果：\n");
    printf("交集：");
    intersection(set1, set2);
    printf("\n并集：");
    unionSet(set1, set2);
    printf("\n");
    return 0;
}

