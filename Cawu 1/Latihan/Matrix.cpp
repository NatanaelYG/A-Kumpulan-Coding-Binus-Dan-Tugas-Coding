#include <stdio.h>

int main(){
    int angka[100][100];
    int n,m,o,p;
    int i,j,k,l;

    scanf("%d %d %d %d", &n,&m,&o,&p);
    if(n != o) printf("Tidak dapat dilakukan\n");
    else {
        for(i = 1;i <= n;i++){
            for(j = 1;j <= m;j++){
                scanf("%d", &angka);
            }
        }
        for(i = 1;i <= n;i++){
            for(j = 1;j <= m;j++){
                printf("%d", angka[i][j]);
            }
            printf("\n");
        }
    }
}