#include <stdio.h>

int main() 
{
    double n, m;
    scanf("%lf %lf", &n, &m);

    printf("%.4lf%%\n", m/n*100);
}