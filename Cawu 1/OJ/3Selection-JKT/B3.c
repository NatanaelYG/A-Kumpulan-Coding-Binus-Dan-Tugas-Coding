#include <stdio.h>

int main() 
{
    int t;
    long long int k, n, m;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        scanf("%lld %lld %lld", &k, &n, &m);
        if (n+m <k){
            printf("Case #%d: no\n",i);
        } else {
            printf("Case #%d: yes\n",i);
        }
    }
}