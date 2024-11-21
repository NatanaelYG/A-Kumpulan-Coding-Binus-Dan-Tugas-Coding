#include <stdio.h>

int main()
{
    long long int t,n,m=0,o,min;

    scanf("%lld",&t);
    for (int i=1; i<=t; i++){
        scanf("%lld %lld",&n, &m);
        scanf("%lld",&min);
        for (int j=1; j<n; j++){
            scanf("%lld",&o);
            if (o < min){
                min = o;
            }
        }
            m = m/min;
        printf("Case #%d: %lld\n", i,m);

    }
}