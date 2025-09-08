#include <stdio.h>
#include <stdlib.h>


void    swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;

}

int partition(int *arr, int l, int r) {
    int pivot = arr[l];
    int i = l + 1;
    while (i <= r) {
        if (arr[i] <= pivot) i++;
        else {
            swap(&arr[i], &arr[r]);
            r--;
        }
    }
    swap(&arr[i-1], &arr[l]);  // i-1 is last element <= pivot
    return (i - 1);
}

void    quickSort(int *arr, int l, int r) {
    if (l >= r) return ;

    int pivotIdx = partition(arr, l, r);
    quickSort(arr, l, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, r);
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
    quickSort(arr, 0, arrSize - 1);
    printf("array after sorting: ");
    printArray(arr, arrSize);   
}