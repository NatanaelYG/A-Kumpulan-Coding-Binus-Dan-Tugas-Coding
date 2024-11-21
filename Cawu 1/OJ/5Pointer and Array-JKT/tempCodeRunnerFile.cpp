#include <stdio.h>

int tillone(int n);

int main(){
    int t,i,angka, hasil;

    scanf("%d",&t);
    for(i = 1;i <= t;i++){
        scanf("%d",&angka);
        hasil = tillone(angka);
        printf("%d\n",hasil);
    }
    return 0;
}

int tillone(int n){
    if(n % 2 == 0){
        return (n - 1)+(n + 1);
    } else {
        return (n/2);
    }
}