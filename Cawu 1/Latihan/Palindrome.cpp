#include <stdio.h>
#include <string.h>

int main(){
    char input[1000];
    int i,j,k,l,n,pan, flag=1;

    // FILE *file = fopen("Data.in","r");

    scanf("%d", &n);
    for(i = 0;i < n;i++){
        flag = 1;
        scanf("%s", input);

        pan = strlen(input);
        k = pan - 1;
        for(j = 0;j < pan/2; j++,k--){
            while(input[i] == ' ' || input[i] == ',')i++;
            while(input[j] == ' ' || input[j] == ',')j--;
            if(input[j] != input[k]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            printf("Case #%d: Is Palindrome\n",i+1);
        } else {
            printf("Case #%d: Is Not Palindrome\n",i+1);
        }
    }

    // fclose(file);
}