#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* crNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}
void append(struct Node** hd, int data) {
    struct Node* newNode = crNode(data);
    if (*hd == NULL) {
        *hd = newNode;
        return;
    }
    struct Node* temp = *hd;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void splitList(struct Node* hd, struct Node** odd, struct Node** even) {
    struct Node* od = NULL;
    struct Node* ev = NULL;
    int pos = 1;
    while (hd != NULL) {
        if (pos % 2 == 0) {
            append(&ev, hd->data);
        } else {
            append(&od, hd->data);
        }
        hd = hd->next;
        pos++;
    }
    *odd = od;
    *even = ev;
}
void printList(struct Node* hd) {
    while (hd != NULL) {
        printf("%d ", hd->data);
        hd = hd->next;
    }
    printf("\n");
}
int main() {
    struct Node* hd1 = NULL;
    append(&hd1, 1);
    append(&hd1, 2);
    append(&hd1, 3);
    append(&hd1, 4);
    append(&hd1, 5);
    append(&hd1, 6);
    append(&hd1, 7);
    append(&hd1, 8);
    append(&hd1, 9);
    append(&hd1, 10);
    printf(" ‰»Î¡¥±Ì£∫");
    printList(hd1);
    struct Node* odd = NULL;
    struct Node* even = NULL;
    splitList(hd1, &odd, &even);
    printf("L1 = ");
    printList(odd);
    printf("L2 = ");
    printList(even);
    return 0;
}

