#include <stdio.h>

int main(){
	int t,n;
	int i,j,k;
	int counterplus = 0;
	int countermin = n-1;
	
	scanf("%d", &t);
	for (k = 0;k < t;k++){
	scanf("%d", &n);
	if (n % 2 == 1){
		counterplus = 0;
		countermin = n-1;
		for (i = 1;i <= n;i++){
			for(j = 1;j <= n;j++){
				if (counterplus == j-1 || countermin == j-1){
					printf("*");
				}
			 else if ((i == 1 || i == n) || (j == 1 || j == n)){
					printf("*");
				} else {
					printf(" ");
				}
			}
			counterplus++;
			countermin--;
			printf("\n");
		}
		printf("\n");
	}
	}
		
	return 0;	
}
