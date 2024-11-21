#include <stdio.h>

int main(){
    int t,n,x[1000],y[1000];
    int i,j,k,l;

    scanf("%d",&t);
    for(i = 0; i < t; i++){
        scanf("%d",&n);
        for(j = 0; j < n; j++) {
            scanf("%d",&x[j]);
        }
        for(k = 0; k < n; k++) {
            scanf("%d",&y[k]);
        }
        if (x[j] == y[k]){
            printf("Case #%d: 0",i);
        } else if (x[j] <= y[k]){
            l++;
            printf("Case #%d: %d",i,l);
        }
    }
}