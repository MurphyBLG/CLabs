#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *in, *out;
    in = fopen("INPUT.txt", "r");

    int *arr, idx = 0;
    arr = (int*) malloc(100);

    while (!feof(in)) {
        int x;
        fscanf(in, "%d", &x);

        arr[idx] = x;
        idx++;
    }

    fclose(in);

    int num;
    scanf("%d", &num);

    for (int i = 0; i < idx; i++) {
        /* printf("%d : ", i);
        for (int k = 0; k < idx; k++) printf("%d ", arr[k]);
        printf("           "); */

        if (arr[i] == num) {
            idx++;
            for (int j = idx - 1; j >= i + 2; j--) {
                arr[j] = arr[j - 1];
            }
            int new;
            scanf("%d", &new);
            arr[i] = new;
            i++;
            arr[i] = num;
        }

        /* for (int i = 0; i < idx; i++) printf("%d ", arr[i]);
        printf("\n"); */ 
    }

    out = fopen("OUTPUT.txt", "w");

    for (int i = 0; i < idx; i++) fprintf(out ,"%d ", arr[i]);

    fclose(out);
    free(arr);
}