#include <stdio.h>

int main(){
    int t,i,j;
    int put[100];
    int n;

    scanf("%d", &t);
    for(i = 0;i < t;i++){
        scanf("%d", &put[i]);
    }
    scanf("%d", &n);

    int sama = 0;
    for(i = 0;i < t;i++){
        if(put[i] == put[i+1] || put[i] == put[i+2]){
            sama += put[i];
            printf("%d", sama);
        }
    }
}