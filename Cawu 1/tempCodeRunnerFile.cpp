#include <stdio.h>

int search(int input[],int t,int key){
    for(int i = 0;i < t;i++){
        if(input[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int input[100];
    int t,key;

    scanf("%d", &t);
    for(int i = 0;i < t;i++){
        scanf("%d", &input[i]);
    }
    scanf("%d", &key);

    int result = search(input, t, key);
    (result == -1) ? printf("Tidak Ada") : printf("Ada di index %d", result);
}