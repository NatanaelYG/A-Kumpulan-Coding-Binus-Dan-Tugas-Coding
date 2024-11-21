#include <stdio.h>

int count;
int asd(int n){
    if (n % 3 == 0 && n != 0) {
        count++;
    }
    if (n == 0){
        return 1;
    }
    else if (n == 1) {
        return 2;
        }
    else if (n % 5 == 0) {
        return n * 2;
        }
    else {
        return asd(n-1) + n + asd(n-2)+ n-2;
    }
}

int main(){
    int t,n,i;

    scanf("%d",&t);
    for(i = 1; i <= t; i++){
        count = 0;
        scanf("%d",&n);
        printf("Case #%d: %d ",i,asd(n));
        printf("%d\n", count);
    }
    return 0;
}

