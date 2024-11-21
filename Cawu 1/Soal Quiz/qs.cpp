#include <stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void qsortINT(int arr[], int low, int high)
{
	if(low < high)
	{
		int pivot = arr[high];
		int i = low;
		
		for(int j = low; j < high; j++)
		{
			if(arr[j] <= pivot)
			{
				swap(&arr[i], &arr[j]);
				i++;
			}
		}
		swap(&arr[i], &arr[high]);
		int pivotIndex = i;
		qsort(arr,low,pivotIndex-1);
		qsort(arr,pivotIndex+1,high);
	}
	
}

int main(){
    int arr[100];
    int n;

    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        scanf("%d", arr[i]);
    }

    qsortINT(arr,0,n);
    for(int i = 0;i < n;i++){
        printf("%d", arr[i]);
    }

    
}