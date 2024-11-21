#include <stdio.h>

int main() {
    double x, y;

    scanf("%lf %lf", &x, &y);

    for (int i = 1; i <= 3; i++) {
        x = x * (100+y)/100;
    }
    printf("%.2lf\n", x);
}