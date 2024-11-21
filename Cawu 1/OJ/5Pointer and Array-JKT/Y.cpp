#include <stdio.h>

int main(){
    int t,n,index,angka;
    char input[1000];
    int i,j,k,l;

    scanf("%d",&t);
    for(i = 1;i <= t;i++){
        scanf("%d %s",&n, input);
        for(j = 1;j <= n;j++){
            scanf("%d %d", &index, &angka);
            index-=1;
            angka-=1;  
            while(index<=angka){
                int temp = input[index];
                input[index] = input[angka];
                input[angka] = temp;
                index++;
                angka--;
            }
        }
        printf("Case #%d: %s\n",i,input);
    }
}