#include <stdio.h>

int asd(int num1, int num2, int k){
    if (k == 0 ) {
        return num1;;
    } else if (k == 1){
        return num2;
    } else {
        return asd(num1, num2, k-1) + asd(num1, num2,k-2);
    }
}

int main(){
    int num1,num2,k;

    scanf("%d %d",&num1,&num2);
    scanf("%d", &k);
    printf("%d\n", asd(num1,num2,k));
}