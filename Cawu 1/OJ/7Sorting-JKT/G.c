#include <stdio.h>

int main(){
    int t,n,x,a[1000]={};
    int i,j,k,l,count;

    scanf("%d",&t);
    for(i = 1; i <= t; i++){
        scanf("%d %d",&n,&x);
        count = 0;
        for(j = 1; j <= n; j++){
            scanf("%d", &a[j]);
        }
            for(k = 1; k <= n; k++){
                for(l = 1; l <= n-k; l++){
                    if(a[l] > a[l+1]){
                        int temp = a[l];
                        a[l] = a[l+1];
                        a[l+1] = temp;
                        count ++;
                    }
                }
            }
        // printf("%d", count);
        printf("Case #%d: %d\n",i,count*x);
    }
}