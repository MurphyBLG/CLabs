#include <stdio.h>
#include <limits.h>

int maxForwardIdx (int a[], int size) {
    int max = a[0], idx = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
            idx = i;
        } 
    }
    
    return idx;
}

int maxBackwardIdx (int a[], int size) {
    int max = a[0], idx = 0;

    for (int i = size - 1; i >= 0; i--) {
        if (a[i] > max) {
            max = a[i];
            idx = i;
        } 
    }
    
    return idx;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int  firstMaxIdx = maxForwardIdx(a, n), lastMaxIdx = maxBackwardIdx(a, n);
    int firstMin = a[0], lastMin = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] <= firstMin) {
            lastMin = firstMin;
            firstMin = a[i];
        }
    }

    if ((firstMaxIdx + lastMaxIdx) % 2 == 0) {
        a[(firstMaxIdx + lastMaxIdx) / 2] = firstMin * lastMin;
    } else {
        a[(firstMaxIdx + lastMaxIdx) / 2] = firstMin * lastMin;
        a[(firstMaxIdx + lastMaxIdx) / 2 + 1] = firstMin * lastMin;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}