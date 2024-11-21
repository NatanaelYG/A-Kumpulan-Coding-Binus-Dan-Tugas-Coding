#include <stdio.h>

int main(){
    int n,i,j,a;

    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&a);
        if(a == 1){
            printf("not easy\n");
            break;
        } else if(a != 1 && i == n-1){
            printf("easy\n");
        }
    }
        return 0;
}