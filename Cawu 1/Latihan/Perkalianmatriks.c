#include <stdio.h>

int main(){
    int m,n,o,p;
    int a[15][15],b[15][15],c[15][15];
    int i,j,k,l,tc,ntc;
    int maxbaris= 0,maxkolom = 0;

    scanf("%d", &ntc);
    for(tc = 1; tc <= ntc; tc++){
        for(i = 0; i < 15;i++){
            for(j = 0;j < 15;j++){
                a[i][j] = b[i][j] = c[i][j] = 0;
            }
        }
    }
    scanf("%d %d %d %d", &m ,&n ,&o ,&p);

    
    if(n != o) printf("Perkalian tidak dapat dilakukan\n");
    else {
        for(i = 0;i < m;i++){
            for(j = 0;j < n;j++){
                scanf("%d", &a[i][j]);
            }
        }
        for(i = 0;i < m;i++){
            for(j = 0;j < n;j++){
                scanf("%d", &b[i][j]);
            }
        }
        printf("Perkalian Matrix\n");

        for(i = 0;i < m;i++){
            for(j = 0;j < n;j++){
                printf("%d ", a[i][j]);
            }

            if(i == m/2) printf("  X   ");
            else printf("      ");
            for(j = 0;j < n;j++){
                printf("%d ", b[i][j]);
            }
            printf("\n");
        }

        for(i = 0;i < m;i++){
            for(j = 0;j < p;j++){
                for(l = 0; l < o;l++){
                    c[i][j] = a[i][j]*b[i][j];
                }
            }
        }

        printf("\nHasil Matrix\n\n");
        for(i = 0;i < m;i++){
            printf(" ");
            for(j = 0;j < p;j++){
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    printf("\n");
    }
    return 0;
}