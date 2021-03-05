#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int firstMax = a[0], secondMax = a[0], firstMaxIdx = -1, secondMaxIdx = -1;
    int firstMin = a[0], secondMin = a[0], firstMinIdx = -1, secondMinIdx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] >= firstMax) {
            secondMax = firstMax;
            firstMax = a[i];

            secondMaxIdx = firstMaxIdx;
            firstMaxIdx = i;
        }

        if (a[i] <= firstMin) {
            secondMin = firstMin;
            firstMin = a[i];

            secondMinIdx = firstMinIdx;
            firstMinIdx = i;
        }
    }

    if ((firstMaxIdx + secondMaxIdx) % 2 == 0) {
        a[(firstMaxIdx + secondMaxIdx) / 2] = firstMin * secondMin;
    } else {
        a[(firstMaxIdx + secondMaxIdx) / 2] = firstMin * secondMin;
        a[(firstMaxIdx + secondMaxIdx) / 2 + 1] = firstMin * secondMin;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}