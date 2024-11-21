#include <stdio.h>

void asd(int n,int mmr[]){
    int i,j,temp;

    for(i = 1;i <= n;i++){
        for(j = 1;j <= n - i;j++){
            if(mmr[j] > mmr[j+1]){
                temp = mmr[j];
                mmr[j] = mmr[j+1];
                mmr[j+1] = temp;
            }
        }
    }
}

int main(){
    int c,n,mmr[10005],f;
    int i,j,k,l,flag;

    scanf("%d", &c);
    for(i = 1;i <= c;i++){
        scanf("%d", &n);
        for(j = 1;j <= n;j++){
            scanf("%d", &mmr[j]);
        }
        scanf("%d", &f);

            printf("CASE #%d: ", i);
            asd(n,mmr);
            flag = 0;
        for(j = 1;j <= n; j++){
            if(mmr[j] == f){
                if(j == n){
                    printf("%d %d\n", mmr[j-1], mmr[j]);
                    flag = 1;
                    break;
                } else{
                    printf("%d %d\n", mmr[j], mmr[j+1]);
                    flag = 1;
                    break;
                } 
            }
        }
                if(flag == 0){
                    printf("-1 -1\n");
                }
    }
}
