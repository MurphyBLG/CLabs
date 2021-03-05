#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int prev = a[1], up = 1, pos_count = 0, even_count = 0;
    double even_avg = 0;    
    for (int i = 0; i < n; i++) {
        if (a[i] < prev && i % 2 != 0) up = 0;

        if (a[i] % 2 == 0) {
            even_avg += a[i];
            even_count++;
        }

        if (a[i] > 0) pos_count++;
    }

    if (n >= 4 && up == 1) {
        even_avg /= even_count;
        printf("%lf\n", even_avg);
    } else {
        printf("%d\n", pos_count);
    }
}