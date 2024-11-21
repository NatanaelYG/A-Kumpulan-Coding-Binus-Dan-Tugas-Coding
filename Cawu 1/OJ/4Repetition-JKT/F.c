#include <stdio.h>

int main(){
	int n,m;
	int i,j,k;
	
	scanf("%d %d", &n, &m);
	for (i = 1;i <= n;i++){
		for (j = 1;j <= n;j++){
			printf("#");
		}
		printf("\n");
	} printf("\n");
	
	for (i = 1;i <= n;i++){
		for (j = 1;j <= n;j++){
			if (i % m == 0){
				printf("#");
			} else {
				printf(".");
			}
		}
		printf("\n");
	} printf("\n");
	
	for (i = 1;i <= n;i++){
		for (j = 1;j <= n;j++){
			if (j % m == 0){
				printf("#");
			} else {
				printf(".");
			}
		}
		printf("\n");
	}
	
}
