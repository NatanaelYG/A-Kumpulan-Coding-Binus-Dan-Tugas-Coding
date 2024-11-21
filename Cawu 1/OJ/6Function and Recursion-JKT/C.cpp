#include <stdio.h>

int asd(int m,int n);

int main(){
    int m,n,hasil;
    scanf("%d %d",&m, &n);
    hasil = asd(m,n);
    printf("result: %d\n", hasil);
    return 0;
}

int asd(int m,int n){
    // if(m < 0){
    //     return 0;
    if(m == 0){
        return n+1;
    } else if (m > 0 && n == 0){
        return asd (m-1,1);
    } else if (m > 0 && n > 0){
        return asd (m-1,asd(m,n-1));
    }
    
}
