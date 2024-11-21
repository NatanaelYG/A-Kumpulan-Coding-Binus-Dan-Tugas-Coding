#include <stdio.h>

int main(){
	int T;
	int i,j,k,l;
	int N;
	
	scanf("%d", &T);
	for (l = 1;l <= T;l++){
	scanf("%d", &N);
	printf("Case #%d:\n",l);
	for(i = 1;i <= N;i++){
		for(j = i;j < N;j++){
			printf(" ");
		}
		if (N % 2 == 1){
		for(k = 1;k <= i;k++){
			if(k % 2 == 0){
				printf("#");
			} else {
				printf("*");
			}
		}
		} else {
			for(k = 1;k <= i;k++){
			if(k % 2 == 0){
				printf("*");
			} else {
				printf("#");
			}
		}
		}
		
		printf("\n");
	}
	}
}

