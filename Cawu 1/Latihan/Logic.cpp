#include <stdio.h>
#include <string.h>

int main(){
    char input[1000];
    int i,j,k,l,n,pan;

    FILE *file = fopen("Data.in","r");

    fscanf(file,"%d\n", &n);
    for(i = 1;i <= n;i++){
        fscanf(file,"%[^\n]\n", input);

        pan = strlen(input);
        if(input[0] >= 'a' && input[0] <= 'z') input[0] = input[0] - 'a' + 'A';
        for(j = 1;j <= pan;j++){
            if(input[j] == ' '){
                j++;
                if(input[j] >= 'a' && input[j] <= 'z'){
                    input[j] = input[j] - 'a' + 'A';
                }
            }
        }

        printf("Case #%d: %s\n",i,input);
    }

    fclose(file);
    return 0;
}