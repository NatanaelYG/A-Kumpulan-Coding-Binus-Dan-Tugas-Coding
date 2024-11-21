#include <stdio.h>
#include <string.h>

int main(){

    FILE *file = fopen("testdata.in","r");

    char nama[105][1005], title[105][1005];
    int i,j,k,l,n,count=0, temps;
    long long int view[1000];
    char temp[1005];

    while(fscanf(file,"%[^#]#%[^#]#%lld\n", title[count], nama[count], &view[count]) != EOF){
        // printf("%d\n",count);
        count++;
    }

    for (i = 0; i < count-1;i++){
        for (j = 0; j < count - i-1; j++){
            if (view[j] < view[j+1]){
                strcpy(temp,title[j]);
                strcpy(title[j],title[j+1]);
                strcpy(title[j+1],temp);

                strcpy(temp,nama[j]);
                strcpy(nama[j],nama[j+1]);
                strcpy(nama[j+1],temp);

                temps = view[j];
                view[j] = view[j+1];
                view[j+1] = temps;
            } else if (view[j] == view[j+1] && strcmp(title[j],title[j+1]) == 0){
                strcpy(temp,title[j]);
                strcpy(title[j],title[j+1]);
                strcpy(title[j+1],temp);

                strcpy(temp,nama[j]);
                strcpy(nama[j],nama[j+1]);
                strcpy(nama[j+1],temp);

                temps = view[j];
                view[j] = view[j+1];
                view[j+1] = temps;
            } else if(nama[j] <= nama[j+1] && view[j] == view[j+1]){
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
        printf("%s by %s - %lld\n",title[i],nama[i],view[i]);
    }

    fclose(file);
}