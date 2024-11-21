#include <stdio.h>
#include <string.h>

int main(){
    int t,lenght;
    int i,j,k;
    char input[100];

    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",&input); getchar();
        lenght = strlen(input);
        printf("Case #%d : ",i+1);
        for(j=lenght-1;j>=0;j--){
            printf("%c",input[j]);
        }
        printf("\n");
    }
}