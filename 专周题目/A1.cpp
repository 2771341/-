#include <stdio.h>
#include <string.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
            printf("Shell Sort Step: ");
            printArray(arr, n);
        }
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        printf("Quick Sort Step: ");
        for (int i = low; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
        printf("Quick Sort Step: ");
        for (int i = low; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
        printf("Heap Sort Step %d: [", n - i);
        for (int j = 0; j < n; j++) {
            printf("%d", arr[j]);
            if (j < n - 1) printf(", ");
        }
        printf("]\n");
    }
}
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        printf("Merge Sort (Divided): [");
        for (int i = l; i <= r; i++) {
            printf("%d", arr[i]);
            if (i < r) printf(", ");
        }
        printf("]\n");
        merge(arr, l, m, r); 
        printf("Merge Sort (Merged): [");
        for (int i = l; i <= r; i++) {
            printf("%d", arr[i]);
            if (i < r) printf(", ");
        }
        printf("]\n");
    }
}
void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);

        printf("Sorting array by digit %d: ", exp);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
int main() {
    int arr[] = {6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("原始数组: ");
    printArray(arr, n);
    // 希尔排序
    shellSort(arr, n);
    printf("希尔排序后的数组: ");
    printArray(arr, n);
    // 快速排序
    quickSort(arr, 0, n - 1);
    printf("快速排序后的数组: ");
    printArray(arr, n);
    // 堆排序
    heapSort(arr, n);
    printf("堆排序后的数组: ");
    printArray(arr, n);
    // 归并排序
    mergeSort(arr, 0, n - 1);
    printf("归并排序后的数组: ");
    printArray(arr, n);
    // 计数排序
    radixSort(arr, n);
    printf("基数排序后的数组: ");
    printArray(arr, n);
    return 0;
}

