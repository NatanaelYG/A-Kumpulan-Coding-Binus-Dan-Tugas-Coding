#include <stdio.h>
#include <string.h>

int main(){
    char input[100001];
    int i,j,sama,beda,n;

    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%s", input);
        beda = 0;
        for(j = 0; j < strlen(input); j++){
            if(input[j] != input[j+1]){
                beda++;
            } else {
            }
        }
        if(beda > 2){
            printf("Case #%d: Ewwww\n", i);
        } else if(beda <= 2){
            printf("Case #%d: Yay\n", i);
        }
    }
    return 0;
}