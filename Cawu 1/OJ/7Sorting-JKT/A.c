#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int input[],int low,int high){
    int pivot = input[high];
    int i = low;

    for(int j = low; j < high;j++){
        if(input[j] <= pivot){
            swap(&input[i],&input[j]);
            i++;
        }
    }
    swap(&input[high],&input[i]);
    return i;
}

void qs(int input[],int low,int high){
    if(low<high){
        int pi = partition(input, low, high);
        qs(input,low,pi-1);
        qs(input,pi+1,high);
    }
}

int main(){
    int i,j,k,l;
    int n,input[100005],selisih, max = 0;

    scanf("%d",&n); getchar();
    for(i = 0; i < n; i++){
        scanf("%d", &input[i]); 
    }

    qs(input,0,n-1);
    
//	for(i = 0; i < n; i++){
//        printf("%lld\n", input[i]); 
//    }
    
    for(i = 0;i < n-1;i++){
        selisih = abs(input[i]-input[i+1]); 
        if (selisih > max){
            max = selisih;
        }
    }
    int cek = 0;
    for (i = 0;i < n-1;i++){
    	if(abs(input[i]-input[i+1]) == max){
    		if(cek == 1){
    			printf(" ");
			} 
    			printf("%d %d",input[i],input[i+1]);
    			cek = 1;
		}
	}
	printf("\n");
	return 0;
}
