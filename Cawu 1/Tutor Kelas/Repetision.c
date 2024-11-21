#include <stdio.h>

int main(){
	/*
		for([initialization];[condition];[increment/decrement]){
		
	*/
	
//	for(;;){
//		printf("^-^-_-^~^");
//	}

//	int c,i,j;
//	for (i=0, j=strlen(ss)-1; i<j; i++, j--){
//		c=ss[i];
//		ss[i]=ss[j];
//		ss[j]=c;
//		printf()
//	}

int n,i,j,k,l,m;
//	for (i= 1; i<=5;i++){
//		for(j = 1;j <= 10;j++){
//			if ( j < 10){
//				printf("%d", j);
//			} else {
//				printf("%d\n", j);
// 		j == 10 ? printf("\n") : printf(" ");
//			}
//		}
//	}
//	scanf("%d", &n);
//	for (i = 1;i<= n;i++){
//		for(j = 1; j <= i;j++){
//			printf("%d ", j);
//		}
//		printf("\n");
//	}
//	
//	printf("\n\n");
//	for (i = 1;i <= n;i++){
//		for(j = n; j >= i;j--){
//			printf("%d ", j);
//		}
//		printf("\n");
//	}
//	
//	for(i = 1;i <= n;i++){
//		for (j = 1; j <= i; j++){
//			printf(" ");
//		}
//		for (k = n;k >= i;k--){
//			printf("%d ", k);
//		}
//		printf("\n");
//	}
	scanf("%d", &n);
	for (i = 1;i <=n;i++){
		if (i%7==0){
			printf("%d ", 7);
		} else {
			printf("%d ", i%7);
		}
	}
	return 0;
}
