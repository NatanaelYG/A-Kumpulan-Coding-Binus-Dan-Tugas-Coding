#include <stdio.h>
#include <string.h>

int faktorial(int n);

int main(){

    int angka, hasil;

    scanf("%d",&angka);

    hasil = faktorial(angka);
    printf("%d\n",hasil);

    return 0;
}

int faktorial(int n){
    if (n <= 1){
        return n;
    } else {
        return n * faktorial(n - 1);
    }
}