#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 2e6;

int getMinimum(int *arr, int arrSize) {
    int mn = 2e9;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < mn) mn = arr[i];    
    }
    return mn;
}

void    countSort(int *arr, int arrSize) {
    int cnt[MAX];
    memset(cnt, 0, sizeof(cnt));

    int offset = getMinimum(arr, arrSize);       // to add extra offset to numbers if it minimum is negative
    if (offset > 0) offset = 0;
    offset = -offset;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] + offset >= MAX) {
            printf("numbers should not exceed %d.\n", MAX - offset);
            return ;
        }
        cnt[arr[i] + offset]++;
    }
    
    int k = 0;
    for (int i = 0; i < MAX; i++) {
        while (cnt[i] > 0) {
            cnt[i]--;
            arr[k++] = i - offset;
        }
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
    printf("array after sorting: ");
    countSort(arr, arrSize);
    printArray(arr, arrSize);
}
