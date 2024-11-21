#include <stdio.h>

int asd(int a, int b){
    if (a == b || a == 1){
        return a;
    } else if(a % 2 != 0){
        return asd(a*3+1, b);
    } else if(a % 2 == 0){
        return asd(a/2, b);
    }
}

int main(){
    int t,a,b,i;

    scanf("%d",&t);
    for(i = 1;i <= t;i++){
        scanf("%d %d",&a,&b);
        if (asd(a,b) == b){
            printf("Case #%d: YES\n",i);
        } else {
            printf("Case #%d: NO\n",i);
        }
    }
    return 0;
}