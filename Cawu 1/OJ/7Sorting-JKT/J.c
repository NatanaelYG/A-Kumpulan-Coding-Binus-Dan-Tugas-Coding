#include <stdio.h>

int main(){
    int t,i,j,k,l,n;
    double a[5005],temp,total,median;

    scanf("%d",&t);
    for(i = 0;i < t;i++){
        scanf("%d",&n);
        total = 0;
        median = 0;
        for(j = 0;j < n;j++){
            scanf("%lf",&a[j]);
            total += a[j];
        }
        for(k = 0;k < n-1;k++){
            for(l = 0;l < n-k-1;l++){
                if (a[l] > a[l+1]){
                    temp = a[l];
                    a[l] = a[l+1];
                    a[l+1] = temp;
                }
            }
        }
        if(n % 2 == 1){
            median = a[n/2];
        } else {
            median = (a[(n/2)-1]+a[n/2])/2;
        }
        printf("Case #%d:\n",i+1);
        printf("Mean : %.2lf\n", total/n);
        printf("Median : %.2lf\n", median);
    }
}