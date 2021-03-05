#include <stdio.h>

int main() {
    int sum = 0;

    for (int i = 21; i < 100; i += 3) {
        if (i % 10 == 2 || i % 10 == 4 || i % 10 == 8) sum += i;
    }

    printf("%d\n", sum);
}