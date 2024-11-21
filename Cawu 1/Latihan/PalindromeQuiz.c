#include <stdio.h>
#include <string.h>

int main(){
    char input[1005];
    int len = strlen(input), count = 0;
    int l = 0, r = len;

    scanf("%s", input);
    // for(int i = 0;i < len;i++){
        while(r > l){
            if(input[l++] == input[r--]){
                count++;
            }
        }
    // }
    printf("%d", count);

}