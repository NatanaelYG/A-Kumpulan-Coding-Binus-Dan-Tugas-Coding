#include <stdio.h>
#include <string.h>

int main(){
    char input[100005];
    int news[100005], idx = 0;

    scanf("%[^\n]", input); getchar();
    int len = strlen(input);

    for(int i = 0;i < len;i++){
        news[idx] = input[i];
        int j = i;
        while(input[j] == news[idx]){
            j++;
        } idx++;
        i = j-1;
    }
    for(int i = 0;i < idx;i++){
        printf("%c", news[i]);
    }
}