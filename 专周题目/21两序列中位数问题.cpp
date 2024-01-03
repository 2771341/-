#include <stdio.h>
#include <stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    int* merged = (int*)malloc(sizeof(int) * total);
    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }
    while (i < nums1Size) {
        merged[k++] = nums1[i++];
    }
    while (j < nums2Size) {
        merged[k++] = nums2[j++];
    }
    double median;
    if (total % 2 == 0) {
        median = (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    } else {
        median = merged[total / 2];
    }
    free(merged);
    return median;
}
int main() {
    int nums1[] = {1, 3, 5, 7, 9};
    int nums2[] = {2, 4, 6, 8, 10};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("ÖÐÎ»Êý: %f\n", median);
    return 0;
}

