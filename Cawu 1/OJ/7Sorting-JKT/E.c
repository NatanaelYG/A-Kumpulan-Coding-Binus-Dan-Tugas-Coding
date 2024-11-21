#include <stdio.h>
#include <string.h>

int main(){
    char nama[105][1005], suhu[250],temp[1005];
    double angka[1000],temps;
    int count = 0,i,j,k;

    FILE *file = fopen("testdata.in","r");

    while(fscanf(file,"%[^#]#%lf#%c\n", nama[count], &angka[count], &suhu[count]) != EOF){
        if(suhu[count] == 'F'){
            angka[count] = (angka[count] -32) * 5.0/9.0;
        }
        count++;
    }

    for(i = 0; i < count - 1; i++){
        for(j = 0; j < count - i - 1; j++){
            if(angka[j] > angka[j+1]){
                strcpy(temp,nama[j]);
                strcpy(nama[j],nama[j+1]);
                strcpy(nama[j+1],temp);

                temps = angka[j];
                angka[j] = angka[j+1];
                angka[j+1] = temps;

                temp[j] = suhu[j];
                suhu[j] = suhu[j+1];
                suhu[j+1] = temp[j];
            } else if (angka[j] == angka[j+1] && nama[j] < nama[j+1]){
                strcpy(temp,nama[j]);
                strcpy(nama[j],nama[j+1]);
                strcpy(nama[j+1],temp);

                temps = angka[j];
                angka[j] = angka[j+1];
                angka[j+1] = temps;

                temp[j] = suhu[j];
                suhu[j] = suhu[j+1];
                suhu[j+1] = temp[j];
            }
        }
    }

    for(i = 0; i < count;i++){
        if(suhu[i] == 'F'){
            angka[i] = (angka[i] * 9.0/5.0) + 32;
        }
        printf("%s is %.2lf%c\n", nama[i], angka[i], suhu[i]);
    }

    fclose(file);
}