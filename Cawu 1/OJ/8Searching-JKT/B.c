#include <stdio.h>
#include <string.h>

int main(){
    int i,j,k,l;
    int t,n;
    int angka,nim[100];
    char nama[100][100];

    FILE *file = fopen("testdata.in","r");

    fscanf(file,"%d", &t); 
    // printf("%d\n", t);
    for(i = 1;i <= t;i++){
        fscanf(file,"%d %[^\n]\n", &nim[i],nama[i]);
        // printf("%d %s\n", nim[i],nama[i]);
    }
    
    fscanf(file,"%d\n", &n);
    // printf("%d\n", n);
    for(j = 1; j <= n;j++){
        fscanf(file,"%d\n", &angka);
        // printf("%d\n", angka);
        for(k = 1; k <= t; k++){
            if (nim[k] == angka){
                printf("Case #%d: %s\n",j,nama[k]);
                break;
            } else if(nim[k]!= angka && k == t){
                printf("Case #%d: N/A\n", j);
            }
        }
    }
}