#include<stdio.h>

int main(){
    int size, searchFreq, max = 0;
    int value[101], frequency[10001] = {0};
    int save[101], saved = 0, find;
    long long int sum = 0;
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        scanf("%d", &value[i]);
        frequency[value[i]]++;
    }
    scanf("%d", &searchFreq);
    int cek, count = 0;
    for(int i = 0; i < size; i++){
        printf("%d %d\n", value[i], frequency[value[i]]);
        if(frequency[value[i]] == searchFreq){
            sum += value[i];
            count++;
            // printf(" Masuk\n");
            // cek = 1;
            // for(int j = 0; j < saved; j++){
            //     if(value[i] == save[j]){
            //         cek = 0;
            //     }
            // }
            // if(cek){
            //     sum += value[i];
            //     saved++;
            // }
        }
    }
    // if(sum != 0) find = sum/saved;
    if(sum != 0) find = sum/count;
    cek = 0;
    // printf("%d\n", find);
    for(int i = 0; i < size; i++){
        if(value[i] == find){
            printf("%d\n", i+1);
            cek = 1;
            break;
        }
    }
    if(!cek) printf("N/A\n");
    return 0;
}