#include <stdio.h>
#include <string.h>

int main(){
    int t,angka,panjang;
    int i,j;

    scanf("%d",&t);
    for(i=0;i<t;i++){
    char input[1005];
        
        scanf("%s", &input); getchar();
        panjang = strlen(input);
        angka = 0;
        printf("Case %d: ",i+1);
        for(j=0;j<panjang;j++){
            // angka = input[j];
            if(j == panjang-1){
            printf("%d\n",input[j]);
            } else {
                printf("%d-",input[j]);
            }
        }
    }
}