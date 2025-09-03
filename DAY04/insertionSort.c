#include <stdio.h>

void    swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void    insertionSort(int *arr, int arrSize) {
    for (int i = 1; i < arrSize; i++) {
        int j = i - 1, value = arr[i];
        while (j >= 0 && arr[j] > arr[j+1]) {
            swap(&arr[j], &arr[j+1]);
            j--;
        }
    }
}

void    printArray(int *arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arrSize; scanf("%d", &arrSize);
    int arr[arrSize];
    for (int i = 0; i < arrSize; i++)
        scanf("%d", &arr[i]);
    
    printf("array beforesorting: ");
    printArray(arr, arrSize);
    insertionSort(arr, arrSize);
    printf("array after sorting: ");
    printArray(arr, arrSize);
}