#include <stdio.h>

int main(){
	int i,j;
	long long int T,N,M,harga;
	long long int total;
	
	
	scanf("%lld", &T);
	for(i = 1;i <= T;i++){
		scanf("%lld %lld",&N,&M);
		total = 0;
		for(j = 1;j <= N;j++){
			scanf("%lld", &harga);
			total += harga;
		}
		if (total == M){
			printf("Case #%d: No worries\n",i);
		} else if (total <= M){
			printf("Case #%d: No worries\n",i);
		} else {
			printf("Case #%d: Wash dishes\n",i);
		}
	}
}
