#include <stdio.h>

void asd(int n, char huruf1,char huruf2){
    if (n == 0){
        printf("%c", huruf1);
    } else if (n == 1){
        printf("%c", huruf2);
    } else {
        asd(n-1,huruf1,huruf2);asd(n-2,huruf1,huruf2);
    }
}

int main(){
    int t,n,i,j;
    char huruf1, huruf2;
    
    scanf("%d",&t);
    for (i = 1;i <= t;i++){
        scanf("%d %c %c", &n, &huruf1, &huruf2);
        printf("Case #%d: ", i);
        asd(n,huruf1,huruf2);
        printf("\n");
    }
    return 0;
}