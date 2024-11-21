#include <stdio.h>

int main(){
	int i,j,k;
	int t,n;
	long long int fibo[101];
	
		fibo[1] = 0;
		fibo[2] = 1;
		for (j = 3;j <= n;j++){
			fibo[i] = fibo[i-1] + fibo[i-2];
		}
		
	scanf("%d", &t);getchar();
	for(i = 1;i <= t;i++){
		scanf("%d", &n); getchar;
		
		printf("Case #%d: %lld\n",i,fibo[n]);
	}
}

