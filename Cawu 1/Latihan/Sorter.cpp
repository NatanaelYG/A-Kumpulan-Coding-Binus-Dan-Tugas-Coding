#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	
	bool isNull = true;

void swap(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int part(int arr[],int low, int high){
	int pivot = arr[high];
	int i = low;
	
	for(int j = low; j < high;j++){
		if(arr[j]<=pivot){
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	swap(&arr[high],&arr[i]);
	return i;
}

void quick(int arr[],int low, int high){
	if(low<high){
		int pi = part(arr,low,high);
		quick(arr,low,pi-1);
		quick(arr,pi+1,high);
	}
}

void printfrandom(int arr[]){
	for(int i = 0;i < 10;i++){
		printf("%d ", arr[i]);
	}
}
	
void randomnumber(int arr[]){
	isNull = false;
	srand(time(NULL));
	
	
	for(int i = 0;i < 10;i++){
	int random = rand() % 101;
		arr[i] = random;
	}
}

void printsort(int arr[]){
	quick(arr,0,10);
	for(int i = 0;i < 10;i++){
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}


void mergepart(int arr[],int left,int right,int mid){
	int leftsize = mid - left+1;
	int rightsize = right - mid;
	
	int leftarr[leftsize];
	int rightarr[rightsize];
	
	for(int i = 0; i < leftsize;i++){
		leftarr[i] = arr[i+left];
	}
	for(int i = 0;i < rightsize;i++){
		rightarr[i] = arr[i+mid+1];
	}
	
	int leftidx = 0;
	int rightidx = 0;
	int start = left;
	
	while(leftidx < leftsize && rightidx < rightsize){
		if(leftarr[leftidx] <= rightarr[rightidx]){
			arr[start] = leftarr[leftidx];
			leftidx++;
		} else {
			arr[start] = rightarr[rightidx];
			rightidx++;
		}
		start++;
	}
	while(leftidx < leftsize){
		arr[start] = leftarr[leftidx];
		leftidx++;
		start++;
	}
	while(rightidx < rightsize){
		arr[start] = rightarr[rightidx];
		rightidx++;
		start++; 
	}
}

void merge(int arr[],int left, int right){
	while(left < right){
		int mid = left+(right - left)/2;
		merge(arr,left,mid);
		merge(arr,mid+1,right);
		mergepart(arr,left,right,mid);
		return;
	}
}

void hapuslayar(){
	int i;
	for(i = 0;i < 25;i++){
		printf("\n");
	}
}

void mainMenu(){
	int menu = -9;
	int arr[10] = {0};
	
	do{
		hapuslayar();
    	printf("Sequence: ");
    	if(isNull == false){
    		printfrandom(arr);
		} else {
			printf("[null]");
		}
		printf("\n\n");
		
        printf("Sorter\n");
        printf("======\n");
        printf("1. Randomize number in array\n");
        printf("2. Merge sort\n");
        printf("3. Quick sort\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &menu); getchar();
        
        switch (menu){
        	case 1:
        		randomnumber(arr);
        		break;
        	case 2: 
        		printf("\n");
        		merge(arr,0,10);
        		break;
        	case 3:
        		printf("\n");
        		printsort(arr);
        		break;
		}
	} while(menu != 4);
}

int main(){
	
    	mainMenu();
        
    return 0;
}
