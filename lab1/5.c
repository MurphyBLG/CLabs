#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sqrt(sum + 3 * (n - i));
    }

    printf("%lf\n", sum);
}