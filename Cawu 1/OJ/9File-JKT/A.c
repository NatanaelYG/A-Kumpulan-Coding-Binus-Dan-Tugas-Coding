#include <stdio.h>
#include <string.h>

int main(){
    int t,n,i,j,k,l,flag;
    char nama[105][105],nama2[105][105],search[105];

    FILE *file = fopen("testdata.in","r");

    fscanf(file,"%d\n", &t);
    // printf("%d\n", t);
    for(i = 1;i <= t;i++){
        fscanf(file,"%[^#]#%[^\n]\n", nama[i],nama2[i]);
        // printf("%s %s\n", nama[i],nama2[i]);
    }
    fscanf(file,"%d\n", &n);
    // printf("%d\n", n);
    for(j = 1;j <= n;j++){
        fscanf(file,"%[^\n]\n", search);
        // printf("%s\n", search);
        // printf("Case #%d: ",j);
        flag = 0;
        for(i = 1;i <= t;i++){
            if(strcmp(search,nama[i]) == 0){
                printf("Case #%d: %s\n", j,nama2[i]);
                flag = 1;
            }
        }
            if(flag == 0){
                printf("Case #%d: N/A\n", j);
            }
    }


    fclose(file);
}