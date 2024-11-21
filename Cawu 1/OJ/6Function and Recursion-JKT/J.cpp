#include <stdio.h>

long long int count;

long long int asd(long long int n){
    count++;
    if (n == 1){
        return n;
    }  else if (n % 2 == 0){
        return asd(n/2);
    } else if (n % 2 == 1){
        return asd((n*3)+1);
    }
}

int main(){
    long long int i,t,n;

    scanf("%lld",&t);
    for(i = 1; i <= t; i++){
        scanf("%lld",&n);
        count = 0;
        asd(n);
        if(count % 2 == 0){
            printf("Case #%lld: Jojo\n",i);
        } else if(count % 2 == 1){
            printf("Case #%lld: Lili\n",i);
        } 
    }
    return 0;
}