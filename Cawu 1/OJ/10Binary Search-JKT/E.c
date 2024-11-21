#include <stdio.h>

int ans;

void bin(long long int total[],int a,int l,int r){
    int tempr = r;
    int templ = l;

    while(templ <= tempr){
        int mid = l + (r - l) / 2;

        if(total[mid] - total[templ] <= a){
            if(mid - templ > ans && mid - templ != 0) ans = mid - templ;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        if(l > r){
            l = templ;
            r = tempr;
            templ++;
        }
    }
}

int main(){
    int n,q,a;
    int i,j,k,l;
    long long int m[10005], total[10005]; 

    total[0] = 0;

    scanf("%d", &n);
    for(i = 1;i <= n;i++){
        scanf("%lld",&m[i]);
        total[i] = m[i] + total[i-1];
    }
    scanf("%d", &q);
    ans = -1;
    for(j = 1;j <= q;j++){
        scanf("%d", &a);
        printf("Case #%d: %d", j, ans);
    }

}