#include <stdio.h>
#include <math.h>

int minTurn(int n, int k)
{
    if (n%2 == 0){
        n++;
    }
    if (k/2 < (n - k )/2){
        return (k)/2;
    }else{
        return (n-k)/2;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++){
        int n, k;
        scanf("%d %d", &n, &k);
        printf("Case #%d: %d\n",i,minTurn(n,k));
    }
    return 0;
}