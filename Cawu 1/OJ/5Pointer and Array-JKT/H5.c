#include <stdio.h>

int main()
{
	int i,j,k,l,m;
	int t,n;
	long long int x[101][101];
	long long int z[100];
		
	scanf("%d", &t);
	for (i = 1;i <= t;i++){
		scanf("%d", &n);
		for(j = 1;j <= n;j++){
			for(k = 1;k <= n;k++){
				scanf("%lld", &x[j][k]);
			}
		}
		printf("Case #%d: ",i);
		for(l = 1;l <= n;l++){
			for(m = 1;m <= n;m++){
			z[l] += x[m][l];
			}
			if (l == n){
				printf("%lld\n", z[l]);
			} else {
				printf("%lld ", z[l]);
			}
			z[l] = 0;
		}
	}	
}
