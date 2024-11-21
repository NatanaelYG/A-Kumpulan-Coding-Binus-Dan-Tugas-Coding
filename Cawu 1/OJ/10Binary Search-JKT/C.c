#include <stdio.h>

int total = 0;

void asd(int m,int l,int r){
    int mid = l + (r - l) / 2;

    if(total >= m){
        total = mid;
        r = mid - 1;
    } else {
        l = mid + 1;
    }
}

int main(){
    int n,q,a,m;
    int i,j,k,l;

    scanf("%d", &n);
    for(i = 0;i < n;i++){
        scanf("%d", &q);
        total += q;
    } 
    scanf("%d", &a);
    asd(m,l,r);
    for(j = 0;j < a;j++){
        scanf("%d", &m);
        printf("Case #%d: %d",j+1,);
    }
}