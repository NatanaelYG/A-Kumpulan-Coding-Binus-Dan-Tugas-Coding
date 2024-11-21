#include <stdio.h>

int total = 0;

int asd(int n){
    total++;
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return asd(n-1) + asd(n-2);
    }
}

int main(){
    int t,n,i;

    scanf("%d",&t);
    for (i = 1; i <= t; i++){
    scanf("%d",&n);
    asd(n);
    printf("Case #%d: %d\n",i ,total);
    total = 0;
    }

    return 0;
}