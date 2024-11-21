#include <stdio.h>

int main(){
	int i,j,k;
	int T,N;
	long long int a,total;
	
	scanf("%d", &T);
	for(i = 1;i <= T;i++){
		scanf("%d", &N);
		total = 0;
		for(j = 1;j <= N;j++){
			scanf("%lld", &a);
					total += a;
		}

		printf("Case #%d: %lld\n",i, total);
	}
}
