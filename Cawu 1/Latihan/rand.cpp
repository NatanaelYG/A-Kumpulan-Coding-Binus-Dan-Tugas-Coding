#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
    srand(time(NULL));
    int angka;

    for(int i = 0;i < 1000000000000000;i++){
    angka = rand() %100000000000000;
        printf("%d\n",angka);
    }
}