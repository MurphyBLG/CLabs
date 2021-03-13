#include <stdio.h>
#include <stdlib.h>

void shiftToTheRight (int *arr, int from, int *to) {
    *to += 1;
    for (int j = *to - 1; j >= from; j--) {
        arr[j] = arr[j - 1];
    }
}

void shiftToTheLeft (int *arr, int from, int *to) {
    *to -= 1;
    for (int j = from; j < *to; j++) {
        arr[j] = arr[j + 1];
    }
}

void findAndDel (int *arr, int *arr_size) {
    for (int i = 1; i < *arr_size - 1; i++) {
        if (arr[i - 1] % 2 == 0 && arr[i + 1] % 2 == 0 && arr[i] % 2 == 1) {
            shiftToTheLeft(arr, i, arr_size);
            break;
        }
    }
}


void insertZeros (int *arr, int *arr_size, int k) {
    for (int i = 0; i < *arr_size; i++) {
        if (arr[i] == k) {
            shiftToTheRight(arr, i, arr_size);
            arr[i] = 0;
            i += 2;
            shiftToTheRight(arr, i, arr_size);
            arr[i] = 0;
        }
    }
} 

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) printf("%d ", *(arr + i));
}

int main() {
    int size, k;
    scanf("%d%d", &size, &k);
    int *arr;
    arr = (int*) calloc(size * 2, sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    insertZeros(arr, &size, k);

    findAndDel(arr, &size);

    printArray(arr, size);
}