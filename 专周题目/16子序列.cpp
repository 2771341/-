#include <stdio.h>
#include <stdbool.h>
bool haha(int* A, int ASize, int* B, int BSize) {
    int i = 0, j = 0;
    while (i < ASize && j < BSize) {
        if (A[i] == B[j]) {
            j++;
        }
        i++;
    }
    return j == BSize;
}
int main() {
    int A1[] = {1, 2, 3, 4, 5};
    int B1[] = {2, 4};
    int A2[] = {1, 3, 5, 7};
    int B2[] = {1, 2, 3};
    int A1Size = sizeof(A1) / sizeof(A1[0]);
    int B1Size = sizeof(B1) / sizeof(B1[0]);
    int A2Size = sizeof(A2) / sizeof(A2[0]);
    int B2Size = sizeof(B2) / sizeof(B2[0]);
    if (haha(A1, A1Size, B1, B1Size)) {
        printf("A = [1, 2, 3, 4, 5], B = [2, 4]，是子序列。\n");
    } else {
        printf("A = [1, 2, 3, 4, 5], B = [2, 4]，不是子序列。\n");
    }
    if (haha(A2, A2Size, B2, B2Size)) {
        printf("A = [1, 3, 5, 7], B = [1, 2, 3]，是子序列。\n");
    } else {
        printf("A = [1, 3, 5, 7], B = [1, 2, 3]，不是子序列。\n");
    }
    return 0;
}

