#include <stdio.h> 

void reverse(char *input);

int main() {
    int n,i,j,panjang;
    char input[1005];

    scanf("%d",&n); getchar();
    for(i = 1;i <= n;i++){
        scanf("%[^\n]", input); getchar();
        printf("Case #%d: ",i);
        reverse(input);
        printf("\n");
    }
    return 0;
}

void reverse(char *input){
    if(*input){
        reverse(input+1);
        printf("%c", *input);
    }
}