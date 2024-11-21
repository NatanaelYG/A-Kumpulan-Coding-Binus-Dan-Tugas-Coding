#include <stdio.h>

int main(){
    int t,i,j;
    int put[100] = {0};
    int n;
    scanf("%d", &t);
    for(i = 1;i <= t;i++) scanf("%d", &put[i]);
    scanf("%d", &n);
    int max=-1, total, save;
    for(i = 1;i <= t;i++){
        total = 0;
        for(j = 0; j < n; j++){
        total+=put[j+i]; 
        printf("total : %d\n", total);
        }
        if(total > max){
            max = total;
            save = i;
        }
    }
    for(i = 0;i < n;i++) printf("%d ", save+i);
}