#include <stdio.h>

int main(){
	int t,i,j,k,l,m,n,o;
	int a,b,c,d,e,f;
	
	scanf("%d", &t);
	for(i = 1;i <= t;i++){
		scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f); getchar();
		printf("Case #%d: ",i);
		for (j = 0;j < a;j++){
			printf("a");
		}
		for (k = 0;k < b;k++){
			printf("s");
		}
		for (l = 0;l < c;l++){
			printf("h");
		}
		for (m = 0;m < d;m++){
			printf("i");
		}
		for (n = 0;n < e;n++){
			printf("a");
		}
		for (o = 0;o < f;o++){
			printf("p");
		}
		printf("\n");
	}
}
