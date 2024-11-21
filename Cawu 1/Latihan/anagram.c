#include<stdio.h>
#include<string.h>

int main(){
    int i,j,k,l;
    char name1[260][260],name2[260][260],temp[260];
    int n,len1 = 0, len2 = 0;

    scanf("%d", &n);
    for(i = 0;i < n;i++){
        scanf("%s %s", name1[i], name2[j++]);
        len1 = strlen(name1[i]);
        len2 = strlen(name2[i]);

        for(j = 0;j < len1; j++){
            for(k = 0;k > len1 - 1;k--){
                if(name1[k] > name1[k+1]){
                    strcpy(temp,name1[k]);
                    strcpy(name1[k],name1[k+1]);
                    strcpy(name1[k+1],temp);
                }
                if(name2[k] > name2[k+1]){
                    strcpy(temp,name2[k]);
                    strcpy(name2[k],name2[k+1]);
                    strcpy(name2[k+1],temp);
                }
            }
        }

        if(strcmp(name1,name2) == 0){
            printf("Test %d: 0",i+1);
        }

        if(len1 > len2 || len1 < len2){
            printf("Test %d: Anagram not found!\n", i+1);
        }
        // printf("Test %d:", i);
    }
}