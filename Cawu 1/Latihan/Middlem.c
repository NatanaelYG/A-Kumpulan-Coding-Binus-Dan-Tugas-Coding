#include <stdio.h>

int main(){
	int n,a[100][100];
	int i,j,k;
	
	scanf("%d", &n);
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(i = 0;i < n-2;i++){
		for(j = 0;j < n-2;j++){
			printf("%d ", a[i+1][j+1]);
		}
		printf("\n");
	}
	
}
