#include <stdio.h>

int save;

void hao(long long int m, long long int l, long long int r){
    while(l <= r){
        long long int mid = l + (r - l) / 2;
        long long int com = (mid*(mid+1)*((2*mid)+1))/6;
        // printf("mid = %d\n", mid);
        // printf("com = %lld\n", com);
        if(com >= m) {
            save = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
}

int main(){
    long long int t,m;
    scanf("%lld", &t);
    for(int i = 0;i < t;i++){
        scanf("%lld", &m);
        save = -1;
        hao(m,1,1600000);
        printf("Case #%d: %d\n",i+1,save);
    }
    return 0;
}