#include <stdio.h>

int main() 
{   
    int n;
    long long int total=0;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++){
        total +=  100 + 50 * (i-1);
    }
    printf("%lld\n", total);
    
    return 0;
}
