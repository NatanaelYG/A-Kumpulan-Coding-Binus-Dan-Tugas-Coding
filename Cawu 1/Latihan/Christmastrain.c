#include <stdio.h>

int main(){
    int t,n,x,a[1005];
    int i,j,k,l;
    int temp = 0,count = 0;

    scanf("%d", &t);
    for(i = 1;i <= t;i++){
        scanf("%d %d", &n, &x);
        for(j = 1;j <= n;j++){
            scanf("%d", &a[j]);
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                count++;
            }
        }
        printf("%d", count);
    }
}