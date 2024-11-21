#include <stdio.h>
#include <string.h>

int main(){
    char input[1000];
    int i,j,sama,beda,n;

    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%s", input);
        beda = 0;
        for(j = 0; j < strlen(input); j++){
            if(strcmp(input,input+1) == 1){
                beda++;
                
            } else {
                continue;
            }
        }printf("%d",beda);
        if(beda > 2){
            printf("Case #%d: Ewwww\n", i);
        } else {
            printf("Case #%d: Yay\n", i);
        }
    }
}