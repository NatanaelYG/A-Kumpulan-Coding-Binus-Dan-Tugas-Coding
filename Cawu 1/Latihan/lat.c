#include <stdio.h>
#include <string.h>

int main(){
    int i,j,k,l,counter = 0;
    char input[1000];
    int alpha[27] = {};

    scanf("%s", input);
    int len = strlen(input);
    for(i = 0;i < len;i++){
        alpha[input[i] - 'a']++;
    }

    for(i = 0;i < 26;i++){
        if(alpha[i] != 0){
            counter++;
        }
    }

    for(i = 0;i < 26;i++){
        
    }
    printf("%d", counter);
}