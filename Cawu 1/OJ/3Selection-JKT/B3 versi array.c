#include <stdio.h>

int main() 
{
    int t;
    char *ans[101];
    int k, n, m;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d %d %d", &k, &n, &m);
        if (n+m < k){
            ans[i+1]="no";
        } else {
            ans[i+1]="yes";
        }
    }
    for(int i=1;i<=t;i++){
        printf("Case #%d: %s\n",i,ans[i]);
    }
}
