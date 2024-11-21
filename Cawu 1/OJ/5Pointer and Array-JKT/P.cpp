#include <stdio.h>

int main(){
    int i,j,k;
    int n,count = 0,counts[105]={0},temp;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &temp);
            counts[temp]++;
        }
    }

    for(i = 1;i <= n;i++){
        if(counts[i]<n){
            count++;
        }
    }
    printf("%d\n",count);
}