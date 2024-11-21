#include <stdio.h>

int asd(int n);

int main(){
    int n;

    scanf("%d",&n);
    printf("%d\n",asd(n));
}

int asd(int n){
    if (n == 0){
        return 0;
    } else if(n % 2 == 1){
        return 1;
    } else {
        return asd(n-1) + asd(n-2);
    }
    
}