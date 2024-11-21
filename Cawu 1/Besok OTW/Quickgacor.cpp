#include <stdio.h>

void qs(int* num,int low,int high){
    int i = low;
    int j = high;
    int pivot = num[i];

    while(i <= j){
        while(num[i] < pivot)i++;
        while(num[j] > pivot)j--;

        if(i <= j){
            int hold = num[i];
            num[i] = num[j];
            num[j] = hold;
            i++;
            j--;
        }
    }
    if(low < j) qs(num, low, j);
    if(i < high) qs(num, i, high);
}

int main(){
    int t;
    int num[100];

    scanf("%d", &t);
    for(int i = 0;i < t;i++){
        scanf("%d", &num[i]);
    }

    qs(num, 0, t-1);

    for(int i = 0;i < t;i++){
        printf("%d ", num[i]);
    }
}