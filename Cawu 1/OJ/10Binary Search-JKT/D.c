#include <stdio.h>

int ans;

void bin(long long int total[],int l,int r,long long int m){
    int tempright = r;
    int tempL = l;
    while (tempL <= tempright){
        int mid = l + (r-l) / 2;

        if(total[mid] - total[tempL] <= m){
            if(mid - tempL > ans && mid - tempL != 0) ans = mid - tempL;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        if(l > r){
            tempL++;
            l = tempL;
            r = tempright;
        }
    }
}

int main(){
    int t,n,a[100001];
    int i,j,k,l;
    long long int total[100005];
    long long int m;
    
    total[0] = 0;

    scanf("%d", &t);
    for(i = 1;i <= t;i++){
        scanf("%d %lld", &n, &m);
        for(j = 1;j <= n;j++){
            scanf("%d", &a[j]);
            total[j] = a[j] + total[j-1];
        }
        ans = -1;
        bin(total,0,n,m);
        // int ans = search(total,n,m,l,n+1);
        printf("Case #%d: %d\n", i, ans);
    }
}

// int search(int total[], int n,int m,int l,int r){
//     for(int i = 1;i <= n;i++){
//         if(total[i] <= m){
            
//         }
//     }
// }