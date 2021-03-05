#include <stdio.h>
#include <math.h>

int fact (int x) 
{ 
 if (x == 0) return 1;
 return x * fact (x - 1);
}

int main() {
    int x, y, z;

    scanf("%d%d%d", &x, &y, &z);

    float a = 0, b = 0;
    a = log(fabs((y - sqrt(fabs(x))) * (x - (y / (z + x*x/4)))));
    b = x - x*x/fact(3) + pow(x, 5)/fact(5);

    printf("a = %f\nb = %f\n", a, b);
}