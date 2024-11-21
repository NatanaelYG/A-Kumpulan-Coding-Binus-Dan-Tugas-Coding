#include <stdio.h>

int main(){
    int t,n,b,a[100005],count;
    int i,j,k,l;

    scanf("%d", &t);
    for(i = 1;i <= t;i++){
        scanf("%d %d", &n, &b);
        count = 0;
        for(j = 0;j < n; j++){
            scanf("%d", &a[j]);
            if(a[j] == b || a[j] > b){
                count++;
            }
        }
    printf("Case #%d: %d\n",i,count);
    }
}