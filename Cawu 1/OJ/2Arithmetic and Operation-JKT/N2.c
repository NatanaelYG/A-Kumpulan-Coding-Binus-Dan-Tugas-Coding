#include <stdio.h>

int main() 
{
    double n, m;

    scanf("%lf %lf", &n, &m);
    printf("%.2lf%%\n", (n-m)/n * 100);
}