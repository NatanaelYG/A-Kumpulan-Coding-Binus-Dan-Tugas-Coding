#include <stdio.h>

int main(){
    int i,j,n,m;

    scanf("%d",&n);
    m = 0;
    for(i=0;i<=n;i++){
        for(j = n-i;j>=0;j--){
            m++;
        }
    }
    printf("%d\n", m);
}