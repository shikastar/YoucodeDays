#include <stdio.h>
#include <stdlib.h>

void    mergeSort(int *arr, int l, int r) {
    if (l >= r) return ;

    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    // two Sorted list
    int n = mid - l + 1, m = r - mid;
    int *left = malloc(sizeof(int) * n);
    int *right = malloc(sizeof(int) * m);
    for (int i = l, k = 0; i <= mid; i++, k++) left[k] = arr[i];
    for (int i = mid + 1, k = 0; i <= r; i++, k++) right[k] = arr[i];

    int leftIdx = 0, rightIdx = 0;
    for (int i = l; i <= r; i++) {
        if (leftIdx >= n) arr[i] = right[rightIdx++];
        else if (rightIdx >= m) arr[i] = left[leftIdx++];
        else if (left[leftIdx] > right[rightIdx]) arr[i] = right[rightIdx++];
        else arr[i] = left[leftIdx++];
    }
}


void    printArray(int *arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    printf("Enter arr Size :");
    int arrSize; scanf("%d", &arrSize);
    int arr[arrSize];
    for (int i = 0; i < arrSize; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("array beforesorting: ");
    printArray(arr, arrSize);
    mergeSort(arr, 0, arrSize - 1);
    printf("array after sorting: ");
    printArray(arr, arrSize);
}