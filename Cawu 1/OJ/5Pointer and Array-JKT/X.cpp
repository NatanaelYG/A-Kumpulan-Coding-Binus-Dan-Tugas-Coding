// #include <stdio.h>

// int main(){
//     int t,n,m,a[100][1000];
//     int i,j,k,l,total;

//     scanf("%d",&t);
//     for(i = 1;i <= t;i++){
//         scanf("%d %d", &n, &m);
//         for(j = 0;j < n;j++){
//             for(k = 0;k < m;k++){
//                 scanf("%d", a[j][k]);
//                 total = a[j][n] + a[j][n-1] + a[j][n-2];
//             }
//         }
//     }
// }

#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    for(int o=1;o<=t;o++){
        int n,m;
        long long int sum=0;
        scanf("%d %d", &n, &m);
        for(int p=0;p<n;p++){
            long long int max=0;
            for(int q=0;q<m;q++){
                long long int temp;
                scanf("%lld",&temp);
                if(max<temp){
                    max=temp;
                }
            }
            sum+=max;
        }
        printf("Case #%d: %lld\n",o,sum);
    }
    return 0;
}