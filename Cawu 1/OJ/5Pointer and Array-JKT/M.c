#include <stdio.h>

int main()
{
	int i,j,k,l;
	int t,n;
	int m[505][505];
	int z;
	
	scanf("%d", &t);
	for(i = 1;i <= t;i++){
		scanf("%d", &n);
		for(j = 0;j < n;j++){
			for(k = 0;k < n;k++){
				scanf("%d", &m[j][k]);
			}
		}
		printf("Case #%d: ", i);
		for(j = 0;j < n;j++){
			z = 0;
			for(k=0;k<n;k++){
				z += m[k][j];
			}
			printf("%d", z);
			if (j == n-1){
			printf("\n");
		} else {
			printf(" ");
		}
		}
	}
	
	return 0;
}
