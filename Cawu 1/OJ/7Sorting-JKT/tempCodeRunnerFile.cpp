#include <stdio.h>

void asd(){
}

int main(){
    int t,i,j,k,l;
    int n,a[100],temp,total,mean = 0;

    scanf("%d",&t);
    for(i = 1;i <= t;i++){
        scanf("%d",&n);
        total = 0;
        for(j = 1;j <= n;j++){
            scanf("%d",&a[j]);
            total += a[j];
            for(k = 0;k < n-1;k++){
                for(l = 0;l < n-k-1;l++){
                    if (a[l] < a[l+1]){
                        temp = a[l];
                        a[l] = a[l+1];
                        a[l+1] = temp;
                    }
                }
            }
            printf("%d ",a[j]);
        }

        mean = total/n;
        printf("%d", total);
        printf("Case #%d:\n",i);
        printf("Mean : %.2lf\n", (double)mean);
    }
}