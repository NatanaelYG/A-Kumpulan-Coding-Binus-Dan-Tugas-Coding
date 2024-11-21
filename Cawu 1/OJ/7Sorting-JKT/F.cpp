#include <stdio.h>
#include <string.h>

int main(){
    int t;
    int i,j,k,l;
    char nama[1005][1005],temp[1005];
    int angka[1005],temps;

    // FILE *file = fopen("testdata.in","r");

    // fscanf(file,"%d\n",&t);

    scanf("%d\n",&t);
    for(i = 0; i < t; i++){
        // fscanf(file,"%s %d\n",nama[i], &angka[i]);
        scanf("%s %d",nama[i], &angka[i]);
    }

    for(j = 0; j < t - 1; j++){
        for(k = 0; k < t - j - 1; k++){
            if(angka[k] > angka[k+1]){
                temps = angka[k];
                angka[k] = angka[k+1];
                angka[k+1] = temps;
                
                strcpy(temp,nama[k]);
                strcpy(nama[k],nama[k+1]);
                strcpy(nama[k+1],temp);

            } else if (angka[k] == angka[k+1] && strcmp(nama[k],nama[k+1])>0){
                strcpy(temp,nama[k]);
                strcpy(nama[k],nama[k+1]);
                strcpy(nama[k+1],temp);

                temps = angka[k];
                angka[k] = angka[k+1];
                angka[k+1], temps;
            }
        }
    }

    for(i = 0; i < t;i++){
        printf("%s\n",nama[i]);
    }

    // fclose(file);
}