#include <stdio.h>

int main() {
    int num, inc = 1, prev = 0;

    scanf("%d", &num);
    prev = num;

    int num_counter = 0;
    while (1 && num != 0) {
        scanf("%d", &num);
        num_counter++;
        if (num == 0) break;
        if (prev > num) inc = 0;
    }

    if (num_counter == 1) printf("There is only one number\n");
    else if (inc == 1) printf("The sequence is increasing\n");
    else printf("The sequence is non-increasing\n");
}