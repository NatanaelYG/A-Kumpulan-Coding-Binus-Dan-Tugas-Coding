#include <stdio.h>
#include <string.h>

int main(){
    FILE *file = fopen("testdata.in","r");
    int t,i,j,k;
    char temp[1005];
    char angka[1005][100],nama[1005][100];

    fscanf(file,"%d\n",&t);
    for( i = 1; i <= t; i++){
        fscanf(file,"%[^#]#%[^\n]\n",angka[i], nama[i]);
    }

    for (j = 1; j <= t; j++){
        for( k = 1; k <= t - j; k++){
            if(strcmp(nama[k],nama[k+1]) > 0){
                strcpy(temp,nama[k]); 
                strcpy(nama[k],nama[k+1]);
                strcpy(nama[k+1],temp);

                strcpy(temp,angka[k]);
                strcpy(angka[k],angka[k+1]);
                strcpy(angka[k+1],temp);
            }
        }
    }

    for(i = 1; i <= t; i++){
        printf("%s %s\n",angka[i],nama[i]);
    }

    fclose(file);
}