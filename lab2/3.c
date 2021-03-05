#include <stdio.h>

void findAndDel (int arr[], int arr_size) {
    int pos = -1;
    for (int i = 1; i < arr_size - 1; i++) {
        if (arr[i - 1] % 2 == 0 && arr[i + 1] % 2 == 0 && arr[i] % 2 == 1) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        for (int i = pos; i < arr_size - 1; i++) arr[i] = arr[i + 1];
    }
}

void insertZeros (int arr[], int arr_size, int k, int newArr[]) {
    int pos = 0;
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == k) {
            newArr[pos] = 0;
            newArr[pos + 1] = arr[i];
            newArr[pos + 2] = 0;
            pos += 3;
        } else {
            newArr[pos] = arr[i];
            pos++;
        }
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int kCount = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == k) kCount++;
    }

    int newSize = n + kCount * 2;
    int new[newSize];
    
    insertZeros(a, newSize, k, new);

    findAndDel(new, newSize);

    for (int i = 0; i < newSize - 1; i++) printf("%d ", new[i]);

    printf("\n");
}