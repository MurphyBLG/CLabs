#include <stdio.h>
#include <stdlib.h>

void shiftToTheRight (int *arr, int from, int *to) {
    *to += 1;
    for (int j = *to - 1; j >= from; j--) {
        arr[j] = arr[j - 1];
    }
}

void insertNew (int *arr, int *size, int *idx) {
    shiftToTheRight(arr, *idx, size);
    int new;
    scanf("%d", &new);
    arr[*idx] = new;
    *idx += 1;
}

int main(){
    FILE *in, *out;
    in = fopen("INPUT.txt", "r");

    int *arr, size = 0;
    arr = (int*) malloc(100);

    while (!feof(in)) {
        int x;
        fscanf(in, "%d", &x);

        arr[size] = x;
        size++;
    }

    fclose(in);

    int num;
    scanf("%d", &num);

    for (int i = 0; i < size; i++) {
        if (arr[i] == num) insertNew(arr, &size, &i);
    }

    out = fopen("OUTPUT.txt", "w");
    for (int i = 0; i < size; i++) fprintf(out ,"%d ", arr[i]);
    fclose(out);
    
    free(arr);
}