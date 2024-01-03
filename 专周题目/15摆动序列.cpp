#include <stdio.h>
int max(int* nums, int numssize) {
    if (numssize < 2) {
        return numssize;
    }
    int a = 1;
    int b = 1;
    while (b < numssize && nums[b] == nums[b - 1]) {
        b++;
    }
    if (b == numssize) {
        return a;
    }
    int c = nums[b] - nums[b - 1];
    a++;
    for (; b < numssize; b++) {
        int d = nums[b] - nums[b - 1];
        if ((d > 0 && c <= 0) || (d < 0 && c >= 0)) {
            a++;
            c = d;
        }
    }
    return a;
}
int main() {
    int a[] = {1, 7, 4, 9, 2, 5};
    int b[] = {1, 2, 3, 4, 5};
    int result1 = max(a, sizeof(a) / sizeof(a[0]));
    int result2 = max(b, sizeof(b) / sizeof(b[0]));
    if (result1 == 6) {
        printf("[1, 7, 4, 9, 2, 5]，是摆动序列。\n");
    } else {
        printf("[1, 7, 4, 9, 2, 5]，非摆动序列，需要删除 %d 个元素\n", 6 - result1);
    }
    if (result2 == 5) {
        printf("[1, 2, 3, 4, 5]，是摆动序列。\n");
    } else {
        printf("[1, 2, 3, 4, 5]，非摆动序列，需要删除 %d 个元素\n", 5 - result2);
    }
    return 0;
}

