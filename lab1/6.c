#include <stdio.h>
#include <math.h>

float sum_of_array(float array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += array[i];

    return sum;
}

int main() {
    float e;
    printf("Enter e: ");
    scanf("%f", &e);

    int n;
    printf("Enter amount of check array elements: ");
    scanf("%d", &n);
    
    float a[n];
    float result = 0;
    for (int i = 1; ; i++) {
        float add = pow(-1, i + 1) / (i * (i + 1) * (i + 2));

        if (i >= 4 && fabs(add + sum_of_array(a, n)) < e) {
            break;
        }

        a[i % n] = add;
        result += add; 
    }

    printf("%f\n", result);
}
