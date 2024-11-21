#include <stdio.h>
#include <ctype.h>

int main(){
    char in[20000];
    char hur[20000];
    int i,j;

    scanf("%[^\n]", in);

    // int len = strlen(in);

    for(i = 0;in[i] !=  '\0';i++){
            if(in[i] >= 'A' && in[i] <= 'Z'){
                hur[i] = (in[i] - 'A') + 'a' ;
            }
        printf("%c", hur[i]);
    }

}