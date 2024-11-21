#include <stdio.h>

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int part(int a[],int low, int high){
	int pivot = a[high];
	int i = low;
	
	for(int j = low;j < high;j++){
		if(a[j] <= pivot){
		swap(&a[i],&a[j]);
		i++;	
		}
	}
	swap(&a[high],&a[i]);
	return i;
}

void quick(int a[],int low,int high){
	if(low < high){
		int pi = part(a,low,high);
		quick(a,low,pi-1);
		quick(a,pi+1,high);
		
	}
}

int main(){
    int n,a[100005],q,x;
    int i,j,k,l,save[200005] = {0};

    scanf("%d", &n);
    for(i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }

    quick(a,1,n);
    
    for(k = 1;k <= n;k++){
//    	printf("%d ", a[k]);
    	save[a[k]] = k;
	}

    scanf("%d", &q);
    for(j = 1;j <= q;j++){
        scanf("%d", &x);
        if(save[x] == 0){
        	printf("-1\n");
		} else {
        	printf("%d\n", save[x]);
		}
    }
    return 0;
}
