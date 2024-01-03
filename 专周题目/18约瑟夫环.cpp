#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void buildCircle(struct Node** head, int total) {
    struct Node* cur = NULL;
    struct Node* prev = NULL;
    for (int i = 1; i <= total; i++) {
        cur = createNode(i);
        if (*head == NULL) {
            *head = cur;
        } else {
            prev->next = cur;
        }
        prev = cur;
    }
    cur->next = *head;
}
void josephus(struct Node** head, int interval) {
    struct Node* cur = *head;
    struct Node* prev = NULL;
    while (cur->next != cur) {
        for (int i = 1; i < interval; i++) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        printf("%d ", cur->data);
        free(cur);
        cur = prev->next;
    }
    *head = cur;
}
int main() {
    int total = 10; 
    int interval = 3; // 报数间隔
    struct Node* head = NULL;
    buildCircle(&head, total);
    printf("淘汰的顺序：");
    josephus(&head, interval);
    printf("\n最后剩下的人：%d\n", head->data);
    return 0;
}

