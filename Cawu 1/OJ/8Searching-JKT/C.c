#include <stdio.h>

int main(){
    int t,n;
    int i,j,l;
    int angka[1005], search,max = 0;
    int flag = 0;

    scanf("%d %d", &t, &n); 
    for(i = 0;i < t;i++){
        scanf("%d", &angka[i]);
    }

    for(j = 0;j < n;j++){
        scanf("%d",&search);
        for(i = 0;i < t;i++){
            if(angka[i] == search){
                angka[i] = 0;
            }
        }
    }

    for(i = 0;i < t;i++){
        // printf("%d",angka[i]);
        if (angka[i] > max){
            max = angka[i];
            flag = 1;
        }
            // printf("Max %d\n", max);
    }
    
    if(flag == 1){
        printf("Maximum number is %d\n", max);
    } else if(flag == 0){
        printf("Maximum number is -1\n");
    }
        // if(angka[i] == search[i] || angka[i+1] == search[i+1]){
        // }

}