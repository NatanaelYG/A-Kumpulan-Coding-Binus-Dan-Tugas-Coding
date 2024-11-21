#include <stdio.h>

int main(){
    int t,n,k,m,x;
    int i,j;

    scanf("%d",&t);
    for(i = 1;i <= t;i++){
        // n = piring
        // k = kapasitas
        // m = porsi mula"
        scanf("%d %d %d",&n,&k,&m);
        int makan=m;
        for(j = 0;j < n;j++){
            scanf("%d",&x);
            if(x>makan&&x<=k){
                makan=x;
            }
        }
        printf("Case #%d: %d\n",i,makan);
    }
}