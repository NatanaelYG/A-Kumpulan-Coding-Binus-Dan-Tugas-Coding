#include <stdio.h>
#include <string.h>

int main(){

    FILE *file = fopen("testdata.in","r");

    char nama[100][1000], title[100][1000];
    int i,j,k,l,n,count=0,view[100], temps;
    char temp[100];

    while(fscanf(file,"%[^#]#%[^#]#%d\n", title[count], nama[count], &view[count]) != EOF){
        // printf("%d\n",count);
        count++;
    }

    for (i = 0; i < count-1;i++){
        for (j = 0; j < count - i-1; j++){
            if (view[j]< view[j+1]){
                strcpy(temp,title[j]);
                strcpy(title[j],title[j+1]);
                strcpy(title[j+1],temp);

                strcpy(temp,nama[j]);
                strcpy(nama[j],nama[j+1]);
                strcpy(nama[j+1],temp);

                temps = view[j];
                view[j] = view[j+1];
                view[j+1] = temps;
            }
        }
    }

    for(i = 0; i < count; i++){
        printf("%s by %s - %s\n",title[i],nama[i],view[i]);
    }

    fclose(file);
}