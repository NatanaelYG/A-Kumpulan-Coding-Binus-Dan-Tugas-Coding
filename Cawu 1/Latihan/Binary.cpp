#include <stdio.h>

int main(){
    int num, index,bit[100];
    scanf("%d %d", &num, &index);
    for(int i=0; i<8; i++){
        bit[i] = (num >> index ) & 1;
        printf("%d ",bit[i]);
    }
}