#include <stdio.h>
#include <stdbool.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i = 1; i<=t; i++){
        int len;
        scanf("%d",&len);
        int counter = 0,arr[len];
        for(int j = 0; j<len ; j++){    
            scanf("%d",&arr[j]);
        }
        for(int j = 0; j<len; j++){
            int sum = arr[j];
            bool valid = false;
            for(int k = 0; k<len ; k++){
                for(int l = 0 ; l<len ; l++){
                    if(arr[k]+arr[l]==sum && arr[l] != sum && k != l && arr[k] != sum){
                        valid=true;
                        break;
                    }
                }
            }
            if(valid){
                counter++;
            };
        }
        printf("Case #%d: %d\n",i,counter);
    }
return 0;
}