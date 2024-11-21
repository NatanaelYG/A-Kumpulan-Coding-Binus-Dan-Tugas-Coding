#include <stdio.h>

int asd(int n){
    if(n == 0){
        return 0;
    } else {
        return asd(n-1) + 1;
    }
}

int main(){
    int n;

    scanf("%d", &n);
    printf("%d", asd(n));

}