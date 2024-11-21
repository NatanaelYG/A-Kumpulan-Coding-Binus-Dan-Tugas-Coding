#include <stdio.h>

int main()
{
    int n;
    long long int total = 0;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        total += 100 + 50 * i;
    }
    printf("%lld\n", total);
}