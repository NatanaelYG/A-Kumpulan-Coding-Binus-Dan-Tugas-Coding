#include <stdio.h>

int main(){
    int t,n,a,i,j,k,hasil;

    scanf("%d",&t);
    for(i = 0; i < t; i++){
        scanf("%d",&n);
        hasil = 0;
        for(j = 0; j < n; j++){
            scanf("%d",&a);
            hasil = hasil+ a;
        }
        printf("Case #%d: %d\n",i+1,hasil);
    }
}