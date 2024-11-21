#include <stdio.h>

int main()
{
    int n,q;
    int c[100000],a,b;
    int i,j;

    scanf("%d",&n);
    for(i = 1;i <= n;i++){
        scanf("%d", &c[i]);
    }

    scanf("%d", &q);
    for(j = 1;j <= q;j++){
        scanf("%d %d", &a, &b);
        c[a] = b;
        printf("Case #%d: ", j);
        for(i = 1;i <= n;i++){
            if (i == n){
            printf("%d\n", c[i]);
            } else {
                printf("%d ", c[i]);
            }
        }
    }
    return 0;
}