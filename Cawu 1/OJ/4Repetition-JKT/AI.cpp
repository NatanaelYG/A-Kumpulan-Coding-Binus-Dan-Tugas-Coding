#include <stdio.h>
#include <stdbool.h>

int main(){
    int t,n,m[100005];

    scanf("%d",&t);
    for (int i=1;i<=t;i++){
        scanf("%d",&n);
        for (int j=0;j<n;j++){
            scanf("%d",&m[j]);
        }

        int sum1 = 0;
        for (int j=0;j<n;j++){
            sum1 += m[j];
        }
        
        bool valid = false;
        int total = 0;
        for (int j=0;j<n;j++){
            if (total == sum1 - total){
                valid = true;
                break;
            } 
                total += m[j];
        }
            printf("Case #%d: ", i);
            if(valid){
                printf("Yes\n");
            } else {
                printf("No\n");
            }
    }
    return 0;
}