#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int input[],int low, int high){
    int pivot = input[high];
    int i = low;

    for (int j=low;j<high;j++){
        if(input[j]<=pivot){
            swap(&input[i],&input[j]);
            i++;
        }
    }
    swap(&input[high],&input[i]);
    return (i);
}

void quicksort(int input[],int low, int high){
    if(low<high){
        int pi = partition(input,low,high);

        quicksort(input,low,pi-1);
        quicksort(input,pi+1,high);
    }
}

int main(){
    int i,j,k,l;
    int n,input[100005],temp;

    scanf("%d",&n); getchar();
    for(i = 0; i < n; i++){
        scanf("%d", &input[i]);
    }

        // for(i = 0; i < n - 1; i++){
        //     for(j = 0; j < n - i - 1; j++){
        //         if(input[j] > input[j+1]){
        //         temp = input[j];
        //         input[j] = input[j+1];
        //         input[j+1] = temp;
        //         }
        //     }
        // }

    quicksort(input,0,n-1);

    for(i = n/2+1; i < n; i++){
        printf("%d ",input[i]);
    }
    printf("\n");
}