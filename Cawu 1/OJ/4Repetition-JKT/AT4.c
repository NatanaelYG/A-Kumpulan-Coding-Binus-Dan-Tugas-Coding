#include <stdio.h>

int main(){
	int n,m,i,j,k,l;
	
	scanf("%d", &n);
	for (i = 1; i <= n;i++){
		scanf("%d", &m);
		for (j = 1;j <= m;j++){
			for (k = m;k > j;k--){
				printf(" ");
			}
			for (l = 1; l <= j*2-1;l++){
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
