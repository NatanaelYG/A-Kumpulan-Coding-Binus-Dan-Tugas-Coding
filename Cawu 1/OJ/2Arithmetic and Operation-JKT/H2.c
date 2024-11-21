#include <stdio.h>

int main()
{
    double a, b, c, d, e, f, g, h, i, j, k, l;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    scanf("%lf %lf %lf %lf", &e, &f, &g, &h);
    scanf("%lf %lf %lf %lf", &i, &j, &k, &l);

    printf("%.2lf\n", a*2 + b*4/2 + c*6/3 + d*4/4);
    printf("%.2lf\n", e*2 + f*4/2 + g*6/3 + h*4/4);
    printf("%.2lf\n", i*2 + j*4/2 + k*6/3 + l*4/4);
}