#include <stdio.h>
#include <math.h>

void print_ans (double a1, double b1, double c1, double a2, double b2, double c2) {
    double D = a1*b2 - a2*b1, Dx = c1*b2 - c2*b1, Dy = a1*c2 - a2*c1;

    double x, y;
    x = Dx / D;
    y = Dy / D;
    printf("x = %lf\ny = %lf\n", x, y);
}

int main() {
    double a1, b1, c1, a2, b2, c2;
    scanf("%lf%lf%lf%lf%lf%lf", &a1, &b1, &c1, &a2, &b2, &c2);

    if (fabs(a1*b2 - a2*b1) >= 0.0001) {
        c1 *= -1;
        c2 *= -1;
        print_ans(a1, b1, c1, a2, b2, c2);
    }
}