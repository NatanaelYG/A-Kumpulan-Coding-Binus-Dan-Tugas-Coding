#include <stdio.h>

int result(int angka);

int main(){
    int t,n,angka;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&angka);
        printf("Case #%d: %d\n", i+1, result(angka));
    }
    return 0;
}

int result(int angka){
    if (angka <= 1){
        return angka;
    }
    else if (angka % 2 == 0){
        return result(angka/2);
    } else {
        return result(angka-1) + result(angka+1);
    }
}
