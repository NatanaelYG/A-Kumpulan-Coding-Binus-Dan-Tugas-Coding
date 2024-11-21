#include <stdio.h>

long long int asd(int n,long long int x, long long int y){
    if(n == 0){
        return x;
    } else if(n == 1){
        return y;
    } else if (n != 0){
        return asd(n-1,x,y) - asd(n-2,x,y);
    }
}

int main(){
    int t,n,i;
    long long int x,y;

    scanf("%d",&t);
    for(i = 1;i <= t;i++){
        scanf("%d %lld %lld",&n,&x,&y);
        printf("Case #%d: %lld\n",i,asd(n,x,y));
    }
    return 0;
}