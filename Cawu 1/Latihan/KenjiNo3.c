#include <stdio.h>

int count = 0;

void asd(char huruf[]){
    if(huruf[count] == '\0') return;
    else {
        count++;
        asd(huruf);
    }
}

int main(){
    char huruf[1000];

    scanf("%s", huruf);
    asd(huruf);
    printf("%d", count);
}