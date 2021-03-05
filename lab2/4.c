#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int matr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &matr[i][j]);

    int sum[n];
    for (int i = 0; i < n; i++) {
        sum[i] = -1 * matr[i][i];
        for (int j = 0; j <= i; j++) sum[i] += matr[i][j] + matr[j][i];
    }

    for (int i = 0; i < n; i++) printf("%d ", sum[i]);

    printf("\n");
}